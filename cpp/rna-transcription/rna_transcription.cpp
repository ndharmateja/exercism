#include "rna_transcription.h"
#include <stdexcept>
#include <algorithm>

namespace rna_transcription
{
    char to_rna(char c)
    {
        switch (c)
        {
        case 'C':
            return 'G';
        case 'G':
            return 'C';
        case 'A':
            return 'U';
        case 'T':
            return 'A';
        default:
            throw std::domain_error("Invalid char.");
        }
    }

    std::string to_rna(std::string input)
    {
        std::transform(input.begin(), input.end(),
                       input.begin(),
                       [](char c)
                       { return to_rna(c); });
        return input;
    }
} // namespace rna_transcription
