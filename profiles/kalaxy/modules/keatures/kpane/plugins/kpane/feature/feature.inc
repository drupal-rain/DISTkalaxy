<?php

$plugin = array(
  'css' => 'feature.css',
  'display' => array(
    'right' => array(
      'label' => t('Picture (Right)')
    ),
  ),
);

// Prepare variables for template:
// * $intro
// * $picture
// * $items
function kpane_kpane_feature_template_preprocess(&$vars, $context) {
  // Narrow mode
  if ($context->settings['feature']['narrow']) {
    $vars['classes_array'][] = 'narrow';
  }
  // Intro
  if ($context->kpane_feature_intro) {
    $vars['intro'] = field_view_value(KPANE_ENTITY, $context, 'kpane_feature_intro',
      $vars['kpane_feature_intro'][0], array(
        'label' => 'hidden',
      )
    );
  }
  // Image
  kpane_include('image');
  $vars['picture'] = kpane_image_prepare_kore_image($vars['kpane_feature_image'][0]['fid'], 'image', $context);
  // Items
  $items = kpane_kpane_feature_items($vars['kpane_feature_items']);
  $vars['items_first'] = $items['first'];
  $vars['items_second'] = $items['second'];
}

function kpane_kpane_feature_settings_form($form_orig, &$form_state, $context) {
  $form = array();

  // Narrow Mode
  $form['narrow'] = array(
    '#type' => 'checkbox',
    '#title' => t('Narrow Mode'),
    '#description' => t('Better display style for narrow column.'),
    '#default_value' => kpane_settings_default_value($context, 'narrow', FALSE),
  );

  // Image
  // Picture Settings
  /*
  kpane_include('picture');
  $form['picture'] = kpane_picture_field_settings_form('picture', $context, 'kpane_feature_image');
  */
  kpane_include('image');
  $form['image'] = kpane_image_settings_form('image', $context);

  return $form;
}

function kpane_kpane_feature_reset() {
  $entity_type = KPANE_ENTITY;
  $bundle = 'feature';
  ctools_include('text', 'kfield');
  kfield_text_add_longtext_default($entity_type, $bundle, 'kpane_feature_intro', t('Intro'));
  ctools_include('image', 'kfield');
  kfield_image_add_image_default($entity_type, $bundle, 'kpane_feature_image', t('Picture'));
  kfield_add_field_default('double_field', $entity_type, $bundle, 'kpane_feature_items', t('Items'));
  $items_base = array(
    'settings' => array(
      'second' => array(
        'type' => 'text',
      ),
    ),
    'cardinality' => FIELD_CARDINALITY_UNLIMITED,
  );
  kfield_mod_field_base('kpane_feature_items', $items_base);
  $items_instance = array(
    'widget' => array(
      'type' => 'textfield_&_textarea',
      'module' => 'double_field',
    ),
  );
  kfield_mod_field_instance($entity_type, $bundle, 'kpane_feature_items', $items_instance);
}

// =============================================================================
// Theme Functions

// Theme items.
function kpane_kpane_feature_items($items) {
  $output = array(
    'first' => '',
    'second' => '',
  );

  $amount = count($items);
  $amount_first = ceil($amount / 2.0);

  for ($i = 0; $i < $amount_first; $i++) {
    $output['first'] .= kpane_kpane_feature_item($items[$i]);
  }
  for ($i = $amount_first; $i < $amount; $i++) {
    $output['second'] .= kpane_kpane_feature_item($items[$i]);
  }

  return $output;
}

// Theme single item.
// @todo Try set each item with bootstrap grid and let the browser sort them.
function kpane_kpane_feature_item($item) {
  $output = '<div class="feature-item">';
  $output .= "<h3>{$item['first']}</h3>";
  $output .= "<div>{$item['second']}</div>";
  $output .= '</div>';

  return $output;
}
