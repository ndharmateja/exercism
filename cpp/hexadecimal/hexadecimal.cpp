#include "hexadecimal.h"

namespace hexadecimal
{
    int convert(std::string input)
    {
        int result = 0;
        int curr_power_of_16 = 1;
        char c;
        int digit;
        for (auto it = input.rbegin(); it != input.rend(); ++it)
        {
            c = *it;
            if (isdigit(c))
                digit = c - '0';
            else if (c >= 'a' && c <= 'f')
                digit = (c - 'a') + 10;
            else
                return 0;
            result += curr_power_of_16 * digit;
            curr_power_of_16 *= 16;
        }

        return result;
    }
} // namespace hexadecimal
