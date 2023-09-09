#include <string>

#pragma once

class Year2018 {
    private:
        std::vector<int> textToInt(std::vector<std::string> freqText);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
};
