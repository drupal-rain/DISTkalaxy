<?php

/**
 * $variables
 *   - id
 *   - trigger
 *   - options
 *     data-options
 *   - attributes
 *   - type
 *     * links
 *     * content
 *     * custom
 *   - content
 *   - content_attributes
 */
function theme_dropdown($vars) {
  // Trigger
  $id = isset($vars['id']) ? $vars['id'] : 'dropdown';
  $html_id = drupal_html_id($id);
  if ($vars['options']) {
    $options = '';
    $i = 0;
    foreach ($vars['options'] as $key => $value) {
      if ($i > 0) {
        $options .= '; ';
      }
      $options .= $key . ':' . $value;
      $i++;
    }
    $vars['attributes']['data-options'] = $options;
  }
  $vars['attributes']['aria-controls'] = $html_id;
  // Default attributes
  $vars['attributes'] += array(
    'aria-expanded' => 'false',
  );
  $vars['attributes']['aria-expanded'] = 'false';
  $output = '<a href="#" data-dropdown="' . $html_id . '"' . drupal_attributes($vars['attributes']) . '>';
  $output .= $vars['trigger'];
  $output .= '</a>';

  // Content
  $vars['content_attributes']['id'] = $html_id;
  $vars['content_attributes']['class'][] = 'f-dropdown';
  $vars['content_attributes'] += array(
    'data-dropdown-content' => '',
    'tabindex' => '-1',
    'aria-hidden' => 'true',
  );
  switch ($vars['type']) {
    case 'links':
      $variables = array(
        'links' => $vars['content'],
        'attributes' => $vars['content_attributes'],
      );
      $output .= theme('links', $variables);
      break;
    case 'content':
      $vars['content_attributes']['class'][] = 'content';
      $output .= '<div' . drupal_attributes($vars['content_attributes']) . '>';
      $output .= drupal_render($vars['content']);
      $output .= '</div>';
      break;
    case 'custom':
      $output .= drupal_render($vars['content']);
      break;
  }

  return $output;
}
