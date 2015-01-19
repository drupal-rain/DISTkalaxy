<div class="panel-display gaia clearfix" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <div class="row">
    <div class="gaia-row1-region medium-12 columns">
      <?php print $content['row1']; ?>
    </div>
  </div>
  <div class="row">
    <div class="gaia-cola1-region medium-9 columns">
      <?php print $content['cola1']; ?>
    </div>
    <div class="gaia-cola2-region medium-3 columns">
      <?php print $content['cola2']; ?>
    </div>
  </div>
  <div class="row">
    <div class="gaia-row2-region medium-12 columns">
      <?php print $content['row2']; ?>
    </div>
  </div>
  <div class="row">
    <div class="gaia-colb1-region medium-9 columns">
      <?php print $content['colb1']; ?>
    </div>
    <div class="gaia-colb2-region medium-3 columns">
      <?php print $content['colb2']; ?>
    </div>
  </div>
  <div class="row">
    <div class="gaia-row3-region medium-12 columns">
      <?php print $content['row3']; ?>
    </div>
  </div>
</div>