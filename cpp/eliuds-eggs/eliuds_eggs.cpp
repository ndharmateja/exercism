#include "eliuds_eggs.h"
#include <bit>

namespace chicken_coop
{
    // Solution 1: Brute force
    // Go over each bit and count the number of ones
    int solution1(int number)
    {
        int num_ones{0};
        for (; number != 0; number >>= 1)
            num_ones += (number & 1);
        return num_ones;
    }

    // Solution 2:
    // For ultra performance use std::popcount(number) to count ones
    // in one instruction (#include <bit>)
    // Works on C++20 or above
    // int solution2(int number)
    // {
    //     return std::popcount(static_cast<unsigned int>(number));
    // }

    // Solution 3: Brian Kernighan's algorithm
    // Reference: https://youtu.be/e0sVe4-JJJI
    // say number =     10111000
    // then number-1 =  10110111
    // all the bits from the right most 1 in the number get flipped
    // so (number) & (number-1) will have one less 1
    // So we can keep doing this until the number becomes zero
    // this algo takes number of iterations = number of 1s
    int solution3(int number)
    {
        int num_ones{0};
        for (; number != 0; number &= (number - 1))
            num_ones++;
        return num_ones;
    }

    int positions_to_quantity(int number)
    {
        return solution3(number);
    }
} // namespace chicken_coop
