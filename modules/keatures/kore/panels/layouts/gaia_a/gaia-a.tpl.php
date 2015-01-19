<div class="panel-display gaia clearfix" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <div class="row">
    <div class="gaia-row1-region medium-12 columns">
      <?php print $content['row1']; ?>
    </div>
  </div>
  <div class="row">
    <div class="gaia-col1-region medium-3 columns">
      <?php print $content['col1']; ?>
    </div>
    <div class="gaia-col2-region medium-9 columns">
      <?php print $content['col2']; ?>
    </div>
  </div>
  <div class="row">
    <div class="gaia-row2-region medium-12 columns">
      <?php print $content['row2']; ?>
    </div>
  </div>
</div>