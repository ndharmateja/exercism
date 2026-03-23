#include <string>

namespace log_line
{
    std::string message(std::string line)
    {
        int colon_index = line.find(":");
        return line.substr(colon_index + 2);
    }

    std::string log_level(std::string line)
    {
        int closing_brace_index = line.find("]");
        return line.substr(1, closing_brace_index - 1);
    }

    std::string reformat(std::string line)
    {
        // return the reformatted message
        return message(line) + " (" + log_level(line) + ")";
    }
} // namespace log_line
