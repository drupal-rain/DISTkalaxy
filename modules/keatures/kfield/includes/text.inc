<?php

function kfield_text_add_text_default($entity_type, $bundle, $field_name, $field_label = '') {
  kfield_add_field_default('text', $entity_type, $bundle, $field_name, $field_label);
}

function kfield_text_add_longtext_default($entity_type, $bundle, $field_name, $field_label = '') {
  kfield_add_field_default('text_long', $entity_type, $bundle, $field_name, $field_label);
}
