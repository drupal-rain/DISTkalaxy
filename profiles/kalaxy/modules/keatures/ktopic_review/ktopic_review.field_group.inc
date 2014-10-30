<?php
/**
 * @file
 * ktopic_review.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ktopic_review_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_verditct|node|kreview|form';
  $field_group->group_name = 'group_verditct';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'kreview';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Verdict',
    'weight' => '4',
    'children' => array(
      0 => 'kreview_pros',
      1 => 'kreview_cons',
      2 => 'kreview_score',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-verditct field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_verditct|node|kreview|form'] = $field_group;

  return $export;
}
