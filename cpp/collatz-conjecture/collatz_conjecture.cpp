#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture
{
    int steps(long long n)
    {
        // If n is 0, domain error
        if (n <= 0)
            throw std::domain_error("n should be positive.");

        // Count #steps
        int steps = 0;
        while (n != 1)
        {
            // divide n by 2
            if (n % 2 == 0)
                n >>= 1;
            else
                n = 3 * n + 1;
            steps++;
        }
        return steps;
    }
} // namespace collatz_conjecture
