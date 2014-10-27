<?php

/**
 * Implements hook_preprocess_HOOK().
 *
 * Add in ktopic context.
 */
function ktopic_review_preprocess_page(&$vars) {
  if (!isset($vars['node'])) return;

  // Add in ktopic node object.
  if ($vars['node']->type == 'kreview') {
    $kreview = $vars['node'];
    $vars['ktopic'] = kreview_get_ktopic($kreview);
    $vars['kreview'] = $kreview;
  }

  // Insert theme hook suggestion before 'page__node__kreview'.
  $pos = array_search('page__node__kreview', $vars['theme_hook_suggestions']);
  if ($pos !== FALSE) {
    array_splice($vars['theme_hook_suggestions'], $pos, 1, array('page__node__ktopic', 'page__node__kreview'));
  }
  // dsm($vars);

}
