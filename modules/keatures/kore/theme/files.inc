<?php

/**
 * Process function for 'files'.
 */
function template_process_files(&$vars) {
  // Allow passing in file fid
  foreach ($vars['files'] as $i => $file) {
    if (is_numeric($file) && $file_object = file_load($file)) {
      $vars['files'][$i] = $file_object;
    }
  }
}

/**
 * Theme function for 'files'.
 */
function theme_files(&$vars) {
  $output = NULL;
  if (empty($vars['files'])) {
    return $output;
  }

  // Prepare items
  $items = array();
  foreach ($vars['files'] as $i => $file) {
    if ($vars['link']) {
      $items[$i] = theme('file_link', array('file' => $file));
    }
    else {
      $items[$i] = $file->filename;
    }
  }

  // Theme by style
  if ($vars['style'] == 'list') {
    $variables['items'] = $items;
    $variables += $vars['settings'];
    $output = theme('html_list', $variables);
  }
  else if ($vars['style'] == 'inline') {
    $output = implode($vars['settings']['delimiter'], $items);
  }

  return $output;
}
