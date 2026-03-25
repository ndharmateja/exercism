#include "bob.h"

namespace bob
{
    std::string hey(std::string input)
    {
        int num_alphabets{0}, num_upper_case{0}, num_chars{0};
        char last_char;
        for (const char &c : input)
        {
            if (iswspace(c))
                continue;
            num_chars++;
            last_char = c;
            if (isalpha(c))
            {
                num_alphabets++;
                num_upper_case += ('A' <= c && c <= 'Z') ? 1 : 0;
            }
        }

        bool yelling = num_alphabets > 0 && num_alphabets == num_upper_case;
        bool question = last_char == '?';
        bool silence = num_chars == 0;
        if (silence)
            return "Fine. Be that way!";
        if (question && yelling)
            return "Calm down, I know what I'm doing!";
        if (question)
            return "Sure.";
        if (yelling)
            return "Whoa, chill out!";
        return "Whatever.";
    }
} // namespace bob
