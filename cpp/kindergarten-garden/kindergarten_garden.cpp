#include "kindergarten_garden.h"

namespace kindergarten_garden
{
    std::array<Plants, 4> plants(std::string plants_org, std::string name)
    {
        // Split the plants organization strings into 2 rows
        size_t newline_index = plants_org.find_first_of("\n");
        std::string_view full_view{plants_org};
        std::string_view row1{full_view.substr(0, newline_index)};
        std::string_view row2{full_view.substr(newline_index + 1)};

        // As the 12 students' names start with A, B, C, D..
        int index = name.at(0) - 'A';
        std::array<Plants, 4> result;

        // We have already assigned one char to each of the enum values
        // so we can directly cast the character into an enum value
        result[0] = static_cast<Plants>((row1[2 * index]));
        result[1] = static_cast<Plants>((row1[2 * index + 1]));
        result[2] = static_cast<Plants>((row2[2 * index]));
        result[3] = static_cast<Plants>((row2[2 * index + 1]));

        return result;
    }
} // namespace kindergarten_garden
