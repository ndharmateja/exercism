#include "armstrong_numbers.h"
#include <cmath>

namespace armstrong_numbers
{
    bool is_armstrong_number(int number)
    {
        if (number == 0)
            return true;
        int result{0};
        int num_digits{static_cast<int>((log10(number))) + 1};
        int copy{number};
        while (copy > 0)
        {
            result += std::pow(copy % 10, num_digits);
            copy = copy / 10;
        }
        return result == number;
    }
} // namespace armstrong_numbers
