#include "isogram.h"
#include <bitset>

namespace isogram
{
    bool is_isogram(const std::string &input)
    {
        std::bitset<26> has_occurred;
        has_occurred.reset();
        for (unsigned char c : input)
        {
            // If c is not any alphabet, we skip
            if (!std::isalpha(c))
                continue;

            // If a char has already occurred, we directly return false
            c = std::tolower(c);
            if (has_occurred.test(c - 'a'))
                return false;

            // Otherwise set the index
            has_occurred.set(c - 'a');
        }

        // If we reached here it means that no chars were repeated
        return true;
    }
} // namespace isogram
