<div class="panel-display phanes clearfix" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <div class="row">
    <div class="phanes-col1-region medium-10 columns">
      <?php print $content['col1']; ?>
    </div>
    <div class="phanes-col2-region medium-2 columns">
      <?php print $content['col2']; ?>
    </div>
  </div>
</div>