<div class="panel-display gaia clearfix" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <div class="row">
    <div class="gaia-col1-region medium-9 columns">
      <?php print $content['col1']; ?>
    </div>
    <div class="gaia-col2-region medium-3 columns">
      <?php print $content['col2']; ?>
    </div>
  </div>
</div>