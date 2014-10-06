<?php

/**
 * Implements hook_views_plugins().
 */
function knews_views_plugins() {
  $module_path = drupal_get_path('module', 'knews') . '/views';

  /*
  return array(
    'style' => array(
      'knews_views_plugin_style' => array(
        'title' => t('Bootstrap Carousel'),
        'help' => t('Bootstrap Carousel Style'),
        'path' => $module_path . '/plugins/carousel',
        'handler' => 'ViewsBootstrapCarouselPluginStyle',
        'parent' => 'default',
        'theme' => 'knews_views_plugin_style',
        'theme path' => $module_path . '/templates/carousel',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
  */
}

function knews_views_pre_render(&$view) {
  if ($view->name == 'knews_category_navigation') {

  }
}
