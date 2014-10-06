<?php


/**
 *  Implements hook_field_formatter_info().
 */
function kfield_field_formatter_info() {
  return array(
    'kfield_list_features' => array(
      'label' => t('Features List'),
      'field types' => array('entityreference'), // @todo Support 'list_integer', 'list_text'
    ),
  );
}

/**
 *  Implements hook_field_formatter_view().
 */
function kfield_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $selection_handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
  $list = options_array_flatten($selection_handler->getReferencableEntities());
  $selected = KtoolsEntityField::entityreferenceEntities($entity_type, $entity, $field['field_name']);

  $element = array(
    '#theme' => 'kore_list_group',
    '#label' => NULL,
    '#items' => $list,
    '#items_disabled' => array_diff(array_keys($list), $selected),

    //'#type' => 'ul',
    //'#attributes' => array(),
  );

  return $element;
}
