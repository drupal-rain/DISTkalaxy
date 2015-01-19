<?php

class views_plugin_style_blockgrid extends views_plugin_style {

  function option_definition() {
    $options = parent::option_definition();

    foreach (kore_foundation_sizes() as $size) {
      if ($size == 'small') {
        $options[$size] = array('default' => '3');
      }
      else {
        $options[$size] = array('default' => '');
      }
    }

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    foreach (kore_foundation_sizes() as $size) {
      $form[$size] = array(
        '#type' => 'textfield',
        '#title' => $size,
        '#default_value' => $this->options[$size],
      );
    }
  }

}
