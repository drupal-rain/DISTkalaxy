<?php

namespace Drupal\kore\Settings;

class image extends Settings_Abstract {

  public static function getDefault() {
    $picture_mapping_options = picture_get_mapping_options();
    $picture_mapping = (!empty($picture_mapping_options)) ? key(picture_get_mapping_options()) : '';
    return array(
      'image_style' => 'picture',
      'picture_mapping' => $picture_mapping,
      'fallback_image_style' => '',
      'responsive' => TRUE,
    );
  }

  /**
   * Settings: 'image_style', 'picture_mapping', 'fallback_image_style', 'responsive'.
   */
  public static function buildForm($id, $settings, $wrap = FALSE) {
    // Initiate
    $form_return = array();
    $form = &Helper::prepareForm($id, $form_return);
    $input_id = Helper::prepareInputId($id, $wrap, 'image_style');
    $settings = Helper::prepareSettings($id, $settings, self::getDefault());

    // Initiate form
    $form = array(
      '#type' => 'fieldset',
      '#title' => t('Image'),
      '#collapsible' => TRUE,
      '#tree' => TRUE,
    );

    // Type
    $image_styles = image_style_options(FALSE);
    $image_styles_options = array('picture' => t('- Picture -')) + $image_styles;
    $form['image_style'] = array(
      '#type' => 'select',
      '#title' => t('Image Style'),
      '#options' => $image_styles_options,
      '#default_value' => $settings['image_style'],
      '#empty_value' => 'none',
    );

    // Picture
    $options = picture_get_mapping_options();
    if ($options) {
      $form['picture_mapping'] = array(
        '#title' => t('Picture mapping'),
        '#type' => 'select',
        '#default_value' => isset($settings['picture_mapping']) ? $settings['picture_mapping'] : '',
        '#required' => TRUE,
        '#options' => picture_get_mapping_options(),
      );
    }
    // No picture mappings.
    else {
      $form['picture_mapping'] = array(
        '#title' => t('Picture mapping'),
        '#type' => 'item',
        '#markup' => t(
          'There are no picture groups defined. !create_link.',
          array('!create_link' => l(t('Create a picture mapping'), 'admin/config/media/picture/add'))
        )
      );
    }

    $form['fallback_image_style'] = array(
      '#title' => t('Fallback image style'),
      '#type' => 'select',
      '#default_value' => $settings['fallback_image_style'],
      '#empty_option' => t('Automatic'),
      '#options' => $image_styles + array(
          PICTURE_EMPTY_IMAGE => t('Empty image'),
          PICTURE_ORIGINAL_IMAGE => t('Original image'),
        ),
    );

    $picture_states = array(
      '#states' => array(
        'visible' => array(
          $input_id => array('value' => 'picture'),
        ),
      ),
    );
    $form['picture_mapping'] += $picture_states;
    $form['fallback_image_style'] += $picture_states;

    // Responsive
    $form['responsive'] = array(
      '#type' => 'checkbox',
      '#title' => t('Responsive to parent'),
      '#default_value' => $settings['responsive'],
    );

    return $form_return;
  }

  public static function buildSummary($id, $settings) {

  }

  public static function buildProduct($id, $settings, $context = NULL) {
    $settings = Helper::prepareSettings($id, $settings, self::getDefault());

    // Renderable element
    $element = array(
      '#theme' => 'img',
      '#file' => $context['file'],
      '#responsive' => $settings['responsive'],
    );
    if (isset($settings['link'])) {
      $element['#link'] = $settings['link'];
      unset($settings['link']);
    }
    if ($settings['image_style'] != 'none') {
      if ($settings['image_style'] != 'picture') {
        $element['#style_name'] = $settings['image_style'];
      }
      else {
        $element += array(
          '#type' => 'picture',
          '#picture' => $settings,
        );
      }
    }

    return $element;
  }

}
