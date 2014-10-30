<?php
/**
 * @file
 * kore.default_picture_mapping.inc
 */

/**
 * Implements hook_default_picture_mapping().
 */
function kore_default_picture_mapping() {
  $export = array();

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala 1/2';
  $picture_mapping->machine_name = 'kala_2_1';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'd',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'd',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
  );
  $export['kala_2_1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala 1/3';
  $picture_mapping->machine_name = 'kala_3_1';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'e',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'e',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
  );
  $export['kala_3_1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala 2/3';
  $picture_mapping->machine_name = 'kala_3_2';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
  );
  $export['kala_3_2'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala 1/4';
  $picture_mapping->machine_name = 'kala_4_1';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'f',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'f',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
  );
  $export['kala_4_1'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala 3/4';
  $picture_mapping->machine_name = 'kala_4_3';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'b',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
  );
  $export['kala_4_3'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala banner 3/4';
  $picture_mapping->machine_name = 'kala_banner_4_3';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'b-banner',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-banner',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-banner',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-banner',
      ),
    ),
  );
  $export['kala_banner_4_3'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala banner full';
  $picture_mapping->machine_name = 'kala_banner_full';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'a-banner',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'b-banner',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-banner',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-banner',
      ),
    ),
  );
  $export['kala_banner_full'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala full';
  $picture_mapping->machine_name = 'kala_full';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'a',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'b',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c',
      ),
    ),
  );
  $export['kala_full'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala landscape 3/4';
  $picture_mapping->machine_name = 'kala_landscape_4_3';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'b-landscape',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-landscape',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-landscape',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-landscape',
      ),
    ),
  );
  $export['kala_landscape_4_3'] = $picture_mapping;

  $picture_mapping = new PictureMapping();
  $picture_mapping->disabled = FALSE; /* Edit this to true to make a default picture_mapping disabled initially */
  $picture_mapping->api_version = 2;
  $picture_mapping->label = 'Kala landscape full';
  $picture_mapping->machine_name = 'kala_landscape_full';
  $picture_mapping->breakpoint_group = 'kala';
  $picture_mapping->mapping = array(
    'custom.user.lg' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'a-landscape',
      ),
    ),
    'custom.user.md' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'b-landscape',
      ),
    ),
    'custom.user.sm' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-landscape',
      ),
    ),
    'custom.user.xs' => array(
      '1x' => array(
        'mapping_type' => 'image_style',
        'image_style' => 'c-landscape',
      ),
    ),
  );
  $export['kala_landscape_full'] = $picture_mapping;

  return $export;
}
