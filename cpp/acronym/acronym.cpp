#include "acronym.h"

namespace acronym
{
    std::string acronym(const std::string &input)
    {
        bool has_word_started = false;
        unsigned char prev_letter = input[0];
        std::string result;
        for (unsigned char c : input)
        {
            // If c is a space, it means the current word ended
            if (c == ' ')
            {
                result.push_back(c);
                continue;
            }
        }
    }
} // namespace acronym
