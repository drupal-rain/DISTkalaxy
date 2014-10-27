<?php

/**
 * Implements hook_variable_group_info().
 */
function kfield_variable_group_info() {
  $groups['keatures'] = array(
    'title' => t('Keatures'),
    'description' => t('Keatures variables.'),
    'access' => 'administer site configuration',
    'path' => array('admin/config/system/variable/keatures'),
  );

  return $groups;
}
