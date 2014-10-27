<?php

$plugin = array();

function kpane_kpane_quote_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('quote');
}

function kpane_kpane_quote_template_preprocess(&$vars, $entity) {
  $lang = entity_language('fieldable_panels_pane', $entity);
  $vars['quote'] = field_view_value('fieldable_panels_pane', $entity, 'field_pane_quote_body',
    $entity->field_pane_quote_body[$lang][0],
    array('label' => 'hidden')
  );
}
