<?php

/**
 * @file
 */

namespace Drupal\kore\Field_Form;

abstract class Field_Form_Abstract implements Field_Form {

  public static function info() {
    return NULL;
    /*
    return array(
      'field' => array(
        'label' => t(''),
        'description' => t(''),
        'weight' => 0,
      ),
    );
    */
  }

  public static function form($entity_type, $entity, &$form, &$form_state, $langcode) {
  }

  public static function validate($entity_type, $entity, &$errors) {
  }

  public static function submit($entity_type, $entity, $form, &$form_state) {
  }

}
