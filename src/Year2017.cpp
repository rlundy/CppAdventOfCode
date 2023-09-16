#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>

#include "Year2017.hpp"
#include "Util.hpp"

int Year2017::Day1Part1(const std::string& input)
{
    const auto adjustedInput = input + input[0];
    auto sum { 0 };
    for (size_t i { 0 }; i < input.size(); i++) {
        auto const x { adjustedInput[i] };
        auto const y { adjustedInput[i + 1] };
        if (x == y) {
            sum += x - '0';
        }
    }
    return sum;
}

int Year2017::Day1Part2(const std::string& input)
{
    auto sum { 0 };
    auto halfway { input.length() / 2 };
    for (size_t i { 0 }; i < halfway; i++) {
        auto const x { input[i] };
        auto const y { input[i + halfway] };
        if (x == y) {
            sum += x - '0';
        }
    }
    return sum * 2;
}

int Year2017::Day2Part1(const std::string &input)
{
    int sum { 0 };
    auto const lines { split(input, "\n") };
    for (auto line : lines) {
        auto const numberTexts { split(line, "\t") };
        auto numbers { textToInt(numberTexts) };
        std::sort(numbers.begin(), numbers.end());
        auto const smallest { numbers.at(0) };
        auto const biggest { numbers.at(numbers.size() - 1 )};
        sum += biggest - smallest;
    }
    return sum;
}

auto Year2017::getEvenlyDivisible(std::vector<int> numbers) {
    for (auto i : numbers)
    for (auto j : numbers) {
        if (i > j && i % j == 0) {
            return i / j;
        }
    }
    throw std::logic_error("No two numbers found where one is evenly divisible by the other.");
}

int Year2017::Day2Part2(const std::string &input)
{
    int sum { 0 };
    auto const lines { split(input, "\n") };
    for (auto line : lines) {
        auto const numberTexts { split(line, "\t") };
        auto numbers { textToInt(numberTexts) };
        std::sort(numbers.rbegin(), numbers.rend());
        sum += getEvenlyDivisible(numbers);
    }
    return sum;
}
