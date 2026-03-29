#include "power_of_troy.h"

namespace troy
{
    human::human() : possession{nullptr}, own_power{nullptr}, influenced_by{nullptr} {}

    void give_new_artifact(human &h, const std::string &artifact_name)
    {
        h.possession = std::make_unique<artifact>(artifact_name);
    }

    void exchange_artifacts(std::unique_ptr<artifact> &p1, std::unique_ptr<artifact> &p2)
    {
        auto temp = std::move(p1);
        p1 = std::move(p2);
        p2 = std::move(temp);
    }

    void manifest_power(human &h, const std::string &power_name)
    {
        h.own_power = std::make_shared<power>(power_name);
    }

    void use_power(human &caster, human &target)
    {
        // Works as both influenced_by and own_power are both shared_ptrs
        target.influenced_by = caster.own_power;
    }

    int power_intensity(const human &h)
    {
        if (h.own_power == nullptr)
            return 0;
        return h.own_power.use_count();
    }
} // namespace troy
