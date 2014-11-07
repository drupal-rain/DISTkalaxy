<?php

function hook_kpane_settings_form_alter(&$form, &$form_state) {
  $entity = $form_state['entity'];
}

function hook_kpane_KPANE_info_alter(&$info) {
  $info['classes']['abc'] = '.abc';
}

function hook_kpane_KPANE_settings_form_alter(&$form, &$form_state) {
  $entity = $form_state['entity'];
}

function hook_kpane_KPANE_template_preprocess_alter(&$vars, $context) {

}

function hook_kpane_KPANE_template_process_alter(&$vars, $context) {

}
