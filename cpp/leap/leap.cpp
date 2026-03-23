#include "leap.h"

namespace leap
{
    bool is_leap_year(int year)
    {
        // if (year % 4 == 1)
        //     return false;
        // if (year % 100 == 0 && year % 400 != 0)
        //     return false;
        // return year % 4 == 0;

        // More efficient solution
        // as the evaluation happens from the most likely to least likely
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
} // namespace leap
