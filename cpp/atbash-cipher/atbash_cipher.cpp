#include "atbash_cipher.h"

#include <string>

namespace atbash_cipher
{
    char find_complement_alphabet(unsigned char alphabet)
    {
        int offset_from_start_of_alphabet = tolower(alphabet) - 'a';
        return 'z' - offset_from_start_of_alphabet;
    }

    std::string encode(const std::string &plaintext)
    {
        std::string ciphertext;
        int num_chars_added{0};
        for (const unsigned char c : plaintext)
        {
            if (isdigit(c))
                ciphertext.push_back(c);
            else if (isalpha(c))
                ciphertext.push_back(find_complement_alphabet(c));
            else
                continue;

            if (++num_chars_added % 5 == 0)
                ciphertext.push_back(' ');
        }

        // If the number of characters added is a multiple of 5
        // there would be an extra space at the end
        if (num_chars_added && num_chars_added % 5 == 0)
            ciphertext.pop_back();
        return ciphertext;
    }
    std::string decode(const std::string &ciphertext)
    {
        std::string plaintext;
        for (const unsigned char c : ciphertext)
        {
            if (isalpha(c))
                plaintext.push_back(find_complement_alphabet(c));
            else if (isdigit(c))
                plaintext.push_back(c);
        }
        return plaintext;
    }
} // namespace atbash_cipher
