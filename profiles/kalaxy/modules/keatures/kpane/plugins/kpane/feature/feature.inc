<?php

$plugin = array();

function kpane_kpane_feature_bundle_info() {
  return _kpane_kpane_bundle_info('feature');
}

function kpane_kpane_feature_theme_registry($existing, $type, $theme, $path) {
  return _kpane_kpane_theme_registry('feature');
}
