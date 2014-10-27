<?php

/**
 * Implements hook_preprocess_HOOK().
 */
/*
function kore_preprocess_kitem(&$vars) {
  $id = $vars['type'];
  if ($id == 'default') {
    return;
  }

  $callback = kitem_plugin_get_function($id, 'preprocess');
  if ($callback) {
    $callback($vars);
  }

  kitem_plugin_attach($id);
}
*/

/**
 * Implements hook_process_HOOK().
 */
/*
function kore_process_kitem(&$vars) {
  if ($vars['type'] == 'default') {
    return;
  }
  $callback = kitem_plugin_get_function($vars['type'], 'process');
  if ($callback) {
    $callback($vars);
  }
}
*/

function kitem_theme_registry($existing, $type, $theme, $path) {
  $kitems = kitem_plugin_get_plugins();
  $kitems_registry = array();
  foreach ($kitems as $id => $plugin) {
    $kitems_registry['kitem__' . $id] = array(
      'base hook' => 'kitem',
      'path' => $plugin['path'],
      'template' => $id,
    );
    // @todo Support function callback to get subtypes (Maybe).
    if (!empty($plugin['subtypes']) && is_array($plugin['subtypes'])) {
      foreach ($plugin['subtypes'] as $subtype => $subtype_info) {
        $kitems_registry['kitem__' . $id . '__' . $subtype] = array(
          'base hook' => 'kitem',
          'path' => $plugin['path'],
          'template' => $id . '-' . strtr($subtype, '_', '-'),
        );
      }
    }
  }

  return $kitems_registry;
}

/**
 * Wrapper for theme() to use the correct hook.
 */
function kitem_theme(&$vars) {
  $hook = 'kitem';
  $hooks = array($hook);
  if (!empty($vars['type']) && $vars['type'] != 'default') {
    $hook .= '__' . $vars['type'];
    array_unshift($hooks, $hook);
    if (!empty($vars['subtype'])) {
      $hook .= '__' . $vars['subtype'];
      array_unshift($hooks, $hook);
    }
  }

  return theme($hooks, $vars);
}

// =============================================================================
// Plugin

/**
 * Wrapper for ctools_get_plugins() to get kpane plugins.
 */
function kitem_plugin_get_plugins($id = NULL) {
  ctools_include('plugins');
  $plugins = ctools_get_plugins('kore', 'kitem', $id);

  return $plugins;
}

/**
 * Get optional callback function of plugin.
 */
function kitem_plugin_get_function($id, $callback) {
  ctools_include('plugins');
  $function = ctools_plugin_load_function('kore', 'kitem', $id, $callback);
  // Allow to use default name of callback: MODULE_kitem_PLUGIN_CALLBACK().
  if (!$function) {
    $plugin = ctools_get_plugins('kore', 'kitem', $id);
    $function_tmp = $plugin['module'] . '_kitem_' . $id . '_' . str_replace(' ', '_', $callback);
    if (function_exists($function_tmp)) {
      $function = $function_tmp;
    }
  }

  return $function;
}

function kitem_plugin_get_subtype_function($type, $subtype, $callback) {
  $plugin = ctools_get_plugins('kore', 'kitem', $type);
  $function = $plugin['module'] . '_kitem_' . $type . '_' . $subtype . '_' . str_replace(' ', '_', $callback);
  if (function_exists($function)) {
    return $function;
  }

  return FALSE;
}

/**
 * Attach css, js, etc.
 */
// @todo Finish the design and work.
function kitem_plugin_attach($id) {
  $plugin = kitem_plugin_get_plugins($id);
  // @todo Support other input format?
  if (isset($plugin['css'])) {
    drupal_add_css($plugin['path'] . '/' . $plugin['css']);
  }
  if (isset($plugin['js'])) {
    drupal_add_js($plugin['path'] . '/' . $plugin['js']);
  }
}

// =============================================================================
// Utility

function kitem_list_options() {
  $plugins = kitem_plugin_get_plugins();
  $options = array(
    'default' => 'default',
  );
  foreach ($plugins as $id => $plugin) {
    $options[$id] = $id;
  }

  return $options;
}
