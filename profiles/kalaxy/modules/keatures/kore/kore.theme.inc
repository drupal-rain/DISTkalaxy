<?php

/**
 *  Implements hook_preprocess().
 */
function kore_preprocess_page(&$vars) {
  if (!isset($vars['node'])) {
    $menu_item = menu_get_item();
    // Do favor for page manager pages to add node object.
    if (strpos($menu_item['path'], 'node/%') !== FALSE) {
      $vars['node'] = node_load(arg(1));
    }
  }
  // Add node type specific template.
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;
  }
}

/**
 *  Implements hook_theme().
 */
function kore_theme($existing, $type, $theme, $path) {
  return array(
    'kore_list_group' => array(
      'variables' => array(
        'label' => NULL,
        'items' => NULL,
        'items_active' => NULL,
        'items_disabled' => NULL,
      ),
    ),
  );
}

function theme_kore_list_group($vars) {
  $out = "";
  if ($vars['label']) {
    $out .= "<h3>" . $vars['label'] . "</h3>";
  }
  if ($vars['items']) {
    $out .= '<ul class="list-group">';
    $items_active = $vars['items_active'];
    $items_disabled = $vars['items_disabled'];
    foreach ($vars['items'] as $key => $value) {
      $classes = array('list-group-item');
      if (is_array($items_disabled) && in_array($key, $items_disabled)) {
        $classes[] = 'disabled';
      }
      if (is_array($items_active) && in_array($key, $items_active)) {
        $classes[] = 'active';
      }
      $out .= '<li class="' . implode(' ', $classes) . '">' . $value . "</li>";
    }
    $out .= "</ul>";
  }

  return $out;
}
