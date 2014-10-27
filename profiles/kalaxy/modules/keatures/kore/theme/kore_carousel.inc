<?php

function theme_kore_carousel($vars) {
  $items = $vars['items'];
  $settings = $vars['settings'];
  $attributes = $vars['attributes'];


  $settings_group = array(
    'instance' => $settings['owlcarousel'],
    'attributes' => array(
      'id' => array(
        'default' => drupal_html_id($settings['id']),
      ),
    ),
  );

  $item_theme = 'kitem';
  if ($settings['kitem'] != 'default') {
    $item_theme .= '__' . $settings['kitem'];
  }

  $items_group = array();
  foreach ($items as $item) {
    $variables = array(
      'type' => $settings['kitem'],
      'item' => $item,
      'settings' => $settings,
    );

    $items_group[]['row'] = theme($item_theme, $variables);
  }

  $element = NULL;
  if ($items_group) {
    $element = array(
      '#theme' => 'owlcarousel',
      '#items' => $items_group,
      '#settings' => $settings_group,
    );
  }

  return $element;
}
