<?php
/**
 * @file Support creating machine name values via devel_generate.
 */

function machine_name_devel_generate($object, $field, $instance, $bundle) {
  if (field_behaviors_widget('multiple values', $instance) == FIELD_BEHAVIOR_CUSTOM) {
    return devel_generate_multiple('_machine_name_devel_generate', $object, $field, $instance, $bundle);
  }
  else {
    return _machine_name_devel_generate($object, $field, $instance, $bundle);
  }
}

function _machine_name_devel_generate($object, $field, $instance, $bundle) {
  $object_field = array();
  // Generate a value that respects max_length.
  if (empty($field['settings']['max_length'])) {
    $field['settings']['max_length'] = 12;
  }
  $object_field['value'] = user_password($field['settings']['max_length']);
  return $object_field;
}
