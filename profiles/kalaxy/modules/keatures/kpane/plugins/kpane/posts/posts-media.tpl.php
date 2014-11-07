<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!empty($title)): ?>
    <?php print "<$tag>$title</$tag>"; ?>
  <?php endif; ?>
  <?php print render($posts); ?>
</div>