<?php

$plugin = array(
  'css' => 'posts.css',
  'classes' => array(
    'posts-hover-highlight' => '.posts-hover-highlight',
  ),
  'display' => array(
    'media' => array(
      'label' => t('Media'),
    ),
    'thumbnail' => array(
      'label' => t('Thumbnail'),
    ),
    'carousel' => array(
      'label' => t('Carousel'),
    ),
  ),
);

function kpane_kpane_posts_bundle_info() {
  return _kpane_plugin_bundle_info('posts');
}

function kpane_kpane_posts_theme_registry($existing, $type, $theme, $path) {
  return _kpane_plugin_theme_registry('posts');
}

// @todo Consider 'access'.
function kpane_kpane_posts_template_preprocess(&$vars, $context) {
  $display = $context->settings['theme']['display'];
  $context_settings = $context->settings['posts'];
  // If user has no access, it will not populate.
  $variables = array(
    'items' => array(),
    'settings' => array(),
    'attributes' => array(),
    'context' => $context,
  );
  if ($display != 'none') {
    _kpane_kpane_posts_template_preprocess($variables, $vars, $context);
  }
  $settings = &$variables['settings'];

  switch ($display) {
    case 'media':
      $vars['classes_array'][] = 'posts-media';
      $settings['image_position'] = $context_settings['media']['image_position'];
      $vars['posts'] = theme('kore_media', $variables);
      break;
    case 'thumbnail':
      $vars['classes_array'][] = 'posts-thumbnail';
      $settings['grid'] = $context_settings['thumbnail']['grid'];
      if ($context_settings['thumbnail']['height_equal']) {
        $settings['attributes']['classes_array'][] = 'equal-height';
      }
      $vars['posts'] = theme('kore_thumbnail', $variables);
      break;
    case 'carousel':
      $vars['classes_array'][] = 'posts-carousel';
      $settings['kitem'] = $context_settings['carousel']['kitem'];
      $settings['owlcarousel'] = $context_settings['carousel']['owlcarousel'];
      $settings['id'] = !empty($context_settings['carousel']['id']) ? $context_settings['carousel']['id'] : 'carousel';
      $vars['posts'] = theme('kore_carousel', $variables);
      break;
  }
}

function kpane_kpane_posts_settings_form($form_orig, &$form_state, $context) {
  $form = array();
  $plugin = kpane_plugin_get_plugins($context->bundle);

  // Call helper which could handler plugin theme info
  _kpane_plugin_settings_form($form, $form_state, $context);

  // Global Settings
  // @todo Individual override.

  // Components Display
  $components = array('image', 'title', 'body');
  $form['display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display'),
    '#collapsible' => TRUE,
    //'#collapsed' => TRUE,
    '#attributes' => array(
      'class' => array('form-inline'),
    ),
  );
  foreach ($components as $component) {
    $form['display'][$component] = array(
      '#type' => 'checkbox',
      '#title' => ucfirst($component),
      '#default_value' => kpane_settings_default_value($context, array('display', $component), TRUE),
    );
  }
  kore_include('heading');
  $form['display']['title_tag'] = array(
    '#type' => 'select',
    '#title' => t('Title tag'),
    '#options' => kore_heading_tag_options(),
    '#default_value' => kpane_settings_default_value($context, array('display', 'title_tag'), 'h3'),
  );

  // Links
  $components = array('image', 'title', 'body', 'wrapper');
  $form['links'] = array(
    '#type' => 'fieldset',
    '#title' => t('Link'),
    '#description' => t('Set selected component as link.'),
    '#collapsible' => TRUE,
    //'#collapsed' => TRUE,
    '#attributes' => array(
      'class' => array('form-inline'),
    ),
  );
  foreach ($components as $component) {
    $form['links'][$component] = array(
      '#type' => 'checkbox',
      '#title' => ucfirst($component),
      '#default_value' => kpane_settings_default_value($context, array('links', $component), FALSE),
    );
  }

  // Image
  kpane_include('image');
  $form['image'] = kpane_image_settings_form('image', $context);

  // Add states to display, links, image elements.
  foreach (array('display', 'links', 'image') as $element) {
    $form[$element]['#states'] = array(
      'invisible' => array(
        ':input[name="settings[theme][display]"]' => array('value' => 'none'),
      ),
    );
  }

  return $form;
}

function kpane_kpane_posts_reset() {
  kfield_add_field_default('entityreference', KPANE_ENTITY, 'posts', 'kpane_posts_ref', t('Posts'));
}

// =============================================================================
// Helper Functions

/**
 * Helper function to prepare kitem based theme function with items.
 */
function _kpane_kpane_posts_template_preprocess(&$variables, $vars, $context) {
  $variables = array(
    'items' => array(),
    'settings' => array(),
  );

  // Prepare settings
  $context_settings = $context->settings['posts'];
  $settings = &$variables['settings'];
  foreach ($context_settings['display'] as $com => $val) {
    $settings[$com] = $val;
  }

  // Prepare items
  $items = &$variables['items'];
  $posts = isset($vars['kpane_posts_ref']) ? $vars['kpane_posts_ref'] : array();
  foreach ($posts as $post) {
    if (!$post['access']) continue;
    $entity = $post['entity'];
    // Data
    //$eck_entity_type = entity_type_load('kpost');
    //$formatters = eck_property_behavior_invoke_plugin($eck_entity_type, 'default_formatter', array('entity' => $entity));
    $item = array(
      'image' => array('path' => $entity->kpost_image[LANGUAGE_NONE][0]['uri'],),
      'title' => $entity->title,//render($formatters['title']),
      'title_tag' => $settings['title_tag'],
      'body' => $entity->body, // render($formatters['body']), // check_markup($entity->body, 'html'),
    );
    // Image
    if ($context_settings['image']['image_style'] != 'none') {
      if ($context_settings['image']['image_style'] != 'picture') {
        $item['image']['style_name'] = $context_settings['image']['image_style'];
      }
      else {
        $item['image'] += array(
          'type' => 'picture',
          'picture' => $context_settings['image'],
        );
      }
    }
    // Links
    foreach ($context_settings['links'] as $link => $on) {
      if ($on && !empty($entity->kpost_link)) {
        $item['links'][$link] = array(
          'path' => $entity->kpost_link[LANGUAGE_NONE][0]['url'],
          'options' => array(
            'title' => $entity->kpost_link[LANGUAGE_NONE][0]['title'],
            'attributes' => $entity->kpost_link[LANGUAGE_NONE][0]['attributes'],
          ),
        );
      }
    }
    $items[] = $item;
  }
}

// -----------------------------------------------------------------------------
// Media

// Settings form for media style.
function kpane_kpane_posts_settings_form_media(&$form, &$form_state, $context) {
  $positions = array('pull-left', 'pull-right');
  $form['media']['image_position'] = array(
    '#type' => 'select',
    '#title' => t('Media object position'),
    '#options' => array_combine($positions, $positions),
    '#default_value' => kpane_settings_default_value($context, array('media', 'image_position'), 'pull-left'),
  );
}

// -----------------------------------------------------------------------------
// Thumbnail

function kpane_kpane_posts_settings_form_thumbnail(&$form, &$form_state, $context) {
  // Thumbnail Height
  $form['thumbnail']['height_equal'] = array(
    '#type' => 'checkbox',
    '#title' => t('Equal height'),
    '#default_value' => kpane_settings_default_value($context, array('thumbnail', 'height_equal'), TRUE),
  );

  // Grid
  $form['thumbnail']['grid'] = array(
    '#type' => 'fieldset',
    '#title' => t('Grid'),
    '#description' => t('Display how many items in one row.'),
    '#collapsible' => TRUE,
    // '#collapsed' => TRUE,
    '#attributes' => array(
      'class' => array('form-inline'),
    ),
  );
  $grids = array('lg', 'md', 'sm', 'xs');
  // Full, Wide: 4, 4, 2, 1.
  // 3/4, Narrow: 3, 3, 1, 1.
  $settings_grid = kpane_settings_default_value($context, array('thumbnail', 'grid'), array(
    'lg' => 4,
    'md' => 4,
    'sm' => 2,
    'xs' => 1,
  ));
  foreach ($grids as $size) {
    $form['thumbnail']['grid'][$size] = array(
      '#type' => 'textfield',
      '#title' => $size,
      '#size' => 2,
      '#default_value' => $settings_grid[$size],
    );
  }
}

// -----------------------------------------------------------------------------
// Carousel

function kpane_kpane_posts_settings_form_carousel(&$form, &$form_state, $context) {
  $options = array();
  foreach (_owlcarousel_return_instances() as $instance) {
    $options[$instance->name] = $instance->name;
  }
  $form['carousel']['owlcarousel'] = array(
    '#type' => 'select',
    '#title' => t('Owlcarousel Instance'),
    '#options' => $options,
    '#default_value' => kpane_settings_default_value($context, array('carousel', 'owlcarousel'), 'owlcarousel_settings_default'),
  );
  $form['carousel']['kitem'] = array(
    '#type' => 'select',
    '#title' => t('Item style'),
    '#options' => kitem_list_options(),
    '#default_value' => kpane_settings_default_value($context, array('carousel', 'kitem'), 'default'),
  );
  $form['carousel']['id'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom ID'),
    '#description' => t('Leave empty to auto generate.'),
    '#default_value' => kpane_settings_default_value($context, array('carousel', id), ''),
  );
}
