#include "isbn_verifier.h"
#include <iostream>

namespace isbn_verifier
{
    bool is_valid(const std::string &isbn)
    {
        int digit_multiplier = 10;
        int result = 0;
        for (const unsigned char c : isbn)
        {
            // We can skip hyphens
            if (c == '-')
                continue;

            // If it is not the last iteration
            if (digit_multiplier != 1)
            {
                if (!('0' <= c && c <= '9'))
                    return false;
                result += ((c - '0') * digit_multiplier--);
                continue;
            }

            // Last iteration
            if (!('0' <= c && c <= '9') && c != 'X')
                return false;
            int digit = c == 'X' ? 10 : c - '0';
            result += (digit * digit_multiplier--);
        }

        return digit_multiplier == 0 && result % 11 == 0;
    }
} // namespace isbn_verifier
