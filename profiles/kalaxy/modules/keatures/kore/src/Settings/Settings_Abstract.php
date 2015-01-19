<?php

/**
 * @file
 */


namespace Drupal\kore\Settings;


abstract class Settings_Abstract implements Settings {

  public static function getDefault() {
    return array();
  }

  public static function buildForm($id, $settings, $wrap = FALSE) {
    return array();
  }

  public static function buildSummary($id, $settings) {
    return NULL;
  }

  public static function buildProduct($id, $settings, $context = NULL) {
    return NULL;
  }

}
