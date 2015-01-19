<?php

/**
 * @file
 */


namespace Drupal\kore\Field_Display;

abstract class Field_Display_Abstract implements Field_Display {

  public static function info() {
    return NULL;
    /*
    return array(
      'FIELD' => array(
        'label' => t(''),
        'description' => t(''),
        'weight' => 0,
      ),
    );
    */
  }

  public static function load($entity_type, $entities, $age, $options) {
  }

  public static function view_alter(&$output, $context) {
    // $entity_type, $entity, $view_mode, $display, $language
    // extract($context);
    // $output['FIELD'] = array(
    //   '#markup' => theme('FIELD', $variables),
    // );
  }

}
