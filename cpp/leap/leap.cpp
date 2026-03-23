#include "leap.h"

namespace leap
{
    bool is_leap_year(int year)
    {
        if (year % 2 == 1)
            return false;
        if (year % 100 == 0 && year % 400 != 0)
            return false;
        return year % 4 == 0;
    }
} // namespace leap
