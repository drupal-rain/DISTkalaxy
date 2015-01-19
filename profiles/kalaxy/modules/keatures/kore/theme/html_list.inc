<?php

function theme_html_list($vars) {
  $output = '';

  switch ($vars['type']) {
    case 'ul':
    case 'ol':
      foreach ($vars['items'] as $item) {
        if ($wrapper = strpos($item, '<li') === FALSE) {
          $output .= '<li>';
        }
        $output .= $item;
        if ($wrapper) {
          $output .= '</li>';
        }
      }
      break;
    case 'dl':
      foreach ($vars['items'] as $item) {
        if (is_array($item)) {
          $output .= '<dt>' . $item['term'] . '</dt>';
          $output .= '<dd>' . $item['description'] . '</dd>';
        }
        else {
          // Customized item
          $output .= $item;
        }
      }
      break;
  }

  if (!$vars['no_wrapper']) {
    $output = '<' . $vars['type'] . drupal_attributes($vars['attributes']) . '>' . $output . '<' . $vars['type'] . '>';
  }

  return $output;
}
