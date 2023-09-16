#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

#include "Year2017.hpp"
#include "Util.hpp"

int Year2017::Day1Part1(const std::string& input)
{
    std::vector<char> numbers;
    for (auto n : input) {
        if (std::isdigit(n)) {
            numbers.push_back(n);
        }
    }
    numbers.push_back(numbers[0]);
    auto sum { 0 };
    for (size_t i { 0 }; i < numbers.size() - 1; i++)
    {
        auto x { numbers[i] };
        auto y { numbers[i + 1] };
        if (x == y) {
            sum += x - '0';
        }
    }
    
    return sum;
}

int Year2017::Day1Part2(const std::string& input)
{
    auto halfway { input.length() / 2 };
    std::vector<char> numbers;
    for (auto n : input) {
        if (std::isdigit(n)) {
            numbers.push_back(n);
        }
    }
    for (auto n : input.substr(0, halfway)) {
        if (std::isdigit(n)) {
            numbers.push_back(n);
        }
    }
    auto sum { 0 };
    for (size_t i { 0 }; i < input.length(); i++) {
        auto x { numbers[i] };
        auto y { numbers[i + halfway] };
        if (x == y) {
            sum += x - '0';
        }
    }

    return sum;
}

int Year2017::Day2Part1(const std::string &input)
{
    int sum { 0 };
    auto lines { split(input, "\n") };
    for (auto line : lines) {
        auto numberTexts { split(line, "\t") };
        auto numbers { textToInt(numberTexts) };
        std::sort(numbers.begin(), numbers.end());
        auto smallest { numbers.at(0) };
        auto biggest { numbers.at(numbers.size() - 1 )};
        sum += biggest - smallest;
    }
    return sum;
}

auto Year2017::getEvenlyDivisible(std::vector<int> numbers) {
    for (auto i : numbers) {
        for (auto j : numbers) {
            if (i > j && i % j == 0) {
                return i / j;
            }
        }
    }
    return INT32_MIN;
}

int Year2017::Day2Part2(const std::string &input)
{
    int sum { 0 };
    auto lines { split(input, "\n") };
    for (auto line : lines) {
        auto numberTexts { split(line, "\t") };
        auto numbers { textToInt(numberTexts) };
        std::sort(numbers.rbegin(), numbers.rend());
        sum += getEvenlyDivisible(numbers);
    }
    return sum;
}
