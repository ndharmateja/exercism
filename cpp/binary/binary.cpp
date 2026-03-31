#include "binary.h"

namespace binary
{
    int convert(const std::string &input)
    {
        // ax^3 + bx^2 + cx^1 + d = (((0x + a)x + b)x + c)x + d
        // result = 0
        // result = result * x + a = 0x + a = a
        // result = result * x + b = (0x + a)x + b = ax + b
        // result = result * x + c = (0x + a)x + b)x + c = ax^2 + bx + c
        // result = result * x + d = (0x + a)x + b)x + c)x + d = ax^3 + bx^2 + cx + d
        int result{0};
        for (char c : input)
        {
            if (c != '0' && c != '1')
                return 0;
            result = (result << 1) + (c - '0');
        }
        return result;
    }
} // namespace binary
