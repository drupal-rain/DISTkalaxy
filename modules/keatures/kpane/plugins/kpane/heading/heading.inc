<?php

$plugin = array();

function kpane_kpane_heading_bundle_info() {
  return _kpane_plugin_bundle_info('heading');
}

function kpane_kpane_heading_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('heading');
}

function kpane_kpane_heading_template_preprocess(&$vars, $entity) {
  $vars['tag'] = $entity->settings['heading']['tag'];
}

function kpane_kpane_heading_settings_form($form_orig, &$form_state, $entity) {
  $form = array();
  $tags = array('h1', 'h2', 'h3', 'h4', 'h5', 'h6');
  $form['tag'] = array(
    '#type' => 'select',
    '#title' => t('Heading Tag'),
    '#options' => array_combine($tags, $tags),
    //'#default_value' => isset($entity->settings['heading']['tag']) ? $entity->settings['heading']['tag'] : 'h2',
    '#default_value' => kpane_settings_default_value($entity, 'tag', 'h2'),
  );

  return $form;
}
