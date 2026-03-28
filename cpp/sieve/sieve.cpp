#include "sieve.h"
#include <unordered_set>

namespace sieve
{
    std::vector<int> primes(int n)
    {
        std::vector<int> is_composite(n + 1, false);
        std::vector<int> result;
        for (int i = 2; i <= n; i++)
        {
            if (is_composite.at(i))
                continue;
            int curr = 2 * i;
            while (curr <= n)
            {
                is_composite[curr] = true;
                curr += i;
            }
        }

        for (int i = 2; i <= n; i++)
            if (!is_composite.at(i))
                result.push_back(i);

        return result;
    }
} // namespace sieve
