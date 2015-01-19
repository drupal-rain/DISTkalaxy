<?php

/**
 * Generate 'links' element for menu_primary_local_tasks().
 *
 * @see theme_links().
 */
function menu_primary_local_tasks_links() {
  $tasks = menu_primary_local_tasks();
  $links = array();
  if ($tasks) {
    foreach ($tasks as $delta => $task) {
      $links[$delta] = $task['#link'];
    }
  }

  return $links;
}
