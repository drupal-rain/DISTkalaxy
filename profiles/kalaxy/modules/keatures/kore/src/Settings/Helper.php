<?php

/**
 * @file
 */


namespace Drupal\kore\Settings;


class Helper {

  public static function &prepareForm($id, &$form_return) {
    if (is_array($id)) {
      foreach ($id as $child) {
        $form = &$form_return[$child];
      }
    }
    else if (!empty($id)) {
      $form = &$form_return[$id];
    }
    else {
      $form = &$form_return;
    }

    return $form;
  }

  public static function prepareSettings($id, $settings, $default = array()) {
    if (is_array($id)) {
      foreach ($id as $child) {
        $settings = $settings[$child];
      }
    }
    else if (!empty($id)) {
      $settings = $settings[$id];
    }
    $settings += $default;

    return $settings;
  }

  public static function prepareInputId($id, $wrap, $trace) {
    $input_id = ':input[name$="';
    $cnt = 0;
    if (is_array($id)) {
      foreach ($id as $child) {
        if (!$wrap && $cnt == 0) {
          $input_id .= $child;
          $cnt++;
        }
        else {
          $input_id .= '[' . $child . ']';
        }
      }
    }
    else if (!empty($id)) {
      if (!$wrap) {
        $input_id .= $id;
      }
      else {
        $input_id .= '[' . $id . ']';
      }
    }
    $input_id .= '[' . $trace . ']"]';

    return $input_id;
  }

}
