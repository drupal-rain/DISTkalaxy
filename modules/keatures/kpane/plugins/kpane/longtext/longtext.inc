<?php

$plugin = array();

function kpane_kpane_longtext_bundle_info() {
  return _kpane_kpane_bundle_info('longtext');
}

function kpane_kpane_longtext_theme_registry($existing, $type, $theme, $path) {
  return _kpane_kpane_theme_registry('longtext');
}
