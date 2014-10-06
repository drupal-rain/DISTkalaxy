<?php

class affilink_handler_field_redirect_affilink_node extends entity_views_handler_field_entity {

  public function query() {
    parent::query();
    $this->query->add_field('redirect', 'source', 'source');
  }

  // @todo Support custom pattern.
  public function get_value($values, $field = NULL) {
    $source = $values->source;

    // Assume '/goto/' pattern.
    if (strpos($source, '/goto') !== FALSE) {
      $path = substr($source, 0, strpos($source, '/goto'));
      // System menu path or alias
      if (strpos($path, 'node/') !== 0) {
        $path_node = drupal_get_normal_path($path);
      }
      else {
        $path_node = $path;
      }
      // @todo Better solution.
      $match = drupal_match_path($path_node, 'node/*');
      if ($match) {
        $path_node_arr = explode('/', $path_node);
        return node_load($path_node_arr[1]);
      }
    }

    return NULL;
  }

}
