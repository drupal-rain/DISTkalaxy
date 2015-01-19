<?php

// * HTML
// * image
// * image_style
// * picture

/**
 * $vars = array(
 *   'type' => 'image', // image, image_style, picture
 *   // Item can be just a file id.
 *   // Item can be a string represent the path.
 *   'item' => array(
 *     'path' => '',
 *     'width' => '',
 *     'height' => '',
 *     'alt' => '',
 *     'title' => '',
 *     'attributes' => '',
 *     // image_style
 *     'style_name' => '',
 *   ),
 *   'settings' => array(
 *     // all
 *     'attributes' => array(), // @todo
 *     'link' => array(
 *       // l()
 *       'path' => '',
 *       'language' => '',
 *       'attributes' => array(),
 *       // url()
 *       // @todo ...
 *     ),
 *     // image_style
 *     'image_style' => '',
 *     // picture
 *     'picture' => array(
 *       'picture_mapping' => '',
 *       'fallback_image_style' => '',
 *       'attributes' => array(),
 *     ),
 *     // Responsive to parent
 *     'responsive' => TRUE,
 *   ),
 * );
 */
// Current $variables
/*
$vars = array(
  'type' => 'image',
  'file' => '',
  'attributes' => '',
  // image_style
  'style_name' => '',
  // Link wrapper
  'link' => array(
    'path' => '',
    'language' => '',
    'attributes' => array(),
  ),
  // picture
  'picture' => array(
    'picture_mapping' => '',
    'fallback_image_style' => '',
    'attributes' => array(),
  ),
  // Responsive to parent
  'responsive' => TRUE,
);
*/

/**
 * Theme function for 'img'.
 */
function theme_img($vars) {
  $output = NULL;

  // $vars['type'] is another real theme registry.
  $output = theme($vars['type'], $vars);

  // Wrap it with link.
  if (isset($vars['link'])) {
    $link = $vars['link'];
    unset($link['path']);
    $options = array(
      'html' => TRUE,
    ) + $link;
    $output = l($output, $vars['link']['path'], $options);
  }

  return $output;
}

/**
 * Implements template_preprocess_REGISTRY().
 */
function template_preprocess_img(&$vars) {
  // Allow fid or file object.
  if (is_numeric($vars['file'])) {
    $vars['file'] = file_load($vars['file']);
  }

  // Default 'type' is set to 'image' in theme registry already.
  // Auto upgrade to iamge_style if style_name is set.
  if ($vars['type'] == 'image' && isset($vars['style_name'])) {
    $vars['type'] = 'image_style';
  }

  // image_style
  if ($vars['type'] == 'image_style' && empty($vars['style_name'])) {
    $vars['style_name'] = 'thumbnail';
  }

  // Picture
  if ($vars['type'] == 'picture') {
    $picture = $vars['picture'];
    unset($vars['picture']); // No need.
    $mappings = picture_mapping_load($picture['picture_mapping']);
    $breakpoint_styles = picture_get_mapping_breakpoints($mappings, $picture['fallback_image_style']);
    unset($picture['picture_mapping']);
    unset($picture['fallback_image_style']);
    $vars += array(
      'uri' => $vars['file']->uri,
      'breakpoints' => $breakpoint_styles,
    );
    $vars += $picture;
  }

  // Responsive
  if ($vars['responsive']) {
    $vars['attributes']['class'] = 'img-responsive'; // @todo Steal it from Bootstrap
  }
}
