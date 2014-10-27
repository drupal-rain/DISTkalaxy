<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($link_wrapper): ?>
    <?php print $link_wrapper; ?>
  <?php endif; ?>
  <div class="kitem-container" >
    <?php if ($title): ?>
      <?php print "<$tag>"; ?><?php print $title; ?><?php print "</$tag>"; ?>
    <?php endif; ?>
    <?php if ($image): ?>
      <?php print $image; ?>
    <?php endif; ?>
    <?php if ($body): ?>
      <div class="kitem-content">
        <?php print $body; ?>
      </div>
    <?php endif; ?>
  </div>
  <?php if ($link_wrapper): ?>
    <?php print '</a>'; ?>
  <?php endif; ?>
</div>