#pragma once

#include <string>
#include <memory>

namespace troy
{

    struct artifact
    {
        // constructors needed (until C++20)
        artifact(std::string name) : name(name) {}
        std::string name;
    };

    struct power
    {
        // constructors needed (until C++20)
        power(std::string effect) : effect(effect) {}
        std::string effect;
    };

    class human
    {
    public:
        // Member variables
        std::unique_ptr<artifact> possession;

        // Own power is shared pointer as the shared_ptr of the influenced_by of the target
        // should also point to the ptr of the own_power of the caster
        // and the influenced_by should exist even after the caster is destroyed
        std::shared_ptr<power> own_power;
        std::shared_ptr<power> influenced_by;

        // Constructor
        human();
    };

    void give_new_artifact(human &, const std::string &);
    void exchange_artifacts(std::unique_ptr<artifact> &, std::unique_ptr<artifact> &);
    void manifest_power(human &, const std::string &);
    void use_power(human &, human &);
    int power_intensity(const human &);
} // namespace troy
