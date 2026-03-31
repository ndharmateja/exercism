#include "hamming.h"
#include <stdexcept>

namespace hamming
{
    int compute(const std::string &s1, const std::string &s2)
    {
        // If sizes are incompatible
        if (s1.size() != s2.size())
            throw std::domain_error("Sizes not same.");

        // Iterate and count number of corresponding chars that are different
        int result{0};
        for (size_t i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i])
                result++;
        return result;
    }
} // namespace hamming
