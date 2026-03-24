#include "reverse_string.h"
#include <utility>

namespace reverse_string
{
    std::string reverse_string(std::string input)
    {
        if (input.size() <= 1)
            return input;
        int lo = 0;
        int hi = input.size() - 1;
        while (lo < hi)
            std::swap(input[lo++], input[hi--]);
        return input;
    }
} // namespace reverse_string
