<?php
/**
 * @file
 * knews.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function knews_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function knews_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function knews_node_info() {
  $items = array(
    'knews' => array(
      'name' => t('News'),
      'base' => 'node_content',
      'description' => t('News content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
