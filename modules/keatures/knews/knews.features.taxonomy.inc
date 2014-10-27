<?php
/**
 * @file
 * knews.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function knews_taxonomy_default_vocabularies() {
  return array(
    'knews_cat' => array(
      'name' => 'News Category',
      'machine_name' => 'knews_cat',
      'description' => '',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => -10,
    ),
  );
}
