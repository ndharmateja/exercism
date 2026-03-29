#include "doctor_data.h"

heaven::Vessel::Vessel(std::string name, int gen, star_map::System system) : name{name}, current_system{system}, generation{gen}, busters{0} {}

heaven::Vessel heaven::Vessel::replicate(std::string name)
{
    return heaven::Vessel(name, this->generation + 1, this->current_system);
}

void heaven::Vessel::make_buster() { this->busters++; }

bool heaven::Vessel::shoot_buster()
{
    // If no busters are available, we return false
    if (!this->busters)
        return false;

    // Otherwise we decrement busters and return true
    this->busters--;
    return true;
}

std::string heaven::get_older_bob(heaven::Vessel v1, heaven::Vessel v2) { return v1.generation < v2.generation ? v1.name : v2.name; }

bool heaven::in_the_same_system(heaven::Vessel v1, heaven::Vessel v2) { return v1.current_system == v2.current_system; }