#pragma once

#include <string>

typedef std::unordered_map<char, int> letterGroup;

class Year2018 {
    private:
        auto group(const std::string& letters);
        auto hasCount(const letterGroup group, const int expectedRepeatedLetterCount);
        auto hasOneThreeLetterSet(const letterGroup group);
        auto hasOneTwoLetterSet(const letterGroup group);
        auto findDifferingPositions(const std::string& code, const std::string& otherCode);
        auto removePosition(const std::string& code, const int position);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
        int Day2Part1(const std::string& input);
        std::string Day2Part2(const std::string& input);
};
