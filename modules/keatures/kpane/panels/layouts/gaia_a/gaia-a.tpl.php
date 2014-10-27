<div class="panel-display gaia clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <section class="section">
    <div class="container">
      <div class="row">
        <div class="col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_FULL); ?> gaia-row1-region">
          <?php print $content['row1']; ?>
        </div>
      </div>
    </div>
    <div class="container">
      <div class="row">
        <div class="col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_FOURTH * 3); ?> gaia-col1-region">
          <?php print $content['col1']; ?>
        </div>
        <div class="col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_FOURTH); ?> gaia-col2-region">
          <?php print $content['col2']; ?>
        </div>
      </div>
    </div>
    <div class="container">
      <div class="row">
        <div class="col-md-<?php print kalatheme_grid_size(KALATHEME_GRID_FULL); ?> gaia-row2-region">
          <?php print $content['row2']; ?>
        </div>
      </div>
    </div>
  </section>
</div>