#include "pangram.h"
#include <bitset>
#include <cctype>

namespace pangram
{
    bool is_pangram(std::string input)
    {
        // bitset<26> only uses 26 bits compared to array<bool, 26> which uses 26 bytes
        std::bitset<26> has_occurred;

        // Iterate over each char and count
        for (char c : input)
        {
            if (std::isalpha(c))
            {
                int index = std::tolower(c) - 'a';
                if (!has_occurred[index])
                    has_occurred.set(index);
            }

            // Early exit
            if (has_occurred.all())
                return true;
        }

        return has_occurred.all();
    }
} // namespace pangram
