<?php

$plugin = array(
  'css' => 'story.css',
  'subtypes' => array(
    'split' => array(),
    'combine' => array(),
  ),
  'display' => array(
    'split' => array(
      'label' => t('Split'),
      'style' => array(
        'left' => array(
          'label' => t('Media on left')
        ),
        'top' => array(
          'label' => t('Media on top')
        ),
        'right' => array(
          'label' => t('Media on right')
        ),
        'bottom' => array(
          'label' => t('Media on bottom')
        ),
      ),
    ),
    'combine' => array(
      'label' => t('Combine'),
      'style' => array(),
    ),
  ),
);

function kpane_kpane_story_template_preprocess(&$vars, $context) {
  // dsm($vars);
  $vars['theme_hook_suggestions'][] = 'fieldable_panels_pane__story_' . $context->settings['story']['mode'];
  $vars['media'] = $vars['content']['kpane_story_media'];
  $vars['media']['#label_display'] = 'hidden';
  $vars['body'] = $vars['content']['kpane_story_body'];
  $vars['body']['#label_display'] = 'hidden';
  switch ($context->settings['story']['mode']) {
    case 'split':
      $vars['media_size'] = $context->settings['story']['split']['media_size'];
      $vars['body_size'] = $context->settings['story']['split']['body_size'];
      switch ($context->settings['story']['split']['media_position']) {
        case 'left':
          $vars['media_position'] = 'pull-left';
          break;
        case 'right':
          $vars['media_position'] = 'pull-right';
          break;
      }
      break;
    case 'combine':
      break;
  }
}

function kpane_kpane_story_settings_form($form_orig, &$form_state, $context) {
  $form = array();

  $form['mode'] = array(
    '#type' => 'select',
    '#title' => t('Mode'),
    '#options' => array(
      'split' => t('Split'),
      'combine' => t('Combine'),
    ),
    '#default_value' => kpane_settings_default_value($context, 'mode', 'split'),
  );

  // Split
  $form['split'] = array(
    '#type' => 'fieldset',
    '#title' => t('Split'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="settings[story][mode]"]' => array('value' => 'split'),
      ),
    ),
    '#attributes' => array(
      'class' => array('form-inline'),
    ),
  );
  $form['split']['media_position'] = array(
    '#type' => 'select',
    '#title' => t('Media position'),
    '#options' => array(
      'left' => t('Left'),
      'top' => t('Top'),
      'right' => t('Right'),
      'bottom' => t('Bottom'),
    ),
    '#default_value' => kpane_settings_default_value($context, array('split', 'media_position'), 'left'),
  );
  $form['split']['media_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Media size'),
    '#size' => 2,
    '#default_value' => kpane_settings_default_value($context, array('split', 'media_size'), 4),
  );
  $form['split']['body_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Body size'),
    '#size' => 2,
    '#default_value' => kpane_settings_default_value($context, array('split', 'body_size'), 8),
  );

  // Combine
  $form['combine'] = array(
    '#type' => 'fieldset',
    '#title' => t('Combine'),
    '#collapsible' => TRUE,
    '#tree' => TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="settings[story][mode]"]' => array('value' => 'combine'),
      ),
    ),
  );
  $form['combine']['media_position'] = array(
    '#type' => 'select',
    '#title' => t('Media position'),
    '#options' => array(
      'left' => t('Left'),
      'top_left' => t('Top left'),
      'top' => t('Top'),
      'top_right' => t('Top right'),
      'right' => t('Right'),
      'bottom_right' => t('Bottom right'),
      'bottom' => t('Bottom'),
      'bottom_left' => t('Bottom left'),
      'center' => t('Center'),
    ),
    '#default_value' => kpane_settings_default_value($context, array('combine', 'media_position'), 'left'),
  );

  // Image
  /*
  kpane_include('image');
  $form['image'] = kpane_image_settings_form('image', $context);
  */

  return $form;
}
