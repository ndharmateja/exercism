#include "pascals_triangle.h"

namespace pascals_triangle
{
    std::vector<std::vector<int>> generate_rows(int num_rows)
    {
        if (num_rows == 0)
            return {};

        std::vector<std::vector<int>> result{{1}};
        result.reserve(num_rows);

        if (num_rows == 1)
            return result;

        for (int i = 1; i < num_rows; i++)
        {
            // If the latest entry was {1, 3, 3, 1}
            // we copy it & make it {1, 4, 6, 4} by adding consecutive elements
            // and then add 1 at the end

            // Create a copy of the latest row
            std::vector<int> row(result.back());
            for (int j = row.size() - 1; j >= 1; --j)
                row[j] += row[j - 1];
            row.push_back(1);
            result.push_back(row);
        }

        return result;
    }
} // namespace pascals_triangle
