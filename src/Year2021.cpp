#include <sstream>
#include <cstdint>
#include <stdexcept>

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
    std::ostringstream mostCommon;
    std::ostringstream leastCommon;
    auto numbers { split(input, "\n") };
    const auto singleNumberLength { numbers[0].size() };
    for (auto i { 0 }; i < singleNumberLength; ++i) {
        int zeros { 0 };
        int ones { 0 };
        for (auto n : numbers) {
            n[i] == '0' ? ++zeros : ++ones;
        }
        mostCommon << (zeros > ones ? '0' : '1');
        leastCommon << (zeros > ones ? '1' : '0');
    }
    auto mostCommonDec = toInt(mostCommon.str());
    auto leastCommonDec = toInt(leastCommon.str());
    return mostCommonDec * leastCommonDec;
}

void Year2021::filterValues(std::vector<std::string>& values, char preferredZeroChar, char preferredOneChar) {
    const auto singleNumberLength = values[0].size();
    for (auto i { 0 }; i < singleNumberLength; ++i) {
        int zeros { 0 };
        int ones { 0 };
        for (auto n : values) {
            n[i] == '0' ? ++zeros : ++ones;
        }
        auto removeChar { zeros > ones ? preferredZeroChar : preferredOneChar };
        std::erase_if(values, [i, removeChar](std::string n){ return n[i] == removeChar; });
        if (values.size() == 1) {
            break;
        }
    }
}

int Year2021::Day3Part2(const std::string &input)
{
    auto o2numbers { split(input, "\n") };
    auto co2numbers { split(input, "\n") };

    filterValues(o2numbers, '0', '1');
    filterValues(co2numbers, '1', '0');

    auto finalO2number { toInt(o2numbers.at(0)) };
    auto finalCo2number { toInt(co2numbers.at(0)) };

    return finalO2number * finalCo2number;
}
