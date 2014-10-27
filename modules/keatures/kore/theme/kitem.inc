<?php

// =============================================================================
// Template

function template_preprocess_kitem(&$vars) {
  // Initiate Defaults
  kitem_initiate($vars);

  // Plugin
  _kitem_plugin_callback($vars, 'preprocess');

}

// $image
// $title
// $body
function template_process_kitem(&$vars) {
  // Run through to generate standard variables: $image, $title, $body.
  kitem_process($vars);

  // Plugin
  _kitem_plugin_callback($vars, 'process');

}

// =============================================================================
// Helper

function _kitem_plugin_callback(&$vars, $callback) {
  // Plugin
  if (isset($vars['type']) && $vars['type'] != 'default') {
    $function = kitem_plugin_get_function($vars['type'], $callback);
    if ($function) {
      $function($vars);
    }
    if (!empty($vars['subtype'])) {
      $function = kitem_plugin_get_subtype_function($vars['type'], $vars['subtype'], $callback);
      if ($function) {
        $function($vars);
      }
    }
  }
}

// =============================================================================
// Utility

/**
 * Initiate kore standard item template variables.
 *
 * @todo It can provide override by the time it calls as well.
 */
function kitem_initiate(&$vars, $item_custom = array(), $settings_custom = array()) {
  $item = &$vars['item'];
  $settings = &$vars['settings'];

  // Defaults
  $item += array(
    'image' => 0,
    'title' => '',
    'body' => '',
    'links' => array(),
  );
  /*
  if ($item_custom) {
    $item = drupal_array_merge_deep($item, $item_custom);
  }
  */
  $settings += array(
    'image' => TRUE,
    'title' => TRUE,
    'title_tag' => 'h3',
    'body' => TRUE,
    'attributes' => array(),
  );
  /*
  if ($settings_custom) {
    $settings = drupal_array_merge_deep($settings, $settings_custom);
  }
  */

  // Add to template default attributes arrays.
  kore_attributes_process($vars, $settings['attributes']);

  // Item image.
  kitem_initiate_image($item);

  // Item Links
  $links = &$item['links'];
  if ($links) {
    foreach ($links as $com => $link) {
      if (isset($links[$com]['options'])) {
        $links[$com]['options'] += array('html' => TRUE);
      }
      else {
        $links[$com]['options'] = array('html' => TRUE);
      }
      // Use kore_image built-in link.
      if ($com == 'image') {
        $item['image']['link'] = $links[$com];
      }
    }
  }
}

/**
 * Helper function to initiate item image.
 */
function kitem_initiate_image(&$item) {
  // Simple transfer image item
  // @todo Support more, like path, url.
  $image = $item['image'];
  if (is_numeric($image)) {
    $item['image'] = array(
      'fid' => $image,
    );
  }
  else if (is_object($image)) {
    $item['image'] = array(
      'path' => $image->uri,
    );
  }
}

/**
 * Process kore standard item template variables.
 */
function kitem_process(&$vars) {
  // Template Variables
  $item = $vars['item'];
  $settings = $vars['settings'];
  $links = $item['links'];

  // $image
  $vars['image'] = NULL;
  if ($settings['image']) {
    $vars['image'] = theme('kore_image', $item['image']);
  }

  // $title, $tag
  $vars['title'] = NULL;
  $vars['tag'] = $settings['title_tag'];
  if ($settings['title']) {
    if (isset($links['title'])) {
      $vars['title'] = l($item['title'], $links['title']['path'], $links['title']['options']);
    }
    else {
      $vars['title'] = $item['title'];
    }
  }

  // $body
  $vars['body'] = NULL;
  if ($settings['body']) {
    $body = '<p>' . $item['body'] . '</p>';
    if (isset($links['body'])) {
      $vars['body'] = l($body, $links['body']['path'], $links['body']['options']);
    }
    else {
      $vars['body'] = $body;
    }
  }

  // $link_wrapper
  $vars['link_wrapper'] = NULL;
  if (isset($links['wrapper'])) {
    $link_wrapper = l('', $links['wrapper']['path'], $links['wrapper']['options']);
    $vars['link_wrapper'] = substr($link_wrapper, 0, -4);
  }
}
