#include <string>

#pragma once

class Year2019 {
    private:
        std::vector<int> getMasses(const std::string input);
        int getFuel(const int mass);
        int getFuelRecursive(const int mass);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
};
