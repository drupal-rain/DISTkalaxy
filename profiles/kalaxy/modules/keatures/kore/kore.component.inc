<?php

// =============================================================================
// Kore Component

/**
 * Return the string callable method.
 */
function kore_component_func($component, $type, $op) {
  $class = kore_component_get_class($component, $type);
  if (method_exists($class, $op)) {
    return $class . "::" . $op;
  }
  return NULL;
}

/**
 * Try to invoke a Component::Type method.
 *
 * Useful when the method is optional.
 * One big issue is that you can't pass variables by reference in this way.
 */
function kore_component_invoke($component, $type, $op) {
  $args = func_get_args();
  unset($args[0], $args[1], $args[2]);

  $class = kore_component_get_class($component, $type);
  if (method_exists($class, $op)) {
    return call_user_func_array(array($class, $op), $args);
  }
  return NULL;
}

/**
 * Invoke the same static method of all component types operation.
 */
function kore_component_invoke_all($component, $op) {
  $args = func_get_args();
  unset($args[0], $args[1]);
  $return = array();
  $classes = kore_component_get_classes($component);
  foreach ($classes as $class) {
    if (method_exists($class, $op)) {
      $result = call_user_func_array(array($class, $op), $args);
      if (isset($result) && is_array($result)) {
        $return = array_merge_recursive($return, $result);
      }
      elseif (isset($result)) {
        $return[] = $result;
      }
    }
  }

  return $return;
}

/**
 * Invoke through classes.
 */
function kore_component_classes_invoke($classes, $op) {
  if (empty($classes)) {
    return array();
  }
  $args = func_get_args();
  unset($args[0], $args[1]);

  $return = array();
  foreach ($classes as $class) {
    if (method_exists($class, $op)) {
      $result = call_user_func_array(array($class, $op), $args);
      if (isset($result) && is_array($result)) {
        $return = array_merge_recursive($return, $result);
      }
      elseif (isset($result)) {
        $return[] = $result;
      }
    }
  }

  return $return;
}

/**
 * Center function to hold the classes with cache.
 */
function kore_component_get_classes($component) {
  $classes = &drupal_static(__FUNCTION__, array());
  if (!isset($classes[$component])) {
    $classes[$component] = \Drupal\kore\Loader::mapImplementationsAvailable($component, "\\Drupal\\kore\\$component\\$component");
  }
  return $classes[$component];
}

/**
 * Get class of the specific component type.
 */
function kore_component_get_class($component, $type) {
  $classes = kore_component_get_classes($component);
  return $classes[$type];
}

// =============================================================================
// Kore Component Depends on Entity

/**
 * @todo A better cache?
 * @consider Turn to call_user_func(), so it can support any hierarchy? For now, just make it suit entity need first.
 * @consider Should I make it support view mode as well?
 */
function kore_component_entity_get_classes($component, $entity_type = NULL, $bundle = NULL) {
  $classes = &drupal_static(__FUNCTION__, array());
  $classes_return = &$classes[$component];

  // Collect the classes
  if (!isset($classes_return)) {
    // Prepare a skeleton is a must for later inheritance
    $classes_return = kore_entity_info_array();
    $classes_component = kore_component_get_classes($component);
    foreach ($classes_component as $type => $class) {
      $info = explode('__', $type);
      // 1 = All, 2 = Entity type, 3 = Bundle, 4 = View mode
      if (count($info) == 1) {
        $classes_return[$info[0]] = $class;
      }
      else {
        drupal_array_set_nested_value($classes_return, $info, $class);
      }
    }
    // Inheritance, child will have all the parent properties
    kore_array_inherit($classes_return);
  }

  // Get the correct result
  $return = drupal_array_get_nested_value($classes_return, kore_array_create($entity_type, $bundle));
  return $return;
}
