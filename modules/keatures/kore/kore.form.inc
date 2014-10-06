<?php

// A simple additional form submit to redirect override.
// Usage:
// $form['#submit'][] = 'kore_form_submit_redirect';
// $form_state['redirect_kore'] = $path_redirect;
function kore_form_submit_redirect($form, &$form_state) {
  $form_state['redirect'] = $form_state['redirect_kore'];
}

// Simple redirect to parent directory path.
function kore_form_submit_redirect_up($form, &$form_state) {
  $path = current_path();
  $form_state['redirect'] = substr($path, 0, strrpos($path, '/'));
}
