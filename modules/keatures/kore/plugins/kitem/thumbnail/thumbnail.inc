<?php

$plugin = array(
  'label' => t('Thumbnail'),
  'subtypes' => array(
    'hovercard' => array(), // @todo Design subtype info.
  ),
);

function kore_kitem_thumbnail_preprocess(&$vars) {
  $item = &$vars['item'];
  $settings = &$vars['settings'];

  if (!isset($settings['grid'])) {
    $settings['grid'] = array();
  }

  // Add class to image
  $item['image']['attributes']['class'][] = 'img-responsive';

  // Grid
  // Use grid in $item would allow variant width for each item if with override settings.
  // Seems it's better than calculate the same grid size in $items namespace.
  foreach ($settings['grid'] as $size => $grid) {
    $vars['classes_array'][] = 'col-' . $size . '-' . floor(KALATHEME_GRID_SIZE / $grid);
  }
}

function kore_kitem_thumbnail_hovercard_preprocess(&$vars) {

}
