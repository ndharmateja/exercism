#include "rna_transcription.h"
#include <stdexcept>

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
        for (auto &c : input)
            c = to_rna(c);
        return input;
    }
} // namespace rna_transcription
