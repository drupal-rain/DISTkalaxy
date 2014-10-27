<?php

$plugin = array();

function kpane_kpane_picture_bundle_info() {
  return _kpane_plugin_bundle_info('picture');
}

function kpane_kpane_picture_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('picture');
}

function kpane_kpane_picture_template_preprocess(&$vars, $context) {
  kpane_include('image');
  $vars['picture'] = kpane_image_prepare_kore_image($vars['kpane_picture_image'][0]['fid'], 'image', $context);
}

function kpane_kpane_picture_settings_form($form_orig, &$form_state, $context) {
  $form = array();

  kpane_include('image');
  $form['image'] = kpane_image_settings_form('image', $context);

  return $form;
}

// Reset the bundle settings
function kpane_kpane_picture_reset() {
  kfield_add_field_custom('image', KPANE_ENTITY, 'picture', 'kpane_picture_image', t('Picture'));
  kpane_title_hide('picture');
}
