#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <unordered_map>
#include <iostream>

#include "Year2018.hpp"
#include "Util.hpp"

int Year2018::Day1Part1(const std::string& input)
{
    return sum(inputToVector(input));
}

int Year2018::Day1Part2(const std::string& input)
{
    std::set<int> usedFrequencies;
    auto frequencies { inputToVector(input) };
    auto sum { 0 };
    usedFrequencies.insert(sum);

    auto current { 0 };
    while (true) {
        if (current >= frequencies.size()) {
            current = 0;
        }
        auto f { frequencies[current] };
        sum += f;
        auto inserted { usedFrequencies.insert(sum) };
        if (!inserted.second) {
            return sum;
        }
        current++;
    }

    return -1;
}

auto Year2018::group(std::string letters) {
    letterGroup grouped;
    for (auto letter : letters) {
        if (grouped.contains(letter))
            grouped[letter]++;
        else
            grouped.insert({ letter, 1 });
    }
    return grouped;
}

auto Year2018::hasCount(letterGroup group, int expectedRepeatedLetterCount) {
    auto numberWithCount { std::count_if(
        group.cbegin(),
        group.cend(),
        [expectedRepeatedLetterCount](std::pair<char, int> pair){ return pair.second == expectedRepeatedLetterCount; }
    ) };
    return numberWithCount > 0;
}

auto Year2018::hasOneThreeLetterSet(letterGroup group) {
    return hasCount(group, 3);
}

auto Year2018::hasOneTwoLetterSet(letterGroup group) {
    return hasCount(group, 2);
}

int Year2018::Day2Part1(const std::string &input)
{
    auto codes { split(input, "\n") };
    std::vector<letterGroup> grouped;
    std::transform(codes.cbegin(), codes.cend(), std::back_inserter(grouped), [this](std::string code){ return group(code); });
    auto hasTwoCount { std::count_if(grouped.cbegin(), grouped.cend(), [this](letterGroup group){ return hasOneTwoLetterSet(group); }) };
    auto hasThreeCount { std::count_if(grouped.cbegin(), grouped.cend(), [this](letterGroup group){ return hasOneThreeLetterSet(group); }) };
    return hasTwoCount * hasThreeCount;
}

std::string Year2018::Day2Part2(const std::string &input)
{
    return "-1";
}
