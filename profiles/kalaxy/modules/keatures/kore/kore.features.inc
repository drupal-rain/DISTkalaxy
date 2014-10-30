<?php
/**
 * @file
 * kore.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kore_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "breakpoints" && $api == "default_breakpoint_group") {
    return array("version" => "1");
  }
  if ($module == "breakpoints" && $api == "default_breakpoints") {
    return array("version" => "1");
  }
  if ($module == "picture" && $api == "default_picture_mapping") {
    return array("version" => "2");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function kore_image_default_styles() {
  $styles = array();

  // Exported image style: a.
  $styles['a'] = array(
    'name' => 'a',
    'label' => 'a',
    'effects' => array(
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: a-banner.
  $styles['a-banner'] = array(
    'name' => 'a-banner',
    'label' => 'a-banner',
    'effects' => array(
      22 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      32 => array(
        'label' => 'Smart Crop',
        'help' => 'Similar to "Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_crop',
        'data' => array(
          'width' => 1140,
          'height' => 285,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: a-landscape.
  $styles['a-landscape'] = array(
    'name' => 'a-landscape',
    'label' => 'a-landscape',
    'effects' => array(
      16 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 1140,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      31 => array(
        'label' => 'Smart Crop',
        'help' => 'Similar to "Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_crop',
        'data' => array(
          'width' => 1140,
          'height' => 640,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: b.
  $styles['b'] = array(
    'name' => 'b',
    'label' => 'b',
    'effects' => array(
      9 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 930,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: b-banner.
  $styles['b-banner'] = array(
    'name' => 'b-banner',
    'label' => 'b-banner',
    'effects' => array(
      24 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 930,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      30 => array(
        'label' => 'Smart Crop',
        'help' => 'Similar to "Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_crop',
        'data' => array(
          'width' => 930,
          'height' => 233,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: b-landscape.
  $styles['b-landscape'] = array(
    'name' => 'b-landscape',
    'label' => 'b-landscape',
    'effects' => array(
      18 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 930,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      29 => array(
        'label' => 'Smart Crop',
        'help' => 'Similar to "Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_crop',
        'data' => array(
          'width' => 930,
          'height' => 522,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: c.
  $styles['c'] = array(
    'name' => 'c',
    'label' => 'c',
    'effects' => array(
      10 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 768,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: c-banner.
  $styles['c-banner'] = array(
    'name' => 'c-banner',
    'label' => 'c-banner',
    'effects' => array(
      26 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 768,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      27 => array(
        'label' => 'Smart Crop',
        'help' => 'Similar to "Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_crop',
        'data' => array(
          'width' => 768,
          'height' => 192,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: c-landscape.
  $styles['c-landscape'] = array(
    'name' => 'c-landscape',
    'label' => 'c-landscape',
    'effects' => array(
      20 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 768,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      28 => array(
        'label' => 'Smart Crop',
        'help' => 'Similar to "Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_crop',
        'data' => array(
          'width' => 768,
          'height' => 430,
        ),
        'weight' => 3,
      ),
    ),
  );

  // Exported image style: d.
  $styles['d'] = array(
    'name' => 'd',
    'label' => 'd',
    'effects' => array(
      11 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 555,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: e.
  $styles['e'] = array(
    'name' => 'e',
    'label' => 'e',
    'effects' => array(
      12 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 360,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: f.
  $styles['f'] = array(
    'name' => 'f',
    'label' => 'f',
    'effects' => array(
      13 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 263,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: g.
  $styles['g'] = array(
    'name' => 'g',
    'label' => 'g',
    'effects' => array(
      14 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 165,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: h.
  $styles['h'] = array(
    'name' => 'h',
    'label' => 'h',
    'effects' => array(
      15 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 68,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
