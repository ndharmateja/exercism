#pragma once
#include <string>
#include <random>
#include <unordered_set>

namespace robot_name
{
    class robot
    {
    private:
        std::string name_;

        // Static variables
        // An ordered set to store all the robot names that were
        // ever used
        static std::unordered_set<std::string> used_names;

        // static function to generate a random name according to the spec
        static std::string generate_random_name();

        // Random objects
        static std::random_device rd;
        static std::mt19937 gen;

    public:
        robot();
        std::string name() const;
        void reset();
    };
} // namespace robot_name
