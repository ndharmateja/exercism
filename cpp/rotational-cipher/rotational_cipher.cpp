#include "rotational_cipher.h"
#include <string>

namespace rotational_cipher
{
    char shift_char(char c, int shift)
    {
        shift = shift % 26;
        char a = std::islower(c) ? 'a' : 'A';
        short offset = c - a;
        return a + ((offset + shift) % 26);
    }

    std::string rotate(std::string input, int shift)
    {
        for (char &c : input)
            if (std::isalpha(c))
                c = shift_char(c, shift);
        return input;
    }
} // namespace rotational_cipher
