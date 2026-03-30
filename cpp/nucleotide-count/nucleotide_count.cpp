#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count
{
    std::map<char, int> count(std::string input)
    {
        std::map<char, int> counts{
            {'A', 0},
            {'C', 0},
            {'G', 0},
            {'T', 0},
        };

        for (const auto c : input)
        {
            if (c != 'A' && c != 'C' && c != 'G' && c != 'T')
                throw std::invalid_argument("Illegal character");
            counts[c]++;
        }
        return counts;
    }
} // namespace nucleotide_count
