<?php

// @deprecating
// or use as wrapper like this

function kpane_image_prepare_kore_image($image, $id, $context) {
  $bundle = $context->bundle;
  $settings = $context->settings[$bundle];

  kore_include('image');
  return kore_image_prepare($image, $id, $settings);
}

// Common usage $form['image'] = kpane_image_settings_form('image', $context);
function kpane_image_settings_form($id, $context) {
  $bundle = $context->bundle;
  $settings = $context->settings[$bundle];
  $prefix = "settings[$bundle]";

  kore_include('image');
  return kore_image_settings_form($id, $prefix, $settings);
}
