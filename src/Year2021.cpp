#include <sstream>
#include <cstdint>

#include "Year2021.hpp"
#include "Util.hpp"
#include "Parser.hpp"

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
        std::string currentDirection;
        int currentDistance;
        Parser(dir) >> currentDirection >> currentDistance;
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
        std::string instruction;
        int amount;
        Parser(dir) >> instruction >> amount;
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

int Year2021::Day3Part1(const std::string &input)
{
    return -1;
}

int Year2021::Day3Part2(const std::string &input)
{
    return -1;
}
