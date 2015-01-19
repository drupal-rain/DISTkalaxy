<?php

function theme_blockgrid($vars) {
  if (is_array($vars['per_row'])) {
    foreach ($vars['per_row'] as $size => $per_row) {
      $vars['attributes']['class'][] = $size . '-block-grid-' . $per_row;
    }
  }
  else if (is_numeric($vars['per_row'])) {
    $vars['attributes']['class'][] = 'small-block-grid-' . $vars['per_row'];
  }

  $output = '<ul' . drupal_attributes($vars['attributes']) . '>';
  foreach ($vars['items'] as $item) {
    // Add the wrapper if not exist.
    if ($wrapper = strpos($item, '<li') === FALSE) {
      $output .= '<li>';
    }
    $output .= $item;
    if ($wrapper) {
      $output .= '</li>';
    }
  }
  $output .= '</ul>';


  return $output;
}
