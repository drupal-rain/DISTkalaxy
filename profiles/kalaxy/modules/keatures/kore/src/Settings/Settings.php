<?php

/**
 * @file Interface for Theme registry helper class.
 */

namespace Drupal\kore\Settings;

interface Settings {

  public static function getDefault();

  /**
   * Possible input:
   *   - $form += settings_form('foo', $settings);
   */
  public static function buildForm($id, $settings, $wrap = FALSE);

  public static function buildSummary($id, $settings);

  /**
   * Generate main purpose of this settings form.
   *
   * Produce a $variables for theme function.
   */
  public static function buildProduct($id, $settings, $context = NULL);

}
