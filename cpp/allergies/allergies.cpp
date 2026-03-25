#include "allergies.h"
#include <array>

namespace allergies
{
    // const char * is faster than string
    // strings are created in read only memory
    static const std::array<const char *, 8> allergens_list = {
        "eggs", "peanuts", "shellfish", "strawberries",
        "tomatoes", "chocolate", "pollen", "cats"};

    // Constructor
    allergy_test::allergy_test(const int &score)
    {
        // We only need to check the lower 8 bits of score
        for (size_t i = 0; i < allergens_list.size(); i++)
        {
            // If the ith bit from the right is set, we add that allergen
            if (score & 1 << i)
                allergens.emplace(allergens_list[i]);
        }
    }

    // Member functions
    // const as these fns don't change state
    // If count is positive, then bool returned is true
    // and viceversa
    bool allergy_test::is_allergic_to(const std::string &allergen) const { return allergens.count(allergen); }

    std::unordered_set<std::string> allergy_test::get_allergies() const { return allergens; }
} // namespace allergies
