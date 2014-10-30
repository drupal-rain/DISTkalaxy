<div class="panel-display phanes clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <section class="section">
    <div class="container">
      <div class="row">
        <div class="col-md-<?php print kore_grid_size(KORE_GRID_SIXTH * 5); ?> phanes-col1-region">
          <?php print $content['col1']; ?>
        </div>
        <div class="col-md-<?php print kore_grid_size(KORE_GRID_SIXTH); ?> phanes-col2-region">
          <?php print $content['col2']; ?>
        </div>
      </div>
    </div>
  </section>
</div>
