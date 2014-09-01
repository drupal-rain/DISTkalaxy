<?php
/**
 * @file
 * kpage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kpage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function kpage_node_info() {
  $items = array(
    'kpage' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => t('Site-wide static page content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
