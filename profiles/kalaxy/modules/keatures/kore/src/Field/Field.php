<?php

/**
 * @file Interface for Field type defition component.
 */

namespace Drupal\kore\Field;


interface Field {

  /**
   * hook_field_info().
   */
  public static function info();

  /**
   * hook_field_schema().
   */
  public static function schema($field);

  /**
   * hook_field_settings_form().
   */
  public static function settings_form($field, $instance, $has_data);

  /**
   * hook_field_instance_settings_form().
   */
  public static function instance_settings_form($field, $instance);

  /**
   * hook_field_is_empty().
   */
  public static function is_empty($item, $field);

  /**
   * hook_field_storage_update_field()
   */
  public static function storage_update_field($field, $prior_field, $has_data);

}
