#include "Year2020.hpp"
#include "Util.hpp"

int Year2020::Day1Part1(const std::string& input) {
    auto numbers { inputToVector(input) };
    for (size_t i = 0; i < numbers.size(); i++)
    for (size_t j = 1; j < numbers.size(); j++)
    {
        auto first { numbers[i] };
        auto second { numbers[j] };
        if (first + second == 2020)
            return first * second;
    }
    return -1;
}

int Year2020::Day1Part2(const std::string& input) {
    auto numbers { inputToVector(input) };
    for (size_t i = 0; i < numbers.size(); i++)
    for (size_t j = 1; j < numbers.size(); j++)
    for (size_t k = 2; k < numbers.size(); k++)
    {
        auto first { numbers[i] };
        auto second { numbers[j] };
        auto third { numbers[k] };
        if (first + second + third == 2020) {
            return first * second * third;
        }
    }
    return -1;
}
