#include <string>
#include <tuple>
#include <cstdlib>
#include <vector>
#include <set>
#include <stdexcept>

#include "Year2016.hpp"
#include "Util.hpp"
#include "CompassDirection.hpp"

CompassDirection Year2016::makeTurn(const CompassDirection direction, const char turn) {
    auto min { static_cast<int>(CompassDirection::MIN) };
    auto max { static_cast<int>(CompassDirection::MAX) };
    auto directionAsInt { static_cast<int>(direction) };
    if (turn == 'L') {
        directionAsInt--;
        if (directionAsInt < min)
            directionAsInt = max;
    }
    else if (turn == 'R') {
        directionAsInt++;
        if (directionAsInt > max) {
            directionAsInt = min;
        }
    }
    return static_cast<CompassDirection>(directionAsInt);
}

std::tuple<int, int> Year2016::getNextMove(CompassDirection direction) {
    switch (direction) {
        case CompassDirection::NORTH:
            return std::make_tuple(0, -1);
            break;
        case CompassDirection::SOUTH:
            return std::make_tuple(0, 1);
            break;
        case CompassDirection::EAST:
            return std::make_tuple(1, 0);
            break;
        case CompassDirection::WEST:
            return std::make_tuple(-1, 0);
            break;
        default:
            throw std::invalid_argument("Not a valid compass direction.");
            break;
    }
}

int Year2016::Day1Part1(const std::string &input)
{
    auto steps { split(input, ", ") };
    auto x { 0 };
    auto y { 0 };
    auto direction { CompassDirection::NORTH };
    for (auto step : steps) {
        auto turn { step[0] };
        auto distanceText { step.substr(1) };
        auto distance { std::stoi(distanceText) };
        direction = makeTurn(direction, turn);
        auto nextMove { getNextMove(direction) };
        for (int i { 0 }; i < distance; i++)
        {
            auto [xChange, yChange] { nextMove };
            x += xChange;
            y += yChange;
        }
    }
    
    return std::abs(x) + std::abs(y);
}

int Year2016::Day1Part2(const std::string &input)
{
    auto firstPosition { std::make_tuple(0, 0) };
    std::set<decltype(firstPosition)> positionsVisited { firstPosition };

    auto steps { split(input, ", ") };
    auto x { 0 };
    auto y { 0 };
    auto direction { CompassDirection::NORTH };
    for (auto step : steps) {
        auto turn { step[0] };
        auto distanceText { step.substr(1) };
        auto distance { std::stoi(distanceText) };
        direction = makeTurn(direction, turn);
        auto nextMove { getNextMove(direction) };
        for (int i {0}; i < distance; i++) {
            auto [xChange, yChange] { nextMove };
            x += xChange;
            y += yChange;
            bool added;
            std::tie(std::ignore, added) = positionsVisited.insert(std::make_tuple(x, y));
            if (!added)
                return std::abs(x) + std::abs(y);
        }
    }

    return 0;
}
