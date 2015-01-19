<?php

// @deprecated or Convert to Foundation
// Grid size constants
define('KORE_GRID_SIZE', 12);
define('KORE_GRID_FULL', 1);
define('KORE_GRID_HALF', 1/2);
define('KORE_GRID_THIRD', 1/3);
define('KORE_GRID_FOURTH', 1/4);
define('KORE_GRID_FIFTH', 1/5);
define('KORE_GRID_SIXTH', 1/6);
// Just because we can
define('KORE_GRID_SILLY', 1/42);

/**
 *  Implements hook_theme().
 */
function kore_theme($existing, $type, $theme, $path) {
  $path = drupal_get_path('module', 'kore');

  // Register Kitem theme hooks.
  $kitems_registry = kitem_theme_registry($existing, $type, $theme, $path);

  return $kitems_registry + array(
    'kitem' => array(
      'variables' => array(
        'type' => 'default',
        'subtype' => NULL,
        'item' => array(), // @todo Change to object and add handler class feature to plugin.
        'settings' => array(),
      ),
      'file' => 'theme/kitem.inc',
      'template' => 'theme/kitem',
    ),
    'klist' => array(
      'variables' => array(
        'type' => 'default', // Unformatted list
        'subtype' => NULL,
        'items' => array(),
        'settings' => array(),
      ),
      'file' => 'theme/klist.inc',
      'template' => 'theme/klist',
    ),

    // -------------------------------------------------------------------------
    // HTML components

    'html_list' => array(
      'variables' => array(
        'type' => 'ul', // ul, ol, dl
        'attributes' => array(),
        'items' => array(),
        'no_wrapper' => FALSE, // If TRUE, only return <li> items.
      ),
      'file' => 'theme/html_list.inc',
    ),

    // -------------------------------------------------------------------------
    // Common

    // Datetime, use moment.js, turn recent date text to "* ago" format by js
    'timeago' => array(
      'variables' => array(
        'timestamp' => 0,
        'end' => '864000', // In seconds
        'type' => 'medium', // System datetime format.
        'format' => '', // PHP format, will be used if 'type' is 'custom'.
        'attributes' => array(),
      ),
      'file' => 'theme/timeago.inc',
    ),

    // Media image, integrate image, image_style, picture
    'img' => array(
      'variables' => array(
        'file' => NULL, // fid or file object
        'type' => 'image', // image, image_style, picture
        'attributes' => array(), // Need to give individual 'alt', 'title'?
        'style_name' => NULL,
        'link' => NULL,
        'picture' => NULL,
        'responsive' => TRUE,
      ),
      'file' => 'theme/img.inc',
    ),

    // Carousel
    'carousel' => array( // Use owl.carousel.js
      'variables' => array(
        'items' => array(),
        'type' => 'owlcarousel',
        'settings' => array(),
        'id' => NULL, // HTML id, if not input, it would generate a unique one
        'attributes' => array(),
        'instance' => NULL, // For owlcaoursel preset instance
        'style' => NULL, // Add-on styles, string or array
      ),
      'file' => 'theme/carousel.inc',
    ),

    // Theme files array
    'files' => array(
      'variables' => array(
        'files' => array(), // Files fid or object array
        'link'  => FALSE, // Theme file to link
        'style' => 'list', // 'list' or 'inline'
        'settings' => array(), // Meant for style options
      ),
      'file' => 'theme/files.inc',
    ),

    // -------------------------------------------------------------------------
    // Foundation components

    // Foundation blockgrid
    'blockgrid' => array(
      'variables' => array(
        'per_row' => 3, // Can be a number or an array, array is for media query.
        'items' => array(),
        'attributes' => array(),
      ),
      'file' => 'theme/blockgrid.inc',
    ),

    // Foundation dropdown
    'dropdown' => array(
      'variables' => array(
        'id' => NULL, // Set a custom id if needed, or it would automatically generate one. For 'data-dropdown' and content html id.
        'trigger' => NULL, // @required The trigger <a>
        'options' => array(),  // Array to generate data-options attribute value
        'attributes' => array(), // For trigger <a>
        'type' => 'content', // 'links', 'content', 'custom'
        'content' => NULL,
        'content_attributes' => array(), // Not for 'custom'
      ),
      'file' => 'theme/dropdown.inc',
    ),

    // @todo price_table

    // Foundation tooltip
    'tooltip' => array(
      'variables' => array(
        'text' => NULL, // @required
        'title' => NULL, // @required
        'classes' => array(), // [tip-top tip-bottom tip-left tip-right] [radius round]
      ),
      'file' => 'theme/tooltip.inc',
    ),

    // =====================
    // @deprecated in favor of file_image
    'kore_image' => array(
      'variables' => array(
        'type' => 'image',
        'fid' => NULL,
        'path' => NULL,
        'width' => NULL,
        'height' => NULL,
        'alt' => NULL,
        'title' => NULL,
        'attributes' => array(),
        'style_name' => NULL,
        'link' => NULL,
        'picture' => NULL,
        'responsive' => TRUE,
      ),
      'file' => 'theme/kore_image.inc',
    ),
    // @deprecated Bootstrap Thumbnail
    'kore_thumbnail' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
      ),
      'file' => 'theme/kore_thumbnail.inc',
      'template' => 'theme/kore_thumbnail', // @todo Transfer to theme function, Again???
    ),
    // @deprecated Bootstrap Media
    'kore_media' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
        'attributes' => array(),
      ),
      'file' => 'theme/kore_media.inc',
    ),
    // @deprecated Bootstrap list-group
    'kore_list_group' => array(
      'variables' => array(
        'label' => NULL,
        'items' => NULL,
        'items_active' => NULL,
        'items_disabled' => NULL,
      ),
      'file' => 'theme/kore_list_group.inc',
    ),
    // @deprecated in favor of carousel
    'kore_carousel' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
        'attributes' => array(),
      ),
      'file' => 'theme/kore_carousel.inc',
    ),
  );
}

// =============================================================================
// Core Theme Registries

/**
 * Implements hook_preprocess_HOOK() for 'page'.
 */
function kore_preprocess_page(&$vars) {
  // Try to fetch the node object.
  if (!isset($vars['node'])) {
    $menu_item = menu_get_item();
    // Do favor for page manager pages to add node object.
    if (strpos($menu_item['path'], 'node/%') !== FALSE) {
      $vars['node'] = node_load(arg(1));
    }
  }

  // Node page only:
  // Add node type specific template.
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;
  }
}

/**
 * Implements hook_preprocess_HOOK() for 'node'.
 */
function kore_preprocess_node(&$variables) {
  // Add in some useful theme_hook_suggestions.
  // Insert into 'node__[Bundle]__[View Mode]' just after 'node__[Bundle]'.
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];
  $index = array_search('node__' . $node->type, $variables['theme_hook_suggestions']);
  array_splice($variables['theme_hook_suggestions'], $index + 1, 0, 'node__' . $node->type . '__' . $view_mode);
}

/*
function kore_preprocess_field(&$vars) {
  $element = $vars['element'];
  // Add useful 'theme_hook_suggestions' to field.
  $vars['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#entity_type'];
  $vars['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#entity_type'] . '__' . $element['#bundle'];
  $vars['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#entity_type'] . '__' . $element['#bundle'] . '__' . $element['#view_mode'];
  if (isset($element['#formatter'])) {
    $vars['theme_hook_suggestions'][] = 'field__' . $element['#field_name'] . '__' . $element['#formatter'];
  }
}
*/

/**
 * Implements hook_preprocess_REGISTRY() for 'image'.
 */
function kore_preprocess_image(&$vars) {
  // Prepare needed variables by input file object.
  if (isset($vars['file']) && is_object($vars['file'])) {
    $vars['path'] = ($vars['path'] == NULL) ? $vars['file']->uri : $vars['path'];
    $vars['alt'] = ($vars['alt'] == NULL) ? $vars['file']->alt : $vars['alt'];
    $vars['title'] = ($vars['title'] == NULL) ? $vars['file']->title : $vars['title'];
  }
}

/**
 * Implements hook_preprocess_REGISTRY() for 'image_style'.
 */
function kore_preprocess_image_style(&$vars) {
  kore_preprocess_image($vars);
}

// =============================================================================
// Utility

/**
 * Process $settings['attributes'] into template attributes arrays.
 */
function kore_attributes_process(&$vars, $attributes) {
  $indexes = array('classes_array', 'attributes_array', 'title_attributes_array', 'content_attributes_array');
  foreach ($indexes as $index) {
    if (isset($attributes[$index])) {
      $vars[$index] = array_merge($vars[$index], $attributes[$index]);
    }
  }
}

/**
 * A shortcut for theme_get_registry().
 */
function kore_theme_get_registry($name) {
  $registry = theme_get_registry();
  return $registry[$name];
}

/**
 * @deprecated or convert to Foundation context
 *
 * Calculates a column number based on columns in the total and current grid.
 *
 * @param int $percentage
 *   Whole number version of the percentage to calculate.
 * @param (optional) integer $total_columns
 *   The total actual columns in the current row. Defaults to 2.
 *
 * @return int
 *   The column count, rounded if necessary.
 *
 * @see kalatheme_grid_size().
 */
function kore_grid_size($percentage, $total_columns = 2) {
  $columns = $percentage * KORE_GRID_SIZE;
  // Deal with uneven division.
  if (!is_integer($columns)) {
    if ($columns > (KORE_GRID_SIZE / $total_columns)) {
      $columns = floor($columns);
    }
    else {
      $columns = ceil($columns);
    }
  }

  return $columns;
}
