<?php


/**
 *  Implements hook_field_formatter_info().
 */
function kfield_field_formatter_info() {
  kore_include('image');
  $image_default = kore_image_settings_default();
  return array(
    'kfield_kore_image' => array(
      'label' => t('Kore image'),
      'field types' => array('image'),
      'settings' => array(
        'link' => FALSE,
        'image' => $image_default,
      ),
    ),
    'kfield_list_features' => array(
      'label' => t('Features list'),
      'field types' => array('entityreference'), // @todo Support 'list_integer', 'list_text'
    ),
  );
}

/**
 *  Implements hook_field_formatter_settings_form().
 */
function kfield_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $function = __FUNCTION__ . '_' . $instance['display'][$view_mode]['type'];

  if (function_exists($function)) {
    return $function($field, $instance, $view_mode, $form, $form_state);
  }
  return NULL;
}

function kfield_field_formatter_settings_form_kfield_kore_image($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element['link'] = array(
    '#type' => 'checkbox',
    '#title' => t('Link to entity'),
    '#default_value' => $settings['link'],
  );
  kore_include('image');
  $id = array(
    $field['field_name'],
    'settings_edit_form',
    'settings',
    'image',
  );
  $element['image'] = kore_image_settings_form($id, 'fields', $settings['image']);

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function kfield_field_formatter_settings_summary($field, $instance, $view_mode) {
  $function = __FUNCTION__ . '_' . $instance['display'][$view_mode]['type'];

  if (function_exists($function)) {
    return $function($field, $instance, $view_mode);
  }
  return NULL;
}

function kfield_field_formatter_settings_summary_kfield_kore_image($field, $instance, $view_mode) {
  return $instance['display'][$view_mode]['type'];
}

/**
 *  Implements hook_field_formatter_view().
 */
function kfield_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $function = __FUNCTION__ . '_' . $display['type'];

  if (function_exists($function)) {
    return $function($entity_type, $entity, $field, $instance, $langcode, $items, $display);
  }
  return NULL;
}

function kfield_field_formatter_view_kfield_kore_image($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $settings = $display['settings'];
  if ($settings['link']) {
    $entity_uri = entity_uri($entity_type, $entity);
    $settings['image']['link']['path'] = $entity_uri['path'];
  }
  kore_include('image');
  foreach ($items as $delta => $item) {
    $vars = kore_image_prepare($item['fid'], 'image', $settings);
    $element[$delta] = array(
      '#markup' => theme('kore_image', $vars),
    );
  }

  return $element;
}

function kfield_field_formatter_view_kfield_list_features($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $selection_handler = entityreference_get_selection_handler($field, $instance, $entity_type, $entity);
  $list = options_array_flatten($selection_handler->getReferencableEntities());
  $selected = KtoolsEntityField::entityreferenceEntities($entity_type, $entity, $field['field_name']);

  $vars = array(
    'label' => NULL,
    'items' => $list,
    'items_disabled' => array_diff(array_keys($list), $selected),
  );
  $element[] = array(
    '#markup' => theme('kore_list_group', $vars),
  );

  return $element;
}
