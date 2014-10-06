<?php

$plugin = array();

function kpane_kpane_code_bundle_info() {
  return _kpane_kpane_bundle_info('code');
}

function kpane_kpane_code_theme_registry($existing, $type, $theme, $path) {
  return _kpane_kpane_theme_registry('code');
}

function kpane_kpane_code_template_preprocess(&$vars, $entity) {
}
