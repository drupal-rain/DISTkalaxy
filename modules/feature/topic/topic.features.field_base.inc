<?php
/**
 * @file
 * topic.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function topic_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_topic'
  $field_bases['field_topic'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topic',
    'foreign keys' => array(
      'node' => array(
        'columns' => array(
          'target_id' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'topic' => 'topic',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_topic_name'
  $field_bases['field_topic_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_topic_name',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'machine_name',
    'settings' => array(
      'max_length' => 128,
      'replace' => '_',
      'replace_pattern' => '[^a-z0-9_]+',
    ),
    'translatable' => 0,
    'type' => 'machine_name',
  );

  return $field_bases;
}
