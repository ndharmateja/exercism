#include "triangle.h"
#include <stdexcept>

namespace triangle
{
    bool is_valid_triangle(double a, double b, double c)
    {
        return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && c + a > b;
    }

    flavor kind(double a, double b, double c)
    {
        if (!is_valid_triangle(a, b, c))
            throw std::domain_error("Invalid triangle.");

        if (a == b && b == c)
            return flavor::equilateral;
        if (a == b || b == c || c == a)
            return flavor::isosceles;
        return flavor::scalene;
    }
} // namespace triangle
