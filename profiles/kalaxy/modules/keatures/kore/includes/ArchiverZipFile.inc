<?php

use \Drupal\ko\File;

class ArchiverZipFile extends ArchiverZip {

  protected $zip_file; // The Drupal managed file object
  protected $is_new; // Flag for new created zip, not a managed file yet

  public function __construct($zip_file) {
    // Ask to create one if pass in string, as uri, file_path.
    if (!is_numeric($zip_file) && !is_object($zip_file) && !empty($zip_file)) {
      $zip_file_uri = File::getUri($zip_file);
      $zip_file_path = drupal_realpath($zip_file_uri);
      // Zip file exists
      if (file_exists($zip_file)) {
        parent::__construct($zip_file_path);
        $this->zip_file = File::loadByUri($zip_file_uri);
      }
      // Create a new zip file for this
      else {
        // Need to prepare directory first
        $dir = dirname($zip_file_uri);
        file_prepare_directory($dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
        $zip_file_path = drupal_realpath($zip_file_uri);
        $this->zip = new ZipArchive();
        $this->zip->open($zip_file_path, ZipArchive::CREATE);
        $this->zip_file = File::prepareFile($zip_file_uri);
        $this->is_new = TRUE;
      }
    }
    // Pass in fid or file object.
    else {
      $zip_file = $this->fileLoad($zip_file);
      $this->zip_file = $zip_file;
      // Prepare a file if not exists, e.g. deleted by others
      if (!file_exists($zip_file->uri)) {
        $dir = dirname($zip_file->uri);
        file_prepare_directory($dir, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS);
        $zip_file_path = drupal_realpath($zip_file->uri);
        $this->zip = new ZipArchive();
        $this->zip->open($zip_file_path, ZipArchive::CREATE);
      }
      else {
        parent::__construct($this->filePath($zip_file));
      }
    }

    return $this;
  }

  /**
   * Wrapper for add().
   *
   * @param $file
   * @param $dir Local relative path in zip, '/' would be a folder with the same name, not root.
   */
  public function addFile($file, $dir = '') {
    $file = $this->fileLoad($file);
    $this->zip->addFile($this->filePath($file), $dir . $file->filename);
    return $this;
  }

  /**
   * Wrapper for remove().
   */
  public function removeFile($file, $dir = '') {
    $file = $this->fileLoad($file);
    $this->zip->deleteName($dir . $file->filename);
    return $this;
  }

  /**
   * Save the $zip_file.
   */
  public function save($reopen = FALSE) {
    $this->zip->close();
    if ($this->is_new) {
      $this->zip_file = file_save_data(file_get_contents($this->zip_file->uri), $this->zip_file->uri);
      // Saved, so it is not new anymore
      $this->is_new = FALSE;
    }
    else {
      $this->zip_file = file_save($this->zip_file);
    }

    // If needed to reopen?
    if ($reopen) {
      $this->zip->open($this->zip_file->uri);
    }

    return $this->zip_file;
  }

  /**
   * Delete the $zip_file.
   */
  public function delete() {
    $this->zip->close();
    return file_delete($this->zip_file);
  }

  /**
   * Get the $zip_file.
   */
  public function getZipFile() {
    return $this->zip_file;
  }

  /**
   * Helper function to load the file object.
   *
   * @todo Support uri input.
   */
  public function fileLoad($file) {
    if (is_numeric($file)) {
      $file = file_load($file);
    }
    return $file;
  }

  /**
   * Helper function to get the realpath from a file object.
   *
   * @param $file
   * @return false|string
   */
  public function filePath($file) {
    $file = $this->fileLoad($file);
    return drupal_realpath($file->uri);
  }

  /**
   * Delete all zip archive entries.
   */
  public function removeAll() {
    for ($i = 0; $i < $this->zip->numFiles; $i++) {
      $this->zip->deleteIndex($i);
    }
  }

  /**
   * Reset the zip status..
   */
  public function reset() {
    $this->zip->unchangeAll();
  }

}
