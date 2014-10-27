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
 *   ),
 * );
 */
/*
$vars = array(
  'type' => 'image',
  'fid' => 0,
  'path' => '',
  'width' => '',
  'height' => '',
  'alt' => '',
  'title' => '',
  'attributes' => '',
  // image_style
  'style_name' => '',
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
);
*/

function theme_kore_image($vars) {
  $output = NULL;

  $type = $vars['type'];
  switch ($type) {
    case 'image':
      $output = theme('image', $vars);
      break;
    case 'image_style':
      $output = theme('image_style', $vars);
      break;
    case 'picture':
      $output = theme('picture', $vars);
      break;
  }

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

function template_preprocess_kore_image(&$vars) {
  // Allow only pass in fid.
  if (empty($vars['path'])) {
    $file = file_load($vars['fid']);
    $vars['path'] = $file->uri;
  }
  // @todo Allow pass file object as 'item'.
  // @todo Allow pass file path as 'item'.

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
      'uri' => $vars['path'],
      'breakpoints' => $breakpoint_styles,
    );
    $vars += $picture;
  }
}
