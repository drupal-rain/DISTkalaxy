
(function($) {
  Drupal.behaviors.koreThumbnail = {
    attach: function (context, settings) {
      $('.thumbnails.equal-height').find('.thumbnail').koreEqualHeight();

      $(window).resize(function () {
        $('.thumbnails.equal-height').find('.thumbnail').koreEqualHeight();
      });
    }
  }
})(jQuery);
