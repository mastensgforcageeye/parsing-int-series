#include "input_generator.h"

#include <cassert>

static std::string random_string(size_t n, const std::string& set) {
    
    std::string result(n, ' ');
    for (size_t i=0; i < n; i++) {
        result[i] = set[rand() % set.size()];
    }

    return result;
}

std::string generate(size_t size, size_t longest_number, size_t longest_separator) {

    assert(longest_number > 0);
    assert(longest_separator > 0);

    std::string result;

    static const std::string numbers    = "0123456789";
    static const std::string separators = ",; ";

    while (true) {
        const size_t n = std::max(size_t(1), rand() % longest_number);
        const size_t k = std::max(size_t(1), rand() % longest_separator);

        const std::string number = random_string(n, numbers);
        const std::string sep    = random_string(k, separators);

        if (result.size() + n + k < size) {
            result += number;
            result += sep;
        } else {
            result += random_string(size - result.size(), separators);
            return result;
        }
    }
}
