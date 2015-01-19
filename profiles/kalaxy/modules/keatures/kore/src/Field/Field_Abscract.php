<?php

/**
 * @file Abscract class for Field component.
 */

namespace Drupal\kore\Field;


abstract class Field_Abscract implements Field {

  public static function info() {
    return NULL;
  }

  public static function schema($field) {
    return array(
      'columns' => array(
        'value' => array(
          'description' => 'Field value.',
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'default' => '',
        ),
      ),
    );
  }

  public static function settings_form($field, $instance, $has_data) {
    return array();
  }

  public static function instance_settings_form($field, $instance) {
    return array();
  }

  public static function is_empty($item, $field) {
    if (isset($item['value'])) {
      return TRUE;
    }
    return FALSE;
  }

  public static function storage_update_field($field, $prior_field, $has_data) {
  }

}
