<?php
/**
 * @file
 * kpane.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function kpane_eck_bundle_info() {
  $items = array(
    'kpost_kpost' => array(
      'machine_name' => 'kpost_kpost',
      'entity_type' => 'kpost',
      'name' => 'kpost',
      'label' => 'Post',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function kpane_eck_entity_type_info() {
  $items = array(
    'kpost' => array(
      'name' => 'kpost',
      'label' => 'Post',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'body' => array(
          'label' => 'Body',
          'type' => 'longtext',
          'behavior' => 'textarea',
        ),
      ),
    ),
  );
  return $items;
}
