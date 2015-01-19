<?php

/**
 * Implements hook_entity_property_info().
 *
 * Loop through all node bundles to check on kdata enabled bundle, then add
 * properties to them.
 */
function kore_entity_property_info() {
  $info = array();

  // Add kdata bundles as entity property.
  // It would add data field to 'views_entity_node' automatically.
  /*
  foreach (node_type_get_names() as $name => $label) {
    if (kore_node_type_kdata_enabled($name)) {
      $properties = &$info['node']['bundles'][$name]['properties'];
      $kdata_bundles = kore_node_type_kdata_get_bundles($name);
      foreach ($kdata_bundles as $kdata_bundle) {
        $properties[$kdata_bundle] = array(
          'label' => t('kdata<@kdata_type>', array('@kdata_type' => $kdata_bundle)),
          'type' => $name,
          'getter callback' => 'kore_entity_metadata_node_kdata_getter_callback',
          'computed' => TRUE,
          'entity views field' => TRUE,
        );
      }
    }
  }
  */

  return $info;
}
