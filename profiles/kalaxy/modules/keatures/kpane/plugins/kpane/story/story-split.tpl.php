<?php if ($title): ?>
  <?php print "<$tag>$title</$tag>"; ?>
<?php endif; ?>
<div class="row <?php print $classes; ?>">
  <div class="col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_SIXTH) / 2 * $media_size; ?> <?php print $media_position; ?>">
    <?php print render($media); ?>
  </div>
  <div class="col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_SIXTH) / 2 * $body_size; ?>">
    <?php print render($body); ?>
  </div>
</div>
