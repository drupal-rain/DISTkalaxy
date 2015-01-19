<?php

/**
 * Helper to create array, usually for array parents.
 */
function kore_array_create() {
  $return = array();
  $args = func_get_args();
  foreach ($args as $arg) {
    if (isset($arg)) {
      $return[] = $arg;
    }
  }

  return $return;
}

/**
 * Child element array will have all parent's properties.
 */
function kore_array_inherit(&$arr) {
  $arr_root = array_filter($arr, 'kore_array_filter_array');
  foreach ($arr as $key => $item) {
    if (is_array($item)) {
      $arr[$key] = array_merge($arr_root, $item);
      kore_array_inherit($arr[$key]);
    }
  }
}

/**
 * It's used to override ancestor's doing.
 */
function kore_array_override($arr) {
  $it = new RecursiveIteratorIterator(new RecursiveArrayIterator($arr));
  $result = iterator_to_array($it);

  return $result;
}

function kore_array_override_multiple() {
  $args = func_get_args();
  $arr = call_user_func_array('drupal_array_merge_deep', $args);
  $it = new RecursiveIteratorIterator(new RecursiveArrayIterator($arr));
  $result = iterator_to_array($it);

  return $result;
}

/**
 * Callback to filter out array children.
 */
function kore_array_filter_array($value) {
  if (is_array($value)) {
    return FALSE;
  }
  return TRUE;
}