<?php

/**
 *  Implements hook_views_data().
 */
function affilink_views_data() {
  $data['affilink'] = array(
    'table' => array(
      'group' => t('Redirect'),
      /*
      'base' => array(
        'field' => 'rid',
        'title' => t('Affilink'),
        'help' => t('Bridge between entity and redirect.'),
        'weight' => 0,
      ),
      */
      'join' => array(
        'redirect' => array(
          'left_field' => 'rid',
          'field' => 'rid'
        ),
      ),
    ),
  );

  $data['affilink']['entity_type'] = array(
    'title' => t('Entity Type'),
    'help' => t('Affilink: Entity type.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['affilink']['entity_id'] = array(
    'title' => t('Entity ID'),
    'help' => t('Affilink: Entity ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_node_nid',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'label' => t('Affilink Entity'),
      'base' => 'node',
      'base field' => 'nid',
      'relationship table' => 'affilink',
      'relationship field' => 'entity_id',
    ),
  );

  return $data;
}

/**
 *  Implements hook_views_data_alter().
 */
function affilink_views_data_alter(&$data) {
  // Provide 'affilink_node' field
  $data['redirect']['affilink_node'] = array(
    'title' => t('Affilink Node'),
    'help' => t('Node context from the redirect source.'),
    'entity_type' => 'node',
    'field' => array(
      'handler' => 'affilink_handler_field_redirect_affilink_node',
      'type' => 'node',
      /*
      'additional fields' => array(
        array(
          'source' => array(
            'table' => 'redirect',
            'field' => 'source',
          ),
        ),
      ),
      */
    ),
    'argument' => array(
      'handler' => 'affilink_handler_argument_redirect_affilink_node',
      'name field' => 'title',
      'name table' => 'node',
    ),
  );
}

function affilink_views_post_execute(&$view) {
  //dsm($view);
}
