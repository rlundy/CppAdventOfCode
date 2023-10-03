#include <algorithm>
#include <stdexcept>

#include "Year2020.hpp"
#include "Util.hpp"
#include "Parser.hpp"

int Year2020::Day1Part1(const std::string& input) {
    auto const numbers { inputToVector(input) };
    for (auto i { 0 }; i < numbers.size(); ++i)
    for (auto j { 0 }; j < numbers.size(); ++j)
    {
        auto const first { numbers[i] };
        auto const second { numbers[j] };
        if (first < second && first + second == 2020)
            return first * second;
    }
    throw std::logic_error("Couldn't find two numbers that add to 2020.");
}

int Year2020::Day1Part2(const std::string& input) {
    auto const numbers { inputToVector(input) };
    for (auto i { 0 }; i < numbers.size(); ++i)
    for (auto j { 0 }; j < numbers.size(); ++j)
    for (auto k { 0 }; k < numbers.size(); ++k)
    {
        auto const first { numbers[i] };
        auto const second { numbers[j] };
        auto const third { numbers[k] };
        if (first < second && second < third && first + second + third == 2020) {
            return first * second * third;
        }
    }
    throw std::logic_error("Couldn't find three numbers that add to 2020.");
}

bool Year2020::IsValid(const std::string& passwordFileLine) {
    int atLeastTimes, atMostTimes;
    char letterToFind;
    std::string password;
    Parser(passwordFileLine) >> atLeastTimes >> '-' >> atMostTimes >> letterToFind >> ':' >> password;
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
    int firstPosition, secondPosition;
    char letterToFind;
    std::string password;
    Parser(passwordFileLine) >> firstPosition >> '-' >> secondPosition >> letterToFind >> ':' >> password;
    --firstPosition;
    --secondPosition;
    // firstPosition-secondPosition letterToFind: password
    auto inFirst { password[firstPosition] == letterToFind };
    auto inSecond { password[secondPosition] == letterToFind };
    return (inFirst || inSecond) && !(inFirst && inSecond);
}

int Year2020::Day2Part2(const std::string &input)
{
    auto policies { split(input, "\n") };
    return std::count_if(policies.cbegin(), policies.cend(), [this](std::string policy){ return IsValidPart2(policy); });
}

int Year2020::Day3Part1(const std::string &input)
{
    auto lines { split(input, "\n" ) };
    auto lineCount { lines.size() };
    auto lineLength { lines.at(0).size() };

    auto xMove { 3 }, yMove { 1 };
    auto x { 0 }, y { 0 };
    auto trees { 0 };

    while (y < lineCount) {
        auto ch { lines.at(y)[x] };
        if (ch == '#') {
            ++trees;
        }
        x += xMove;
        y += yMove;
        if (x >= lineLength) {
            x -= lineLength;
        }
    }

    return trees;
}

int Year2020::Day3Part2(const std::string &input)
{
    return -1;
}
