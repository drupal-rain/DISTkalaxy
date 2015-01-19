<?php

/**
 * @themable
 */
function theme_tooltip($vars) {
  $output = '<span data-tooltip aria-haspopup="true" class="has-tip';
  $output .= (!empty($vars['classes'])) ? implode(' ', $vars['classes']) : '';
  $output .= '" title="' . $vars['title'] . '">';
  $output .= $vars['text'];
  $output .= '</span>';

  return $output;
}
