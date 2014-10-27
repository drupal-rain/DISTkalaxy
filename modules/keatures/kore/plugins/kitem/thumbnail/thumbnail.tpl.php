<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($link_wrapper): ?>
    <?php print $link_wrapper; ?>
  <?php endif; ?>
  <div class="thumbnail" >
    <?php if ($image): ?>
      <?php print $image; ?>
    <?php endif; ?>
    <?php if ($title || $body): ?>
      <div class="caption">
        <?php if ($title): ?>
          <?php print "<$tag>"; ?><?php print $title; ?><?php print "</$tag>"; ?>
        <?php endif; ?>
        <?php if ($body): ?>
          <?php print $body; ?>
        <?php endif; ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if ($link_wrapper): ?>
    <?php print '</a>'; ?>
  <?php endif; ?>
</div>