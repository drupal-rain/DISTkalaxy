<?php

/**
 * @file Interface for Field Display Component.
 *
 * It can be used to create an extra field or some extra fields.
 * It can be used to override current field.
 *
 * Name convention:
 *   - [Entity Type]__[Field]
 *   - [Entity Type]__[Bundle]__[Field]
 *   - @consider [Entity Type]__[Bundle]__[View Mode]__[Field]
 */

namespace Drupal\kore\Field_Display;

interface Field_Display {

  /**
   * @Implements hook_field_extra_fields().
   */
  public static function info();

  /**
   * @Implements hook_field_attach_load().
   *
   * @see field_attach_load().
   * This function has simple DB cache.
   */
  public static function load($entity_type, $entities, $age, $options);

  /**
   * @Implements hook_field_attach_view_alter().
   *
   * Multiple usage, alter $output or return a newly created element.
   *
   * $context = array(
   *   'entity_type' => '',
   *   'entity' => NULL,
   *   'view_mode' => '',
   *   'display' => '',
   *   'language' => '',
   * );
   *
   * $output['FIELD'] need to be a renderable element, string would cause issue.
   */
  public static function view_alter(&$output, $context);

}
