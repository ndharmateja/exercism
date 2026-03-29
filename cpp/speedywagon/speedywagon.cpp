#include "speedywagon.h"

namespace speedywagon
{

    // Enter your code below:

    // Please don't change the interface of the uv_light_heuristic function
    int uv_light_heuristic(std::vector<int> *data_array)
    {
        double avg{};
        for (auto element : *data_array)
        {
            avg += element;
        }
        avg /= data_array->size();
        int uv_index{};
        for (auto element : *data_array)
        {
            if (element > avg)
                ++uv_index;
        }
        return uv_index;
    }

    bool connection_check(pillar_men_sensor *ptr) { return ptr != nullptr; }

    int activity_counter(pillar_men_sensor *sensors_base_addr, size_t num_sensors)
    {
        int result{0};
        for (size_t i = 0; i < num_sensors; i++)
            result += sensors_base_addr[i].activity;
        return result;
    }

    bool alarm_control(pillar_men_sensor *ptr)
    {
        if (ptr == nullptr)
            return false;
        return ptr->activity > 0;
    }

    bool uv_alarm(pillar_men_sensor *ptr)
    {
        if (ptr == nullptr)
            return false;
        return uv_light_heuristic(&ptr->data) > ptr->activity;
    }
} // namespace speedywagon
