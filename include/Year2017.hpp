#pragma once

#include <string>

class Year2017 {
    private:
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
        int Day2Part1(const std::string& input);
        auto getEvenlyDivisible(std::vector<int> numbers);
        int Day2Part2(const std::string& input);
        int getSumOfSurroundings(int x, int y, std::unordered_map<std::string, int> positions);
        int Day3Part1(const std::string& input);
        int Day3Part2(const std::string &input);
        int Day4Part1(const std::string& input);
        int Day4Part2(const std::string& input);
};
