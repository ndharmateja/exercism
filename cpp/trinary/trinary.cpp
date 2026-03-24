#include "trinary.h"

namespace trinary
{
    int to_decimal(std::string input)
    {
        int current_three_power = 1;
        int result = 0;
        for (auto it = input.rbegin(); it != input.rend(); ++it)
        {
            char c = *it;
            if (!isdigit(c))
                return 0;
            result += current_three_power * (c - '0');
            current_three_power *= 3;
        }
        return result;
    }
} // namespace trinary
