#pragma once

#include <string>

#include "CompassDirection.hpp"

class Year2016 {
    public:
        CompassDirection makeTurn(const CompassDirection direction, const char turn);
        std::tuple<int, int> getNextMove(CompassDirection direction);
        int Day1Part1(const std::string& input);
        int Day1Part2(const std::string& input);

};
