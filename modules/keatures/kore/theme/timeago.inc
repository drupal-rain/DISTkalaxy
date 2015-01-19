<?php

/**
 * Theme function for 'datetime_ago'.
*/
function theme_timeago($vars) {
  libraries_load('moment');
  ctools_add_js('timeago', 'kore');
  $data = 'timestamp:' . $vars['timestamp'] . '; end:' . $vars['end'];
  $vars['attributes']['class'][] = 'timeago';

  $output = '<span' . drupal_attributes($vars['attributes']) . ' data-moment data-options="' . $data . '">';
  $output .= format_date($vars['timestamp'], $vars['type'], $vars['format']);
  $output .= '</span>';

  return $output;
}
