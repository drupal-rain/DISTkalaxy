<?php

define('KORE_ENTITY_INFO_TYPE', 1);
define('KORE_ENTITY_INFO_BUNDLE', 2);
define('KORE_ENTITY_INFO_VIEWMODE', 4);

/**
 * Prepare an entity skeloton array.
 *
 * @todo A better cache?
 */
function kore_entity_info_array($mode = 3) {
  $info = entity_get_info();
  $return = &drupal_static(__FUNCTION__, array());

  if (empty($return)) {
    foreach ($info as $entity_type => $info_entity_type) {
      $return[KORE_ENTITY_INFO_TYPE][$entity_type] = array();
      foreach ($info_entity_type['view modes'] as $view_mode => $info_view_mode) {
        $return[KORE_ENTITY_INFO_TYPE|KORE_ENTITY_INFO_VIEWMODE][$entity_type][$view_mode] = array();
      }
      foreach ($info_entity_type['bundles'] as $bundle => $info_bundle) {
        $return[KORE_ENTITY_INFO_TYPE|KORE_ENTITY_INFO_BUNDLE][$entity_type][$bundle] = array();
        foreach ($info_entity_type['view modes'] as $view_mode => $info_view_mode) {
          $return[KORE_ENTITY_INFO_TYPE|KORE_ENTITY_INFO_BUNDLE|KORE_ENTITY_INFO_VIEWMODE][$entity_type][$bundle][$view_mode] = array();
        }
      }
    }
  }

  return $return[$mode];
}
