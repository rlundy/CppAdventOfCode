#include <string>
#include <tuple>
#include <cstdlib>
#include <vector>
#include <set>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>

#include "Year2016.hpp"
#include "Util.hpp"
#include "CompassDirection.hpp"
#include "KeypadKey.hpp"

CompassDirection Year2016::makeTurn(const CompassDirection direction, const char turn) {
    auto const min { static_cast<int>(CompassDirection::MIN) };
    auto const max { static_cast<int>(CompassDirection::MAX) };
    auto directionAsInt { static_cast<int>(direction) };
    switch (turn) {
        case 'L':
            --directionAsInt;
            if (directionAsInt < min) {
                directionAsInt = max;
            }
            break;
        case 'R':
            ++directionAsInt;
            if (directionAsInt > max) {
                directionAsInt = min;
            }
            break;
        default:
            throw std::invalid_argument((std::ostringstream() << "Bad direction: " << turn).str());
    }
    return static_cast<CompassDirection>(directionAsInt);
}

std::pair<int, int> Year2016::getNextMove(const CompassDirection direction) {
    switch (direction) {
        case CompassDirection::NORTH: return std::make_pair(0, -1);
        case CompassDirection::SOUTH: return std::make_pair(0, 1);
        case CompassDirection::EAST: return std::make_pair(1, 0);
        case CompassDirection::WEST: return std::make_pair(-1, 0);
        default: throw std::invalid_argument("Not a valid compass direction.");
    }
}

int Year2016::Day1Part1(const std::string& input)
{
    auto steps { split(input, ", ") };
    auto x { 0 };
    auto y { 0 };
    auto direction { CompassDirection::NORTH };
    for (auto step : steps) {
        auto const turn { step[0] };
        auto const distanceText { step.substr(1) };
        auto const distance { std::stoi(distanceText) };
        direction = makeTurn(direction, turn);
        auto const [xChange, yChange] { getNextMove(direction) };
        for (int i { 0 }; i < distance; ++i)
        {
            x += xChange;
            y += yChange;
        }
    }
    
    return std::abs(x) + std::abs(y);
}

int Year2016::Day1Part2(const std::string& input)
{
    auto firstPosition { std::make_pair(0, 0) };
    std::set<decltype(firstPosition)> positionsVisited { firstPosition };

    auto const steps { split(input, ", ") };
    auto x { 0 };
    auto y { 0 };
    auto direction { CompassDirection::NORTH };
    for (auto step : steps) {
        auto const turn { step[0] };
        auto const distanceText { step.substr(1) };
        auto const distance { std::stoi(distanceText) };
        direction = makeTurn(direction, turn);
        auto const nextMove { getNextMove(direction) };
        for (int i {0}; i < distance; ++i) {
            auto [xChange, yChange] { nextMove };
            x += xChange;
            y += yChange;
            auto [it, added] { positionsVisited.insert(std::make_pair(x, y)) };
            if (!added)
                return std::abs(x) + std::abs(y);
        }
    }
    throw std::logic_error("No repeatedly-visited position found.");
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

bool Year2016::isTriangle(std::vector<int> sides) {
    std::sort(sides.begin(), sides.end());
    return sides[0] + sides[1] > sides[2];
}

int Year2016::Day3Part1(const std::string &input)
{
    auto triangleCount { 0 };
    auto ints { readInts(input) };
    for (size_t i { 0 }; i < ints.size(); i+=3)
    {
        std::vector<int> sides { ints[i], ints[i + 1], ints[i + 2] };
        std::sort(sides.begin(), sides.end());
        if (isTriangle(sides)) {
            ++triangleCount;
        }
    }
    return triangleCount;
}

int Year2016::Day3Part2(const std::string &input)
{
    auto triangleCount { 0 };
    auto ints { readInts(input) };
    for (size_t i { 0 }; i < ints.size(); i+=9)
    {
        std::vector<int> t1 { ints[i], ints[i + 3], ints[i + 6] };
        std::vector<int> t2 { ints[i + 1], ints[i + 4], ints[i + 7] };
        std::vector<int> t3 { ints[i + 2], ints[i + 5], ints[i + 8] };
        if (isTriangle(t1)) {
            ++triangleCount;
        }
        if (isTriangle(t2)) {
            ++triangleCount;
        }
        if (isTriangle(t3)) {
            ++triangleCount;
        }
    }
    return triangleCount;
}
