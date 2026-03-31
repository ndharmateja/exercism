#pragma once
#include <map>
#include <vector>
#include <string>

namespace grade_school
{
    class school
    {
    private:
        std::map<int, std::vector<std::string>> _map;

    public:
        void add(std::string, int);
        std::map<int, std::vector<std::string>> roster() const;
        std::vector<std::string> grade(int) const;
    };
} // namespace grade_school
