<?php

// ctools_include('image', 'kfield);

// =============================================================================
//
// @todo $settings.
// $settings holds field_base, widget, display settings.



function kfield_image_add_image_default($entity_type, $bundle, $field_name, $field_label = '') {
  kfield_add_field_default('image', $entity_type, $bundle, $field_name, $field_label);
}
