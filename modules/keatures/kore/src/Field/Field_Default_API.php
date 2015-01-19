<?php

/**
 * @file
 */

namespace Drupal\kore\Field;

// As documentation only.
// @see _field_invoke().
// @doc http://drupal7.api/api/drupal/modules%21field%21field.attach.inc/function/_field_invoke/7.x
// @doc http://drupal7.api/api/drupal/7.x/search/hook_field_attach
// @todo Consider field_attach_* hooks implementation
// Even these hooks are only for the field type module, because all the fields are in 'kore' realm, widget, formatter, can also invoke.
interface Field_Default_API {

  // @doc http://drupal7.api/api/drupal/modules%21field%21field.api.php/function/hook_field_load/7.x
  // Pay attention to performance issue, so not for Field_Widget
  public static function load($entity_type, $entities, $field, $instances, $langcode, &$items, $age);

  public static function validate($entity_type, $entity, $field, $instance, $langcode, $items, &$errors);

  public static function presave($entity_type, $entity, $field, $instance, $langcode, &$items);

  public static function insert($entity_type, $entity, $field, $instance, $langcode, &$items);

  public static function update($entity_type, $entity, $field, $instance, $langcode, &$items);

  public static function delete($entity_type, $entity, $field, $instance, $langcode, &$items);

  public static function delete_revision($entity_type, $entity, $field, $instance, $langcode, &$items);

  public static function prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items);

  public static function prepare_translation($entity_type, $entity, $field, $instance, $langcode, &$items, $source_entity, $source_langcode);

}
