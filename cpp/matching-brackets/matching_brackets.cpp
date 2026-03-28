#include "matching_brackets.h"
#include <stack>

namespace matching_brackets
{
    bool is_opening(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }

    bool is_closing(char c)
    {
        return c == ')' || c == ']' || c == '}';
    }

    bool is_matching(char open, char close)
    {
        return (open == '(' && close == ')') ||
               (open == '[' && close == ']') ||
               (open == '{' && close == '}');
    }

    bool check(std::string input)
    {
        std::stack<char> stack;
        for (char c : input)
        {
            // Add opening brackets to stack
            if (is_opening(c))
            {
                stack.push(c);
                continue;
            }

            if (is_closing(c))
            {
                // If stack is empty at this point, return false
                if (stack.empty())
                    return false;
                if (!is_matching(stack.top(), c))
                    return false;
                stack.pop();
            }

            // If non-bracket chars, we don't do anything
        }

        // At this point if stack is empty, all chars were matched
        // otherwise there were opening brackets that were not balanced
        return stack.empty();
    }
} // namespace matching_brackets
