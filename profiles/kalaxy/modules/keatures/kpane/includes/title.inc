<?php

// Hide title in display.
function kpane_title_hide($bundle, $view_mode = 'default') {
  $field_bundle_settings = field_bundle_settings(KPANE_ENTITY, $bundle);
  $field_bundle_settings['extra_fields']['display']['title'][$view_mode]['visible'] = FALSE;
  field_bundle_settings(KPANE_ENTITY, $bundle, $field_bundle_settings);
}

function kpane_title_settings_form() {

}

function kpane_title_template_variable() {

}
