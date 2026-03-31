#include "grade_school.h"
#include <algorithm>

namespace grade_school
{
    void school::add(std::string name, int grade)
    {
        auto &names = this->_map[grade];

        // This insertion is faster than sorting the whole vector
        // Find the first element that is greater than name
        // so that we can insert the name at that position to
        // keep the list sorted
        auto it = std::upper_bound(names.begin(), names.end(), name);
        names.insert(it, name);
    }

    std::map<int, std::vector<std::string>> school::roster() const { return this->_map; }

    std::vector<std::string> school::grade(int g) const
    {
        // [] operator can't be used as this is a const function
        // [] creates a default value if the key isn't present
        auto it = this->_map.find(g);
        if (it == this->_map.end())
            return std::vector<std::string>{};

        // return the corresponding vector of strings
        return it->second;
    }
} // namespace grade_school
