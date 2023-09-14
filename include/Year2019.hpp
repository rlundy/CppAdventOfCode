#pragma once

#include <string>

class Year2019 {
    private:
        int getFuel(const int mass);
        int getFuelRecursive(const int mass);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
        int Day2Part1(const std::string& input);
        int Day2Part2(const std::string& input);
};
