#include "lasagna_master.h"

namespace lasagna_master
{
    int preparationTime(std::vector<std::string> layers, int avg_time_per_layer) { return layers.size() * avg_time_per_layer; }

    amount quantities(std::vector<std::string> layers)
    {
        int noodles_count{0}, sauces_count{0};
        for (const auto &layer : layers)
        {
            if (layer == "noodles")
                noodles_count++;
            if (layer == "sauce")
                sauces_count++;
        }

        return amount{noodles_count * 50, sauces_count * 0.2};
    }

    void addSecretIngredient(std::vector<std::string> &my_list, const std::vector<std::string> &friends_list)
    {
        // This works because back() method returns
        // a reference (std::string&) to the last element
        my_list.back() = friends_list.back();
    }

    void addSecretIngredient(std::vector<std::string> &my_list, const std::string &auntiesSecret)
    {
        // This works because back() method returns
        // a reference (std::string&) to the last element
        my_list.back() = auntiesSecret;
    }

    std::vector<double> scaleRecipe(const std::vector<double> &amounts, int num_portions)
    {
        // The amounts are specified for two people
        // So if the num_portions is 2, then there is no scaling required
        if (num_portions == 2)
            return amounts;

        std::vector<double> result(amounts.size());
        double scaling_factor = num_portions / 2.0;
        std::transform(amounts.begin(), amounts.end(),
                       result.begin(),
                       [scaling_factor](double q)
                       { return scaling_factor * q; });
        return result;
    }
} // namespace lasagna_master
