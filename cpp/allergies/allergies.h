#pragma once
#include <string>
#include <unordered_set>

namespace allergies
{
    class allergy_test
    {
    private:
        std::unordered_set<std::string> allergens;

    public:
        // Constructor
        allergy_test(const int &score);

        // Member functions
        // const as these fns don't change state
        bool is_allergic_to(const std::string &) const;
        std::unordered_set<std::string> get_allergies() const;
    };
} // namespace allergies
