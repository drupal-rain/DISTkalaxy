<?php
/**
 * Created by PhpStorm.
 * User: Kolier
 * Date: 2015-01-04
 * Time: 05:53
 */

namespace Drupal\kore\Field_Widget;


interface Field_Widget {

  /**
   * hook_field_widget_info().
   */
  public static function info();

  /**
   * hook_field_widget_settings_form().
   */
  public static function settings_form($field, $instance);

  /**
   * hook_field_widget_form().
   */
  public static function form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element);

}
