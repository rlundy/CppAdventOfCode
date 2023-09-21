#include <sstream>
#include <cstdint>

#include "Year2021.hpp"

#include "Util.hpp"

int Year2021::Day1Part1(const std::string& input) {
    auto depths { inputToVector(input) };
    auto increases { 0 };
    for (auto i { 0 }; i < depths.size() - 1; ++i) {
        auto from { depths[i] };
        auto to { depths[i + 1] };
        if (to > from) {
            ++increases;
        }
    }
    return increases;
}

int Year2021::Day1Part2(const std::string& input) {
    auto depths { inputToVector(input) };
    auto increases { 0 };
    for (auto i { 0 }; i < depths.size() - 3; ++i) {
        auto a1 { depths[i] };
        auto a2 { depths[i + 1] };
        auto a3 { depths[i + 2] };
        auto a4 { depths[i + 3] };
        auto first { a1 + a2 + a3 };
        auto second { a2 + a3 + a4 };
        if (second > first) {
            ++increases;
        }
    }
    return increases;
}

int64_t Year2021::Day2Part1(const std::string &input)
{
    int64_t distance { 0 };
    int64_t depth { 0 };
    auto directions { split(input, "\n") };
    for (auto dir : directions) {
        auto currentDirParts { split(dir, " ") };
        auto currentDirection { currentDirParts[0] };
        auto currentDistanceText { currentDirParts[1] };
        auto currentDistance = std::stoi(currentDistanceText);
        if (currentDirection == "forward") {
            distance += currentDistance;
        }
        else if (currentDirection == "up") {
            depth -= currentDistance;
        }
        else if (currentDirection == "down") {
            depth += currentDistance;
        }
        else {
            throw std::logic_error((std::ostringstream() << "Invalid direction: " << dir).str());
        }
    }
    return distance * depth;
}

int64_t Year2021::Day2Part2(const std::string &input)
{
    int64_t aim { 0 };
    int64_t horizontalPos { 0 };
    int64_t depth { 0 };
    auto directions { split(input, "\n") };
    for (auto dir : directions) {
        auto parts { split(dir, " ") };
        auto instruction { parts[0] };
        auto amountText { parts[1] };
        auto amount = std::stoi(amountText);
        if (instruction == "up") {
            aim -= amount;
        }
        else if (instruction == "down") {
            aim += amount;
        }
        else if (instruction == "forward") {
            horizontalPos += amount;
            depth += aim * amount;
        }
        else {
            throw std::logic_error((std::ostringstream() << "Invalid direction: " << dir).str());
        }
    }
    return horizontalPos * depth;
}
