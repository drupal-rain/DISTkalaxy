(function ($) {

  Drupal.behaviors.views_tree = {
    attach: function (context, settings) {

      var views_tree_settings = Drupal.settings.views_tree_setting;
      for(var views_tree_name in views_tree_settings) {

        $.each( $(".view-id-"+views_tree_name+" .view-content li"), function () {
          var count = $(this).find("li").size();
          if (count > 0) {
            $(this).addClass('views_tree_parent');
            if (views_tree_settings[views_tree_name] != "collapsed") {
              $(this).addClass('views_tree_expanded');
              $(this).prepend('<div class="views_tree_link views_tree_link_expanded"><a href="#">Operation</a></div>');
            }
            else {
              $(this).addClass('views_tree_collapsed');
              $(this).prepend('<div class="views_tree_link views_tree_link_collapsed"><a href="#">Operation</a></div>');
              $(this).children(".item-list").hide();
            }
          }
        });

      }
      $('.views_tree_link a', context).once('views_tree', function () {
        $(this).click(function (e) {
          e.preventDefault();

          if ($(this).parent().hasClass('views_tree_link_expanded')) {
            $(this).parent().parent().children(".item-list").slideUp();
            $(this).parent().addClass('views_tree_link_collapsed');
            $(this).parent().removeClass('views_tree_link_expanded');
          }
          else {
            $(this).parent().parent().children(".item-list").slideDown();
            $(this).parent().addClass('views_tree_link_expanded');
            $(this).parent().removeClass('views_tree_link_collapsed');
          }

        });
      });
    }
  };

})(jQuery);
