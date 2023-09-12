#pragma once

#include <string>
#include <map>

#include "CompassDirection.hpp"
#include "KeypadKey.hpp"

class Year2016 {
    public:
        CompassDirection makeTurn(const CompassDirection direction, const char turn);
        std::tuple<int, int> getNextMove(CompassDirection direction);
        auto getNineKeyPad();
        auto getThirteenKeyPad();
        auto getCode(std::map<char, KeypadKey> keys, const std::string &input);
        int Day1Part1(const std::string &input);
        int Day1Part2(const std::string& input);
        std::string Day2Part1(const std::string& input);
        std::string Day2Part2(const std::string& input);
};
