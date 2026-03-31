#include "grains.h"

namespace grains
{
    // There are 2^(n-1) grains in square 'n'
    // We can get 2^(n-1) by left shifting 1 by n-1 bits
    unsigned long long square(int n) { return 1ULL << (n - 1); }

    // Total grains = 2^0 + 2^1 + ... + 2^63 = 2^64 - 1
    // In a 64 bit number, the bit pattern is 11111....11 (64 bits)
    // we can get that by subtracting 1 from 0ULL
    unsigned long long total() { return 0ULL - 1; }
} // namespace grains
