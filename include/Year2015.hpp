#pragma once

#include <string>

class Year2015 {
    private:
        int getWrappingPaper(const std::string& dimensions);
        int getRibbon(const std::string& dimensions);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
        int Day2Part1(const std::string& input);
        int Day2Part2(const std::string& input);
};
