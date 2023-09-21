#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <string>
#include <sstream>
#include <unordered_set>

#include "Year2015.hpp"
#include "Util.hpp"

int Year2015::Day1Part1(const std::string& input)
{
    return std::accumulate(
        input.cbegin(),
        input.cend(),
        0,
        [](int acc, char ch){ if (ch == '(') return acc + 1; else if (ch == ')') return acc - 1; else return acc; }
    );
}

int Year2015::Day1Part2(const std::string& input)
{
    auto floor { 0 };
    for (size_t i { 0 }; i < input.length(); ++i) {
        auto step { input[i] };
        if (step == '(') {
            ++floor;
        }
        else if (step == ')') {
            --floor;
        }
        else {
            throw std::logic_error("Invalid step: " + std::string(1, step));
        }
        if (floor < 0) {
            return i + 1;
        }
    }
    throw std::logic_error("Never entered the basement.");
}

std::tuple<int, int, int> parseDimensions(const std::string& dimensions) {
    auto const dimsText { split(dimensions, "x") };
    auto const dims { textToInt(dimsText) };
    if (dims.size() != 3) {
        throw std::length_error((std::ostringstream() << "Wrong number of box dimensions: " << dims.size()).str());
    }
    return std::make_tuple(dims[0], dims[1], dims[2]);
}

int Year2015::getWrappingPaper(const std::string& dimensions) {
    auto [l, w, h] { parseDimensions(dimensions) };
    auto const s1 { l * w };
    auto const s2 { w * h };
    auto const s3 { l * h };
    auto const minSide { std::min({ s1, s2, s3 }) };
    return s1 * 2 + s2 * 2 + s3 * 2 + minSide;
}

int Year2015::getRibbon(const std::string& dimensions)
{
    auto [l, w, h] { parseDimensions(dimensions) };
    auto const p1 { 2 * l + 2 * w };
    auto const p2 { 2 * l + 2 * h };
    auto const p3 { 2 * w + 2 * h };
    auto const smallest { std::min({ p1, p2, p3 }) };
    auto const bow { l * w * h };
    return smallest + bow;
}

int Year2015::Day2Part1(const std::string& input)
{
    auto const dimensions { split(input, "\n") };
    std::vector<int> paper;
    std::transform(
        dimensions.cbegin(),
        dimensions.cend(),
        std::back_inserter(paper),
        [this](const std::string& dim) { return this->getWrappingPaper(dim); }
    );
    return sum(paper);
}

int Year2015::Day2Part2(const std::string& input)
{
    auto const dimensions { split(input, "\n") };
    std::vector<int> ribbon;
    std::transform(
        dimensions.cbegin(),
        dimensions.cend(),
        std::back_inserter(ribbon),
        [this](const std::string& dim) { return this->getRibbon(dim); }
    );
    return sum(ribbon);
}

std::string Year2015::toText(int x, int y) {
    return (std::ostringstream() << x << "," << y).str();
}

int Year2015::Day3Part1(const std::string &input)
{
    std::unordered_set<std::string> houses;
    auto x { 0 }, y { 0 };
    houses.insert(toText(x, y));
    for (auto pos : input) {
        switch (pos) {
            case 'v':
                ++y;
                break;
            case '^':
                --y;
                break;
            case '<':
                --x;
                break;
            case '>':
                ++x;
                break;
        }
        houses.insert(toText(x, y));
    }
    return houses.size();
}

int Year2015::Day3Part2(const std::string &input)
{
    std::unordered_set<std::string> houses;
    auto x { 0 }, y { 0 }, rx { 0 }, ry { 0 };
    auto isRobo { false };
    houses.insert(toText(x, y));
    for (auto pos : input) {
        switch (pos) {
            case 'v':
                if (isRobo) ++ry; else ++y;
                break;
            case '^':
                if (isRobo) --ry; else --y;
                break;
            case '<':
                if (isRobo) --rx; else --x;
                break;
            case '>':
                if (isRobo) ++rx; else ++x;
                break;
        }
        if (isRobo) {
            houses.insert(toText(rx, ry));
        } else {
            houses.insert(toText(x, y));
        }
        isRobo = !isRobo;
    }
    return houses.size();
}
