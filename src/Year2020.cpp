#include <algorithm>

#include "Year2020.hpp"
#include "Util.hpp"

int Year2020::Day1Part1(const std::string& input) {
    auto numbers { inputToVector(input) };
    for (auto i { 0 }; i < numbers.size(); i++)
    for (auto j { 1 }; j < numbers.size(); j++)
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
    for (auto i { 0 }; i < numbers.size(); i++)
    for (auto j { 1 }; j < numbers.size(); j++)
    for (auto k { 2 }; k < numbers.size(); k++)
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

bool Year2020::IsValid(const std::string& passwordFileLine) {
    auto parts { split(passwordFileLine, ":") };
    auto password { trim(parts[1]) };
    auto frontparts { split(parts[0], " ") };
    auto letterToFind { frontparts[1][0] };
    auto range { split(frontparts[0], "-") };
    auto atLeastTimes { std::stoi(range[0]) };
    auto atMostTimes { std::stoi(range[1]) };
    // atLeastTimes-atMostTimes letterToFind: password
    auto letterTimes { std::count_if(password.cbegin(), password.cend(), [letterToFind](char p){ return p == letterToFind; }) };
    return letterTimes >= atLeastTimes && letterTimes <= atMostTimes;
}

int Year2020::Day2Part1(const std::string &input)
{
    auto policies { split(input, "\n") };
    return std::count_if(policies.cbegin(), policies.cend(), [this](std::string policy){ return IsValid(policy); });
}

bool Year2020::IsValidPart2(const std::string& passwordFileLine) {
    auto parts { split(passwordFileLine, ":") };
    auto password { trim(parts[1]) };
    auto frontparts { split(parts[0], " ") };
    auto letterToFind { frontparts[1][0] };
    auto range { split(frontparts[0], "-") };
    auto firstPosition { std::stoi(range[0]) - 1 };
    auto secondPosition { std::stoi(range[1]) - 1 };
    // firstPosition-secondPosition letterToFind: password
    auto inFirst = password[firstPosition] == letterToFind;
    auto inSecond = password[secondPosition] == letterToFind;
    return (inFirst || inSecond) && !(inFirst && inSecond);
}

int Year2020::Day2Part2(const std::string &input)
{
    auto policies { split(input, "\n") };
    return std::count_if(policies.cbegin(), policies.cend(), [this](std::string policy){ return IsValidPart2(policy); });
}
