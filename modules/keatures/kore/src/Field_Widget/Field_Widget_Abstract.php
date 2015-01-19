<?php

/**
 * @file
 */


namespace Drupal\kore\Field_Widget;


abstract class Field_Widget_Abstract implements Field_Widget {

  public static function info() {
    return NULL;
  }

  public static function settings_form($field, $instance) {
    return array();
  }

  public static function form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
    return array();
  }

}
