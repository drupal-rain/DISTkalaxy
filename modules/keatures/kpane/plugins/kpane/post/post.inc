<?php

$plugin = array();

function kpane_kpane_post_bundle_info() {
  return _kpane_plugin_bundle_info('content');
}

function kpane_kpane_post_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('content');
}
