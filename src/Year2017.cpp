#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "Year2017.hpp"
#include "Util.hpp"

int Year2017::Day1Part1(const std::string& input)
{
    const auto adjustedInput { input + input[0] };
    auto sum { 0 };
    for (size_t i { 0 }; i < input.size(); ++i) {
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
    for (size_t i { 0 }; i < halfway; ++i) {
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

int Year2017::Day3Part1(const std::string &input)
{
    auto magnitude { 1 };
    auto sign { 1 };
    auto xPos { 0 };
    auto yPos { 0 };
    auto target { std::stoi(input) };
    auto counter { 1 };
    while (counter < target) {
        for (auto i { 0 }; i < magnitude; ++i) {
            ++counter;
            xPos += sign;
            if (counter == target) {
                return abs(xPos) + abs(yPos);
            }
        }
        for (auto j { 0 }; j < magnitude; ++j) {
            ++counter;
            yPos += sign;
            if (counter == target) {
                return abs(xPos) + abs(yPos);
            }
        }
        sign = -sign;
        ++magnitude;
    }
    return abs(xPos) + abs(yPos);
}

int Year2017::getSumOfSurroundings(int x, int y, std::unordered_map<std::string, int> positions) {
    std::vector<std::string> keysToLookFor;
    keysToLookFor.push_back(toKey(x - 1, y - 1));
    keysToLookFor.push_back(toKey(x, y - 1));
    keysToLookFor.push_back(toKey(x + 1, y - 1));
    keysToLookFor.push_back(toKey(x - 1, y));
    // no x, y of course because that's the current position
    keysToLookFor.push_back(toKey(x + 1, y));
    keysToLookFor.push_back(toKey(x - 1, y + 1));
    keysToLookFor.push_back(toKey(x, y + 1));
    keysToLookFor.push_back(toKey(x + 1, y + 1));

    int sum { 0 };
    for (auto key : keysToLookFor) {
        if (positions.contains(key)) {
            auto pos { positions.find(key) };
            sum += pos->second;
        }
    }
    return sum;
}

int Year2017::Day3Part2(const std::string &input)
{ 
    std::unordered_map<std::string, int> positions;
    auto magnitude { 1 };
    auto sign { 1 };
    auto xPos { 0 };
    auto yPos { 0 };
    auto currentValue { 1 };
    positions.emplace(toKey(xPos, yPos), 1);
    auto target { std::stoi(input) };
    auto counter { 1 };
    while (true) {
        for (auto i { 0 }; i < magnitude; ++i) {
            ++counter;
            xPos += sign;
            auto value { getSumOfSurroundings(xPos, yPos, positions) };
            if (value > target) {
                return value;
            }
            positions.emplace(toKey(xPos, yPos), value);
        }
        for (auto j { 0 }; j < magnitude; ++j) {
            ++counter;
            yPos += sign;
            auto value { getSumOfSurroundings(xPos, yPos, positions) };
            if (value > target) {
                return value;
            }
            positions.emplace(toKey(xPos, yPos), value);
        }
        sign = -sign;
        ++magnitude;
    }
}

int Year2017::Day4Part1(const std::string &input)
{
    auto passphrases { split(input, "\n") };
    auto numberValid { 0 };
    for (auto phrase : passphrases) {
        auto isValid { true };
        auto words { split(phrase, " ") };
        std::unordered_set<std::string> duplicates;
        for (auto word : words) {
            auto [it, added] { duplicates.insert(word) };
            if (!added) {
                isValid = false;
            }
        }
        if (isValid) {
            ++numberValid;
        }
    }
    
    return numberValid;
}

int Year2017::Day4Part2(const std::string &input)
{
    auto passphrases { split(input, "\n") };
    auto numberValid { 0 };
    for (auto phrase : passphrases) {
        auto isValid { true };
        auto words { split(phrase, " ") };
        std::unordered_set<std::string> duplicates;
        for (auto word : words) {
            std::sort(word.begin(), word.end());
            auto [it, added] { duplicates.insert(word) };
            if (!added) {
                isValid = false;
            }
        }

        if (isValid) {
            ++numberValid;
        }
    }

    return numberValid;
}
