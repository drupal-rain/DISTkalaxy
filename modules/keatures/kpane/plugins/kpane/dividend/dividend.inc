<?php

$plugin = array();

function kpane_kpane_dividend_bundle_info() {
  return _kpane_plugin_bundle_info('dividend');
}

function kpane_kpane_dividend_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('dividend');
}
