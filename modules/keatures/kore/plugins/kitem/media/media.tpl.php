<li class="<?php print $classes; ?> media"<?php print $attributes; ?>>
  <?php if ($link_wrapper): ?>
    <?php print $link_wrapper; ?>
  <?php endif; ?>
  <div class="media-container" >
    <?php if ($image): ?>
      <div class="media-object <?php print $image_position; ?>">
        <?php print $image; ?>
      </div>
    <?php endif; ?>
    <?php if ($title || $body): ?>
      <div class="media-body">
        <?php if ($title): ?>
          <?php print "<$tag class=\"media-heading\">"; ?><?php print $title; ?><?php print "</$tag>"; ?>
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
</li>