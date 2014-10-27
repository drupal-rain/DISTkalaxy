(function ($) {
    $.fn.koreEqualHeight = function () {
        var maxHeight = 0,
            wrapper,
            wrapperHeight;

        return this.each(function () {

            // Applying a wrapper to the contents of the current element to get reliable height
            wrapper = $(this).wrapInner('<div class="wrapper" />').children('.wrapper');
            wrapperHeight = wrapper.outerHeight();

            maxHeight = Math.max(maxHeight, wrapperHeight);

            // Remove the wrapper
            wrapper.children().unwrap();

        }).height(maxHeight);
    }
})(jQuery);
