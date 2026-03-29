#pragma once
#include <string>

namespace star_map
{
    enum class System
    {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
    };
}

namespace heaven
{
    class Vessel
    {
    private:
        // Instance variables
        std::string name;

    public:
        // Instance variables
        star_map::System current_system;
        int generation;
        int busters;

        // Constructor
        Vessel(std::string, int, star_map::System system = star_map::System::Sol);

        // Instance methods
        Vessel replicate(std::string);
        void make_buster();
        bool shoot_buster();

        // Friend functions
        friend std::string get_older_bob(Vessel, Vessel);
    };

    std::string get_older_bob(Vessel, Vessel);
    bool in_the_same_system(Vessel, Vessel);
}
