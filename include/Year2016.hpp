#pragma once

#include <string>
#include <map>

#include "CompassDirection.hpp"
#include "KeypadKey.hpp"

class Year2016 {
    private:
        std::pair<int, int> getNextMove(CompassDirection direction);
        auto getNineKeyPad();
        auto getThirteenKeyPad();
        auto getCode(std::map<char, KeypadKey> keys, const std::string &input);
    public:
        CompassDirection makeTurn(const CompassDirection direction, const char turn);
        int Day1Part1(const std::string &input);
        int Day1Part2(const std::string& input);
        std::string Day2Part1(const std::string& input);
        std::string Day2Part2(const std::string& input);
        int Day3Part1(const std::string& input);
        int Day3Part2(const std::string& input);
};
