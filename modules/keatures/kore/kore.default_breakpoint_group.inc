<?php
/**
 * @file
 * kore.default_breakpoint_group.inc
 */

/**
 * Implements hook_default_breakpoint_group().
 */
function kore_default_breakpoint_group() {
  $export = array();

  $breakpoint_group = new stdClass();
  $breakpoint_group->disabled = FALSE; /* Edit this to true to make a default breakpoint_group disabled initially */
  $breakpoint_group->api_version = 1;
  $breakpoint_group->machine_name = 'kala';
  $breakpoint_group->name = 'Kala';
  $breakpoint_group->breakpoints = array(
    0 => 'custom.user.lg',
    1 => 'custom.user.md',
    2 => 'custom.user.sm',
    3 => 'custom.user.xs',
  );
  $breakpoint_group->type = 'custom';
  $breakpoint_group->overridden = 0;
  $export['kala'] = $breakpoint_group;

  return $export;
}
