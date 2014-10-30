<?php

function kore_image_prepare($image, $id, $settings) {
  if (is_array($id)) {
    foreach ($id as $child) {
      $settings = $settings[$child];
    }
  }
  else {
    $settings = $settings[$id];
  }

  // Renderable element
  $element = array(
    '#theme' => 'kore_image',
    '#fid' => $image,
    '#responsive' => $settings['responsive'],
  );
  if ($settings['image_style'] != 'none') {
    if ($settings['image_style'] != 'picture') {
      $element['#style_name'] = $settings['image_style'];
    }
    else {
      $element += array(
        '#type' => 'picture',
        '#picture' => $settings,
      );
    }
  }

  return $element;
}

function kore_image_settings_default() {
  $picture_mapping_options = picture_get_mapping_options();
  $picture_mapping = (!empty($picture_mapping_options)) ? key(picture_get_mapping_options()) : '';
  return array(
    'image_style' => 'picture',
    'picture_mapping' => $picture_mapping,
    'fallback_image_style' => '',
    'responsive' => TRUE,
  );
}

function kore_image_settings_form($id, $prefix, $settings) {
  $index = '';
  $input_id = ':input[name="' . $prefix;
  $form = array();
  if (is_array($id)) {
    foreach ($id as $child) {
      $form = &$form[$child];
      $index = $child;
      $input_id .= '[' . $child . ']';
    }
  }
  else {
    $form = &$form[$id];
    $index = $id;
    $input_id .= '[' . $id . ']';
  }
  $input_id .= '[image_style]"]';


  // Initiate
  if (is_array($id)) {
    foreach ($id as $child) {
      $settings = $settings[$child];
    }
  }
  else {
    $settings = $settings[$id];
  }
  if (!isset($settings)) {
    $settings = array();
  }
  $settings += kore_image_settings_default();

  $form = array(
    '#type' => 'fieldset',
    '#title' => t('Image'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
  );

  // Type
  $image_styles = image_style_options(FALSE);
  $image_styles_options = array('none' => t('<< None >>'), 'picture' => t('<< Picture >>')) + $image_styles;
  $form['image_style'] = array(
    '#type' => 'select',
    '#title' => t('Image Style'),
    '#options' => $image_styles_options,
    '#default_value' => $settings['image_style'],
  );

  // Picture
  $options = picture_get_mapping_options();
  if ($options) {
    $form['picture_mapping'] = array(
      '#title' => t('Picture mapping'),
      '#type' => 'select',
      '#default_value' => isset($settings['picture_mapping']) ? $settings['picture_mapping'] : '',
      '#required' => TRUE,
      '#options' => picture_get_mapping_options(),
    );
  }
  // No picture mappings.
  else {
    $form['picture_mapping'] = array(
      '#title' => t('Picture mapping'),
      '#type' => 'item',
      '#markup' => t(
        'There are no picture groups defined. !create_link.',
        array('!create_link' => l(t('Create a picture mapping'), 'admin/config/media/picture/add'))
      )
    );
  }

  $form['fallback_image_style'] = array(
    '#title' => t('Fallback image style'),
    '#type' => 'select',
    '#default_value' => $settings['fallback_image_style'],
    '#empty_option' => t('Automatic'),
    '#options' => $image_styles + array(
        PICTURE_EMPTY_IMAGE => t('Empty image'),
        PICTURE_ORIGINAL_IMAGE => t('Original image'),
      ),
  );

  $picture_states = array(
    '#states' => array(
      'visible' => array(
        $input_id => array('value' => 'picture'),
      ),
    ),
  );
  $form['picture_mapping'] += $picture_states;
  $form['fallback_image_style'] += $picture_states;

  // Responsive
  $form['responsive'] = array(
    '#type' => 'checkbox',
    '#title' => t('Responsive to parent'),
    '#default_value' => $settings['responsive'],
  );

  return $form;
}
