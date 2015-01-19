<?php

/**
 * @file Interface for Field Form Component.
 *
 * It can be used to create extra field, extra fields.
 * It can be used to override current field.
 *
 * Name convention:
 *   - [Entity Type]__[Field]
 *   - [Entity Type]__[Bundle]__[Field]
 *   - @consider It's possible to have [Field] for all entities.
 * Need to avoid: [Field] should not be the same as [Entity Type] or [Bundle]
 */

namespace Drupal\kore\Field_Form;

interface Field_Form {

  /**
   * @Implements hook_field_extra_fields().
   */
  public static function info();

  /**
   * @Implements hook_field_attach_form().
   */
  public static function form($entity_type, $entity, &$form, &$form_state, $langcode);

  /**
   * @Implements hook_field_attach_validate().
   */
  public static function validate($entity_type, $entity, &$errors);

  /**
   * @Implements hook_field_attach_submit().
   */
  public static function submit($entity_type, $entity, $form, &$form_state);

}
