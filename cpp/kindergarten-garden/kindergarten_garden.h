#pragma once
#include <array>
#include <string>

namespace kindergarten_garden
{
    enum class Plants : char
    {
        clover = 'C',
        grass = 'G',
        violets = 'V',
        radishes = 'R',
    };

    std::array<Plants, 4> plants(std::string, std::string);
} // namespace kindergarten_garden
