<div class="<?php print $classes; ?> thumbnails row"<?php print $attributes; ?>>
  <?php foreach ($items_output as $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
</div>