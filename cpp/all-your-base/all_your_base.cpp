#include "all_your_base.h"
#include <algorithm>
#include <stdexcept>

namespace all_your_base
{
    unsigned convert_to_decimal(std::vector<unsigned> digits, unsigned base)
    {
        // ax^3 + bx^2 + cx^1 + d = (((0x + a)x + b)x + c)x + d
        // result = 0
        // result = result * x + a = 0x + a = a
        // result = result * x + b = (0x + a)x + b = ax + b
        // result = result * x + c = (0x + a)x + b)x + c = ax^2 + bx + c
        // result = result * x + d = (0x + a)x + b)x + c)x + d = ax^3 + bx^2 + cx + d
        unsigned result = 0;
        for (const auto digit : digits)
        {
            if (digit >= base)
                throw std::invalid_argument("Invalid digit '" + std::to_string(digit) + "' for base '" + std::to_string(base) + "'.");
            result = (result * base) + digit;
        }
        return result;
    }

    std::vector<unsigned> convert_from_decimal(unsigned value, unsigned base)
    {
        // If value is 0, we need to return an empty vector
        if (value == 0)
            return {};

        // Collect all digits in reverse order (pushback starts from least significant digit)
        std::vector<unsigned> digits;
        while (value > 0)
        {
            digits.push_back(value % base);
            value /= base;
        }

        std::reverse(digits.begin(), digits.end());
        return digits;
    }

    std::vector<unsigned> convert(unsigned in_base, std::vector<unsigned> digits, unsigned out_base)
    {
        if (in_base <= 1 || out_base <= 1)
            throw std::invalid_argument("Base is not valid.");
        if (in_base == out_base || digits.empty())
            return digits;
        return convert_from_decimal(convert_to_decimal(digits, in_base), out_base);
    }
} // namespace all_your_base
