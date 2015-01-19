
<div class="panel-display apollo clearfix <?php !empty($class) ? print $class : ''; ?>" <?php !empty($css_id) ? print "id=\"$css_id\"" : ''; ?>>
  <div class="row">
    <div class="apollo-cola1-region medium-6 large-8 columns">
      <?php print $content['cola1']; ?>
    </div>
    <div class="apollo-cola2-region medium-6 large-4 columns">
      <?php print $content['cola2']; ?>
    </div>
  </div>
  <div class="row">
    <div class="apollo-colb1-region medium-6 large-4 columns">
      <?php print $content['colb1']; ?>
    </div>
    <div class="apollo-colb2-region medium-6 large-8 columns">
      <?php print $content['colb2']; ?>
    </div>
  </div>
</div>
