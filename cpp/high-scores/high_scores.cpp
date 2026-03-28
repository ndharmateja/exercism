#include "high_scores.h"
#include <algorithm>

namespace arcade
{

    std::vector<int> HighScores::list_scores()
    {
        return this->scores;
    }

    int HighScores::latest_score()
    {
        return this->scores.back();
    }

    int HighScores::personal_best()
    {
        return *std::max_element(scores.begin(), scores.end());
    }

    std::vector<int> HighScores::top_three()
    {
        std::vector<int> copy(scores);
        std::sort(copy.begin(), copy.end(), std::greater<int>());
        size_t count = std::min(size_t(3), copy.size());
        return std::vector<int>(copy.begin(), copy.begin() + count);
    }

} // namespace arcade
