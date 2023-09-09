#include "Year2015.hpp"

int Year2015::Day1Part1(const std::string& input)
{
    auto up = std::count(input.cbegin(), input.cend(), '(');
    auto down = std::count(input.cbegin(), input.cend(), ')');
    return static_cast<int>(up - down);
}

int Year2015::Day1Part2(const std::string &input)
{
    auto floor = 0;
    for (auto i = 0; i < input.length(); i++) {
        auto step = input[i];
        if (step == '(') {
            floor++;
        }
        else if (step == ')') {
            floor--;
        }
        if (floor < 0) {
            return i + 1;
        }
    }
    return -1;
}
