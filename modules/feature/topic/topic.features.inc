<?php
/**
 * @file
 * topic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function topic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "relation" && $api == "relation_type_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function topic_node_info() {
  $items = array(
    'subject' => array(
      'name' => t('Subject'),
      'base' => 'node_content',
      'description' => t('Subject of a topic.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'topic' => array(
      'name' => t('Topic'),
      'base' => 'node_content',
      'description' => t('The important and unique topic.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
