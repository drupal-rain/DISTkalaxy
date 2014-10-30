<?php

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
    'kore_list_group' => array(
      'variables' => array(
        'label' => NULL,
        'items' => NULL,
        'items_active' => NULL,
        'items_disabled' => NULL,
      ),
      'file' => 'theme/kore_list_group.inc',
    ),
    'kore_media' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
        'attributes' => array(),
      ),
      'file' => 'theme/kore_media.inc',
    ),
    'kore_thumbnail' => array(
      'variables' => array(
        'items' => array(),
        'settings' => array(),
      ),
      'file' => 'theme/kore_thumbnail.inc',
      'template' => 'theme/kore_thumbnail', // @todo Transfer to theme function, Again???
    ),
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
// Theme Registry

/**
 *  Implements hook_preprocess().
 */
function kore_preprocess_page(&$vars) {
  if (!isset($vars['node'])) {
    $menu_item = menu_get_item();
    // Do favor for page manager pages to add node object.
    if (strpos($menu_item['path'], 'node/%') !== FALSE) {
      $vars['node'] = node_load(arg(1));
    }
  }
  // Add node type specific template.
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;
  }
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
