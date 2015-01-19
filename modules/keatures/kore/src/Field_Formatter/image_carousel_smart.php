<?php

/**
 * @file A field formatter for image field.
 *
 * There are three ways of output:
 *   - If there is no file, print none.
 *   - If there is a single image, just print it.
 *   - If more than one image, initiate a carousel.
 */

namespace Drupal\kore\Field_Formatter;

use Drupal\kore\Settings;

class image_carousel_smart extends Field_Formatter_Abstract {

  public static function info() {
    $settings = array();
    $settings['image'] = Settings\image::getDefault();
    $settings['carousel'] = Settings\carousel::getDefault();
    return array(
      'image_carousel_smart' => array(
        'label' => t('Smart carousel'),
        'field types' => array('image'),
        'settings' => $settings,
      ),
    );
  }

  public static function settings_form($field, $instance, $view_mode, $form, &$form_state) {
    $settings = $instance['display'][$view_mode]['settings'];

    $element = array();
    $wrap = FALSE;
    // Field context
    if ($form_state['formatter_settings_edit']) {
      $wrap = TRUE;
    }

    $element += Settings\carousel::buildForm('carousel', $settings, $wrap);
    $element += Settings\image::buildForm('image', $settings, $wrap);

    return $element;
  }

  /*
  public static function settings_summary($field, $instance, $view_mode) {
    return 'Summary';
  }
  */

  public static function view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
    $size = count($items);
    // None
    if ($size == 0) {
      return NULL;
    }
    $settings = $display['settings'];

    // Single image
    if ($size == 1) {
      $element[0] = Settings\image::buildProduct('image', $settings, array('file' => (object)$items[0]));
    }
    // Carousel
    else {
      $items_carousel = array();
      foreach ($items as $delta => $item) {
        $item_element = Settings\image::buildProduct('image', $settings, array('file' => (object)$item));
        $items_carousel[$delta] = drupal_render($item_element);
      }
      $element[0] = Settings\carousel::buildProduct('carousel', $settings, array('items' => $items_carousel));
    }

    return $element;
  }

}
