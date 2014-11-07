Kpane
=====
Provide useful features to compose article by using panels panes.

Plugin: Kpane
=============
* settings (Required) // @todo
    - Default settings value.
* bundle info (Optional)
    - Callback: MODULE_PLUGIN-TYPE_PLUGIN_bundle_info().
    - @see kpane_plugin_get_function().
    - Hook into HOOK_entity_info_alter(), add bundle in code.
    Or just create it by using admin UI, then use plugin to provide some customization, or as an alter callback.
    - Helper: _kpane_plugin_bundle_info().
* theme registry (Optional)
    - Callback: MODULE_PLUGIN-TYPE_PLUGIN_theme_registry($existing, $type, $theme, $path).
    - Helper: _kpane_plugin_theme_registry().
* template preprocess (Optional)
    - Callback: MODULE_PLUGIN-TYPE_PLUGIN_template_preprocess().
    - Actual hook by other add-on: MODULE_preprocess_fieldable_panels_pane__PLUGIN(&$vars, $context).
* template process (Optional)
    - Callback: MODULE_PLUGIN-TYPE_PLUGIN_template_process().
* settings form (Optional)
    - Callback: MODULE_PLUGIN-TYPE_PLUGIN_settings_form($form_orig, &$form_state, $context).
* reset (Optional)
    - As initiate and reset.
* css (Optional)
    - Attach css file.
* js (Optional)
    - Attach js file.
* classes (Optional)
    - Predefined CSS classes.



Kpane Types
===========
* code
* dividend
* feature
* heading
* longtext
* (?)media
* picture
* post
* posts
* quote
* whitespace

Kpane Template
==============
* kpane_KPANE
* kpane_KPANE_DISPLAY
* kpane_KPANE_DISPLAY_STYLE
* kpane_KPANE[_DISPLAY][_STYLE]__IDENTITY (So theme can easily override a single pane.)


Current Development Strategy for Kpane
======================================
* Develop and use in experiment.
* Update the db if necessary.
* Create a new 'display' or even 'kpane' when needed.


