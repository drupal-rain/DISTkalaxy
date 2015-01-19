<?php



/**
 * $vars
 *   - id
 *   - attributes
 *   - items
 *   - type
 *   - settings
 */
function theme_carousel(&$vars) {
  $html_id = !empty($vars['id']) ? drupal_html_id($vars['id']) : drupal_html_id('carousel');
  $output = '';
  $settings = $vars['settings'];

  // Use theme_owlcarousel
  if ($vars['type'] == 'owlcarousel' && isset($vars['instance'])) {
    // Prepare items and settings.
    $items = array();
    foreach ($vars['items'] as $i => $item) {
      $items[$i]['row'] = $item;
    }
    $variables = array(
      'items' => $items,
      'settings' => array(
        'instance' => $vars['instance'],
        'attributes' => array(
          'id' => array('default' => $html_id),
        ),
      ),
    );

    // Add-on Style
    if (isset($settings['style'])) {
      if (is_array($settings['style'])) {
        $class = '';
        $i = 0;
        foreach ($settings['style'] as $style) {
          $class .= ($i > 0) ? ' ' : '';
          $class .= 'carousel-' . $style;
          $i++;
        }
      }
      else {
        $class ='carousel-' . $settings['style'];
      }
      $variables['settings']['attributes']['class'][] = $class;
    }

    $output = theme('owlcarousel', $variables);
  }
  else {
    // @todo

  }

  return $output;
}
