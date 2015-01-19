
(function($) {
  Drupal.behaviors.koreTimeAgo = {
    attach: function (context, settings) {
      if (typeof Foundation == 'undefined') return;

      $(".timeago").each(function (index, element) {
        settings_timeago = Foundation.utils.data_options($(element));
        if ($.now() / 1000 - settings_timeago.timestamp < settings_timeago.end) {
          text = moment(settings_timeago.timestamp, "X").fromNow();
          $(element).text(text);
        }
      })
    }
  }
})(jQuery);
