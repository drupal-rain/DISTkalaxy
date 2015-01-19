<?php

function kore_entity_metadata_node_kdata_getter_callback($data, array $options, $name, $type, $info) {
  // @todo Make it possible to return list if needed.
  return kore_node_kdata_get_entity($data, $name);
}
