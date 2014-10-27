<?php

/**
 * Simple picture theme for an image.
 */
function kore_picture_theme_image($image, $group_name, $fallback_image_style = '', $options = array()) {
  $mappings = picture_mapping_load($group_name);
  $breakpoint_styles = picture_get_mapping_breakpoints($mappings, $fallback_image_style);
  $uri = is_object($image) ? $image->uri : $image;
  $vars = array(
    'uri' => $uri,
    'breakpoints' => $breakpoint_styles,
  );
  $vars += $options;

  return theme('picture', $vars);
}
