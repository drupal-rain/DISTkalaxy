<?php
/**
 * @file
 * ktopic_review.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function ktopic_review_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:kreview:default:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'kreview';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'gaia_a';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'row1' => NULL,
      'col1' => NULL,
      'col2' => NULL,
      'row2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '30c26c2a-cf03-490f-b654-ce92f444faa8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-12e09b0d-cbb9-408b-bde7-429602389a7a';
    $pane->panel = 'col1';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:image_cover';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_link' => '',
        'image_style' => '',
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12e09b0d-cbb9-408b-bde7-429602389a7a';
    $display->content['new-12e09b0d-cbb9-408b-bde7-429602389a7a'] = $pane;
    $display->panels['col1'][0] = 'new-12e09b0d-cbb9-408b-bde7-429602389a7a';
    $pane = new stdClass();
    $pane->pid = 'new-14508cd6-0205-400c-a853-79901d240c08';
    $pane->panel = 'col1';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '14508cd6-0205-400c-a853-79901d240c08';
    $display->content['new-14508cd6-0205-400c-a853-79901d240c08'] = $pane;
    $display->panels['col1'][1] = 'new-14508cd6-0205-400c-a853-79901d240c08';
    $pane = new stdClass();
    $pane->pid = 'new-7716794d-9e1e-4aa4-8552-4214a003786a';
    $pane->panel = 'col2';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:kreview_pros';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'textformatter_list',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'textformatter_type' => 'ul',
        'textformatter_class' => 'textformatter-list',
        'textformatter_comma_full_stop' => 0,
        'textformatter_comma_and' => 0,
        'textformatter_comma_tag' => 'div',
        'textformatter_comma_override' => 0,
        'textformatter_separator_custom' => '',
        'textformatter_separator_custom_tag' => 'span',
        'textformatter_separator_custom_class' => 'textformatter-separator',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7716794d-9e1e-4aa4-8552-4214a003786a';
    $display->content['new-7716794d-9e1e-4aa4-8552-4214a003786a'] = $pane;
    $display->panels['col2'][0] = 'new-7716794d-9e1e-4aa4-8552-4214a003786a';
    $pane = new stdClass();
    $pane->pid = 'new-c61efae6-e9bb-4e60-a3c5-fd10e0757336';
    $pane->panel = 'col2';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:kreview_cons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'textformatter_list',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'textformatter_type' => 'ul',
        'textformatter_class' => 'textformatter-list',
        'textformatter_comma_full_stop' => 0,
        'textformatter_comma_and' => 0,
        'textformatter_comma_tag' => 'div',
        'textformatter_comma_override' => 0,
        'textformatter_separator_custom' => '',
        'textformatter_separator_custom_tag' => 'span',
        'textformatter_separator_custom_class' => 'textformatter-separator',
      ),
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c61efae6-e9bb-4e60-a3c5-fd10e0757336';
    $display->content['new-c61efae6-e9bb-4e60-a3c5-fd10e0757336'] = $pane;
    $display->panels['col2'][1] = 'new-c61efae6-e9bb-4e60-a3c5-fd10e0757336';
    $pane = new stdClass();
    $pane->pid = 'new-8349c7bb-ae91-4f02-878b-1157c87bd168';
    $pane->panel = 'row2';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'default',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8349c7bb-ae91-4f02-878b-1157c87bd168';
    $display->content['new-8349c7bb-ae91-4f02-878b-1157c87bd168'] = $pane;
    $display->panels['row2'][0] = 'new-8349c7bb-ae91-4f02-878b-1157c87bd168';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-14508cd6-0205-400c-a853-79901d240c08';
  $panelizer->display = $display;
  $export['node:kreview:default:default'] = $panelizer;

  return $export;
}
