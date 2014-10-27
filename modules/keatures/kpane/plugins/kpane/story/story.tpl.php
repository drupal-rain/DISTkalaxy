<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($title): ?>
    <?php print "<$tag>$title</$tag>"; ?>
  <?php endif; ?>
  <?php print $fields; ?>
</div>