<div class="panel-display chaos clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <section class="section">
    <div class="container">
      <div class="row">
        <div class="col-md-<?php print kore_grid_size(KORE_GRID_FULL); ?> chaos-row-region">
          <?php print $content['row']; ?>
        </div>
      </div>
    </div>
  </section>
</div>