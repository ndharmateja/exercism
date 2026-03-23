#include "darts.h"

namespace darts
{
    int score(double x, double y)
    {
        double squared_distance = x * x + y * y;
        if (squared_distance <= 1)
            return 10;
        if (squared_distance <= 25)
            return 5;
        if (squared_distance <= 100)
            return 1;
        return 0;
    }
} // namespace darts
