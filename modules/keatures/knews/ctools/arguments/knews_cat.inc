<?php

$plugin = array(
  'title' => t("Knews Category Term"),
  // keyword to use for %substitution
  'keyword' => 'knews_cat',
  'description' => t('Creates a "knew_cat" from the arg.'),
  'context' => 'knews_cat_context',
  // 'settings form' => 'simplecontext_arg_settings_form',
  'placeholder form' => array(
    '#type' => 'textfield',
    '#description' => t('Enter the knews_cat term name.'),
  ),
);

/**
 * Get the simplecontext context using the arg. In this case we're just going
 * to manufacture the context from the data in the arg, but normally it would
 * be an API call, db lookup, etc.
 */
function knews_cat_context($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If $empty == TRUE it wants a generic, unfilled context.
  if ($empty) {
    return ctools_context_create_empty('term');
  }
  if (empty($arg)) {
    return FALSE;
  }

  $name = str_replace('-', ' ', $arg);
  $terms = kfield_taxonomy_term_entity_query('knews_cat', $name);
  if (empty($terms)) {
    return FALSE;
  }

  return ctools_context_create('term', reset($terms));
}
