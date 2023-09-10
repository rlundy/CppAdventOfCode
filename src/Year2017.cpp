#include <iostream>
#include <vector>
#include <string>
#include <cctype>

#include "Year2017.hpp"

int Year2017::Day1Part1(const std::string& input)
{
    std::vector<char> numbers;
    for (auto n : input) {
        if (std::isdigit(n)) {
            numbers.push_back(n);
        }
    }
    numbers.push_back(numbers[0]);
    int sum { 0 };
    for (int i { 0 }; i < numbers.size() - 1; i++)
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
    int sum{0};
    for (int i { 0 }; i < input.length(); i++) {
        auto x { numbers[i] };
        auto y { numbers[i + halfway] };
        if (x == y) {
            sum += x - '0';
        }
    }

    return sum;
}
