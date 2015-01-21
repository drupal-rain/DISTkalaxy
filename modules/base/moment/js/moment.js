/**
 * @file
 * Moment.js integration.
 */

(function ($) {
  'use strict';

  Drupal.moment = Drupal.moment || {};

  /**
   * Interface language code.
   *
   * @return {string}
   */
  Drupal.moment.getInterfaceLanguageCode = function () {
    var $html = $('html');

    return $html.attr('lang') || $html.attr('xml:lang') || 'en';
  };

  /**
   * Supported formats are very limited.
   *
   * @todo Improve.
   *
   * @param {string} format
   *
   *  @return {string}
   */
  Drupal.moment.dateLimitFormatDate = function (format) {
    return format
      .replace(/h|H|m|s/g, '')
      .replace(/^[\s,'"\.:;\-]+/g, '')
      .replace(/[\s,'"\.:;\-]+$/g, '');
  };

}(jQuery));
