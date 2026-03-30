#include "robot_name.h"

namespace robot_name
{
    std::unordered_set<std::string> robot::used_names;
    std::random_device robot::rd;
    std::mt19937 robot::gen(rd());

    std::string robot::generate_random_name()
    {
        std::uniform_int_distribution<int> char_dist(0, 25);
        std::uniform_int_distribution<int> digit_dist(0, 9);

        std::string result;
        for (size_t i = 0; i < 2; i++)
            result += static_cast<char>('A' + char_dist(gen));
        for (size_t i = 0; i < 3; i++)
            result += std::to_string(digit_dist(gen));

        // Return resulting random name
        return result;
    }

    // Constructor
    robot::robot() { this->reset(); }

    std::string robot::name() const { return this->name_; }

    void robot::reset()
    {
        std::string name;
        while (used_names.count(name = generate_random_name()))
            ;
        used_names.emplace(name);
        this->name_ = name;
    }
} // namespace robot_name
