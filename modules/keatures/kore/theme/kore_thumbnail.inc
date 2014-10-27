<?php

function template_preprocess_kore_thumbnail(&$vars) {
  drupal_add_js(drupal_get_path('module', 'kore') . '/js/kore_thumbnail.js');

  $settings = $vars['settings'];
  $settings += array(
    'attributes' => array(),
  );

  kore_attributes_process($vars, $settings['attributes']);
}

// $items_output
function template_process_kore_thumbnail(&$vars) {
  $items = $vars['items'];
  $settings = $vars['settings'];
  // Remove 'attributes' for item
  unset($settings['attributes']);

  $vars['items_output'] = array();
  foreach ($items as $item) {
    $variables = array(
      'type' => 'thumbnail',
      'item' => $item,
      'settings' => $settings,
    );
    $item_output = kitem_theme($variables);
    $vars['items_output'][] = $item_output;
  }
}
