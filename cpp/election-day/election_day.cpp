#include <string>
#include <vector>
#include <algorithm>

namespace election
{

    // The election result struct is already created for you:

    struct ElectionResult
    {
        // Name of the candidate
        std::string name{};
        // Number of votes the candidate has
        int votes{};
    };

    // vote_count takes a reference to an `ElectionResult` as an argument and will
    // return the number of votes in the `ElectionResult.
    int vote_count(const ElectionResult &result) { return result.votes; }

    // increment_vote_count takes a reference to an `ElectionResult` as an argument
    // and a number of votes (int), and will increment the `ElectionResult` by that
    // number of votes.
    void increment_vote_count(ElectionResult &result, int num_votes) { result.votes += num_votes; }

    // determine_result receives the reference to a final_count and returns a
    // reference to the `ElectionResult` of the new president. It also changes the
    // name of the winner by prefixing it with "President". The final count is given
    // in the form of a `reference` to `std::vector<ElectionResult>`, a vector with
    // `ElectionResults` of all the participating candidates.
    ElectionResult &determine_result(std::vector<ElectionResult> &results)
    {
        auto max_votes_it = std::max_element(results.begin(),
                                             results.end(),
                                             [](const ElectionResult &result1, const ElectionResult &result2)
                                             {
                                                 return result1.votes < result2.votes;
                                             });

        // Update the name of the winner struct object with prefix president
        max_votes_it->name = "President " + max_votes_it->name;

        // Return the winner
        return *max_votes_it;
    }

} // namespace election
