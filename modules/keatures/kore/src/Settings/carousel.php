<?php

namespace Drupal\kore\Settings;

class carousel extends Settings_Abstract {

  public static function getDefault() {
    return array(
      'instance' => NULL,
      'id' => NULL,
    );
  }

  public static function buildform($id, $settings, $wrap = FALSE) {
    $form_return = array();
    $form = &Helper::prepareForm($id, $form_return);
    $settings = Helper::prepareSettings($id, $settings, self::getDefault());

    // Initiate form
    $form = array(
      '#type' => 'fieldset',
      '#title' => t('Carousel'),
      '#collapsible' => TRUE,
      '#tree' => TRUE,
    );

    $form['instance'] = array(
      '#type' => 'select',
      '#title' => t('Settings Group'),
      '#description' => t('Select the settings group to apply.'),
      '#default_value' => $settings['instance'],
      '#options' => owlcarousel_instance_callback_list(),
    );

    $form['id'] = array(
      '#type' => 'textfield',
      '#title' => t('Id'),
      '#default_value' => $settings['id'],
    );

    return $form_return;
  }

  public static function buildProduct($id, $settings, $context = NULL) {
    $settings = Helper::prepareSettings($id, $settings, self::getDefault());

    return array(
      '#theme' => 'carousel',
      '#items' => $context['items'],
      '#id' => $settings['id'],
      '#instance' => $settings['instance'],
    );
  }

}
