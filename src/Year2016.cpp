#include <string>
#include <tuple>
#include <cstdlib>
#include <vector>
#include <set>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <map>

#include "Year2016.hpp"
#include "Util.hpp"
#include "CompassDirection.hpp"
#include "KeypadKey.hpp"

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

int Year2016::Day1Part1(const std::string& input)
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

int Year2016::Day1Part2(const std::string& input)
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

auto move(std::map<char, KeypadKey> keys, KeypadKey current, char direction) {
    char nextValue;
    switch (direction) {
        case 'U':
            nextValue = current.getNorth().value_or(current.getValue());
            break;
        case 'D':
            nextValue = current.getSouth().value_or(current.getValue());
            break;
        case 'L':
            nextValue = current.getWest().value_or(current.getValue());
            break;
        case 'R':
            nextValue = current.getEast().value_or(current.getValue());
            break;
    }
    return keys.at(nextValue);
}

auto Year2016::getNineKeyPad() {
    std::map<char, KeypadKey> keys;
    keys.insert({'1', KeypadKey('1', std::nullopt, '4', '2', std::nullopt)});
    keys.insert({'2', KeypadKey('2', std::nullopt, '5', '3', '1')});
    keys.insert({'3', KeypadKey('3', std::nullopt, '6', std::nullopt, '2')});
    keys.insert({'4', KeypadKey('4', '1', '7', '5', std::nullopt)});
    keys.insert({'5', KeypadKey('5', '2', '8', '6', '4')});
    keys.insert({'6', KeypadKey('6', '3', '9', std::nullopt, '5')});
    keys.insert({'7', KeypadKey('7', '4', std::nullopt, '8', std::nullopt)});
    keys.insert({'8', KeypadKey('8', '5', std::nullopt, '9', '7')});
    keys.insert({'9', KeypadKey('9', '6', std::nullopt, std::nullopt, '8')});
    return keys;
}

auto Year2016::getThirteenKeyPad() {
    std::map<char, KeypadKey> keys;
    keys.insert({'1', KeypadKey('1', std::nullopt, '3', std::nullopt, std::nullopt)});
    keys.insert({'2', KeypadKey('2', std::nullopt, '6', '3', std::nullopt)});
    keys.insert({'3', KeypadKey('3', '1', '7', '4', '2')});
    keys.insert({'4', KeypadKey('4', std::nullopt, '8', std::nullopt, '3')});
    keys.insert({'5', KeypadKey('5', std::nullopt, std::nullopt, '6', std::nullopt)});
    keys.insert({'6', KeypadKey('6', '2', 'A', '7', '5')});
    keys.insert({'7', KeypadKey('7', '3', 'B', '8', '6')});
    keys.insert({'8', KeypadKey('8', '4', 'C', '9', '7')});
    keys.insert({'9', KeypadKey('9', std::nullopt, std::nullopt, std::nullopt, '8')});
    keys.insert({'A', KeypadKey('A', '6', std::nullopt, 'B', std::nullopt)});
    keys.insert({'B', KeypadKey('B', '7', 'D', 'C', 'A')});
    keys.insert({'C', KeypadKey('C', '8', std::nullopt, std::nullopt, 'B')});
    keys.insert({'D', KeypadKey('D', 'B', std::nullopt, std::nullopt, std::nullopt)});
    return keys;
}

auto Year2016::getCode(std::map<char, KeypadKey> keys, const std::string& input) {
    KeypadKey current { keys.at('5') };
    std::ostringstream code;
    auto instructionSet { split(input, "\n") };
    for (auto instructionLine : instructionSet) {
        for (auto dir : instructionLine) {
            current = move(keys, current, dir);
        }
        code << current.getValue();
    }

    return code.str();
}

std::string Year2016::Day2Part1(const std::string &input)
{
    return getCode(getNineKeyPad(), input);
}

std::string Year2016::Day2Part2(const std::string &input)
{
    return getCode(getThirteenKeyPad(), input);
}
