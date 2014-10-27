<?php

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
