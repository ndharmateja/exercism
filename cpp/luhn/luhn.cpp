#include "luhn.h"

namespace luhn
{
    bool valid(std::string input)
    {
        if (input.length() <= 1)
            return false;

        int sum = 0;
        int num_digits = 0;
        for (auto it = input.rbegin(); it != input.rend(); ++it)
        {
            char c = *it;
            if (c == ' ')
                continue;
            if (!isdigit(c))
                return false;
            ++num_digits;
            int digit = (num_digits % 2 == 0) ? ((c - '0') * 2) : (c - '0');
            if (digit > 9)
                digit -= 9;
            sum += digit;
        }

        return num_digits > 1 && sum % 10 == 0;
    }
} // namespace luhn
