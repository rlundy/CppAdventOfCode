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
        void doStep(char direction, int &x, int &y);
        int Day3Part1(const std::string &input);
        std::vector<std::pair<int, int>> writeSteps(const std::string& wire);
        int Day3Part2(const std::string &input);
};
