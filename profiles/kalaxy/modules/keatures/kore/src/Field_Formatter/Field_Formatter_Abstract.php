<?php

/**
 * @file
 */

namespace Drupal\kore\Field_Formatter;


abstract class Field_Formatter_Abstract implements Field_Formatter {

  public static function info() {
    return NULL;
    /*
    return array(
      'FORMATTER' => array(
        'label' => t(''),
        'field types' => array('FIELD_TYPE_1', 'FIELD_TYPE_2'),
        'settings' => array(
          'var_1' => '',
          'var_2' => '',
        ),
      ),
    );
    */
  }

  public static function settings_form($field, $instance, $view_mode, $form, &$form_state) {
    return NULL;
  }

  public static function settings_summary($field, $instance, $view_mode) {
    // At least return empty string to make the settings editable.
    return ' ';
  }

  public static function prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  }

  public static function view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
    return NULL;
  }

}
