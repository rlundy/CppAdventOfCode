#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <unordered_map>
#include <iostream>
#include <unordered_set>

#include "Year2018.hpp"
#include "Util.hpp"

int Year2018::Day1Part1(const std::string& input)
{
    return sum(inputToVector(input));
}

int Year2018::Day1Part2(const std::string& input)
{
    std::set<int> usedFrequencies;
    auto const frequencies { inputToVector(input) };
    auto sum { 0 };
    usedFrequencies.insert(sum);

    auto current { 0 };
    while (true) {
        if (current >= frequencies.size()) {
            current = 0;
        }
        auto const f { frequencies[current] };
        sum += f;
        auto const inserted { usedFrequencies.insert(sum) };
        if (!inserted.second) {
            return sum;
        }
        current++;
    }
}

auto Year2018::group(const std::string& letters) {
    letterGroup grouped;
    for (auto letter : letters) {
        if (grouped.contains(letter))
            grouped[letter]++;
        else
            grouped.insert({ letter, 1 });
    }
    return grouped;
}

auto Year2018::hasCount(const letterGroup group, const int expectedRepeatedLetterCount) {
    auto const numberWithCount { std::count_if(
        group.cbegin(),
        group.cend(),
        [expectedRepeatedLetterCount](std::pair<char, int> pair){ return pair.second == expectedRepeatedLetterCount; }
    ) };
    return numberWithCount > 0;
}

auto Year2018::hasOneThreeLetterSet(const letterGroup group) {
    return hasCount(group, 3);
}

auto Year2018::hasOneTwoLetterSet(const letterGroup group) {
    return hasCount(group, 2);
}

int Year2018::Day2Part1(const std::string& input)
{
    auto codes { split(input, "\n") };
    std::vector<letterGroup> grouped;
    std::transform(codes.cbegin(), codes.cend(), std::back_inserter(grouped), [this](std::string code){ return group(code); });
    auto hasTwoCount { std::count_if(grouped.cbegin(), grouped.cend(), [this](letterGroup group){ return hasOneTwoLetterSet(group); }) };
    auto hasThreeCount { std::count_if(grouped.cbegin(), grouped.cend(), [this](letterGroup group){ return hasOneThreeLetterSet(group); }) };
    return hasTwoCount * hasThreeCount;
}

std::string Year2018::Day2Part2(const std::string& input)
{
    auto const codes { split(input, "\n") };
    std::unordered_set<std::string> codesWithOneLetterBlankedOut;
    for (auto code : codes) {
        for (size_t i { 0 }; i < code.length(); i++) {
            auto copy { code };
            copy.replace(i, 1, "_");
            auto [it, added] { codesWithOneLetterBlankedOut.insert(copy) };
            if (!added) {
                std::cout << "Original code: " << code << std::endl;
                copy.replace(i, 1, "");
                return copy;
            }
        }
    }
    throw std::logic_error("Couldn't find two codes that differ by only one letter.");
}
