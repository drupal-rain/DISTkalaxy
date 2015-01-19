<?php

// A positive integer to store the node nid.

$plugin = array(
  'label' => t('Kdata nid'),
  'default_formatter' => 'eck_extras_kdata_nid_property_default_formatter',
  'property_info' => 'eck_extras_kdata_nid_property_property_info',
  'getter' => 'eck_extras_kdata_nid_property_getter',
  'setter' => 'eck_extras_kdata_nid_property_setter',
);

function eck_extras_kdata_nid_property_default_formatter($property, $vars) {
  $entity = $vars['entity'];

  return array(
    '#markup' => strip_tags($property . '(Node): ' . $entity->{$property}),
  );
}

function eck_extras_kdata_nid_property_property_info($property, $vars) {
  $info = $vars;
  // Predefined type to 'node'
  $info['properties'][$property]['type'] = 'node';

  return $info;
}

function eck_extras_kdata_nid_property_getter($property, $vars) {
  $entity = $vars['entity'];

  // Entity metadata wrapper get chain.
  return entity_metadata_wrapper('node', $entity->{$property});
}

function eck_extras_kdata_nid_property_setter($property, $vars) {
  $entity = $vars['entity'];
  $entity->{$property} = $vars['value'];
}
