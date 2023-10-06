#pragma once

#include <string>
#include <cstdint>
#include <vector>

class Year2021 {
    private:
        void filterValues(std::vector<std::string>& values, char preferredZeroChar, char preferredOneChar);
    public:
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);
        int64_t Day2Part1(const std::string& input);
        int64_t Day2Part2(const std::string& input);
        int Day3Part1(const std::string& input);
        int Day3Part2(const std::string& input);
};
