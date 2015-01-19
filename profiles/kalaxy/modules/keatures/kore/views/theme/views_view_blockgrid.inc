<?php

function template_preprocess_views_view_blockgrid(&$vars) {
  foreach (kore_foundation_sizes() as $size) {
    if (!empty($vars['options'][$size])) {
      $vars['classes_array'][] = $size . '-block-grid-' . $vars['options'][$size];
    }
  }
}
