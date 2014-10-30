<?php
/**
 * @file
 * ktopic_review.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ktopic_review_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function ktopic_review_node_info() {
  $items = array(
    'kreview' => array(
      'name' => t('Review'),
      'base' => 'node_content',
      'description' => t('Review to a topic.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
