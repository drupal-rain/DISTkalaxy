<div class="<?php print $classes; ?> row vertical-align" <?php print $attributes; ?>>
  <div class="feature-main col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_THIRD) * 2; ?>">
    <?php if ($title): ?>
      <?php print "<$tag class=\"feature-title\">$title</$tag>"; ?>
    <?php endif; ?>
    <div class="feature-intro">
      <?php print render($intro); ?>
    </div>
    <div class="feature-items-first col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_HALF); ?>">
      <?php print $items_first; ?>
    </div>
    <div class="feature-items-second col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_HALF); ?>">
      <?php print $items_second; ?>
    </div>
  </div>
  <div class="feature-picture col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_THIRD); ?>">
    <?php print render($picture); ?>
  </div>
</div>