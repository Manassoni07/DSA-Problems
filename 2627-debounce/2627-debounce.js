/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timer;

    return function(...args) {
        // Clear any existing timer to cancel the previous call execution
        clearTimeout(timer);

        // Schedule the execution of fn after t milliseconds
        timer = setTimeout(() => {
            fn(...args);
        }, t);
    };
};

/**
 * Example Usage:
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */