<?php

/**
 *  Implements hook_node_insert().
 */
function kore_node_insert($node) {
  kore_node_save($node);
}

/**
 *  Implements hook_node_update().
 */
function kore_node_update($node) {
  kore_node_save($node);
}

/**
 * For node save operations.
 */
function kore_node_save($node) {
  if (kore_node_kdata_enabled($node)) {
    $kdata_list = kore_node_kdata_get_entities_flat($node);
    foreach ($kdata_list as $kdata) {
      $kdata->nid = $node->nid;
      $kdata->changed = $node->changed;
      $kdata->save();
    }
  }
}

// -----------------------------------------------------------------------------
// Node type

/**
 * Simple function to indicate the field name.
 */
function kore_node_type_kdata_field_name($type) {
  return $type . '_kdata';
}

/**
 * Check if the node type has kdata feature enabled.
 */
function kore_node_type_kdata_enabled($type, $reset = FALSE) {
  $field_name_kdata = $type . '_kdata';

  // Static cache
  $cache = &drupal_static(__FUNCTION__, array(), $reset);
  if (isset($cache[$type])) {
    return $cache[$type];
  }

  $field_kdata = field_info_field($field_name_kdata);
  if ($field_kdata && isset($field_kdata['bundles']['node'])) {
    // 1. Has field
    // 2. The field is entityreference
    // 3. Target bundle with the same name
    if (
      in_array($type, $field_kdata['bundles']['node'])
      && $field_kdata['type'] == 'entityreference'
      && $field_kdata['settings']['target_type'] == $type
    ) {
      $cache[$type] = TRUE;
      return TRUE;
    }
  }

  $cache[$type] = FALSE;
  return FALSE;
}

/**
 * Get a list of kdata bundles corresponding to the node type.
 */
function kore_node_type_kdata_get_bundles($type, $reset = FALSE) {
  $bundles = array();
  $eck_entity_type = EntityType::loadByName($type, $reset);
  foreach (Bundle::loadByEntityType($eck_entity_type) as $eck_bundle) {
    $bundles[] = $eck_bundle->name;
  }

  return $bundles;
}

// -----------------------------------------------------------------------------
// Node

/**
 * Simple function to indicate the field name.
 */
function kore_node_kdata_field_name($node) {
  return kore_node_type_kdata_field_name($node->type);
}

/**
 * Check if node bundle enables kdata feature by checking the field.
 */
function kore_node_kdata_enabled($node, $reset = FALSE) {
  return kore_node_type_kdata_enabled($node->type, $reset);
}

// Entity id indexed kdata entities.
function kore_node_kdata_get_entities_flat($node) {
  $items = field_get_items('node', $node, kore_node_kdata_field_name($node));
  $list = array();
  if ($items) {
    $ids = array();
    foreach ($items as $item) {
      $ids[] = $item['target_id'];
    }
    $list = entity_load($node->type, $ids);
  }

  return $list;
}

/**
 * Get the specific kdata<TYPE> by using kdata field.
 */
function kore_node_kdata_get_entity($node, $kdata_bundle) {
  $lang = entity_language('node', $node);
  $kdatas = array();
  if ($node->kdata && $node->kdata[$lang]) {
    foreach ($node->kdata[$lang] as $delta => $value) {
      $kdatas[$delta] = entity_load_single('kdata', $value['target_id']);
    }
    // Return the first match.
    // So use UI to sort it up.
    foreach ($kdatas as $kdata) {
      if ($kdata->type == $kdata_bundle) {
        return $kdata;
      }
    }
  }

  return FALSE;
}

/**
 * Get a list of kdata bundles corresponding to the node.
 */
function kore_node_kdata_get_bundles($node, $reset = FALSE) {
  return kore_node_type_kdata_get_bundles($node->type, $reset);
}
