#pragma once

#include <string>

typedef std::unordered_map<char, int> letterGroup;

class Year2018 {
    private:
        auto group(std::string letters);
        auto hasCount(letterGroup group, int expectedRepeatedLetterCount);
        auto hasOneThreeLetterSet(letterGroup group);
        auto hasOneTwoLetterSet(letterGroup group);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
        int Day2Part1(const std::string &input);
        std::string Day2Part2(const std::string& input);
};
