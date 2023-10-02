#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
#include <unordered_set>
#include <stdexcept>
#include <set>
#include <map>

#include "Year2019.hpp"
#include "Util.hpp"
#include "IntCode.hpp"
#include "Parser.hpp"
#include "Stopwatch.hpp"

int Year2019::getFuel(const int mass)
{
    return mass / 3 - 2;
}

int Year2019::getFuelRecursive(const int mass) {
    auto currentMass { mass };
    auto fuel { 0 };
    while (currentMass > 0) {
        fuel += (currentMass = std::max(getFuel(currentMass), 0));
    }
    return fuel;
}

int Year2019::Day1Part1(const std::string& input)
{
    auto masses { inputToVector(input) };
    std::vector<int> fuels;
    std::transform(masses.cbegin(), masses.cend(), std::back_inserter(fuels), [this](int mass){ return getFuel(mass); });
    return sum(fuels);
}

int Year2019::Day1Part2(const std::string& input)
{
    auto masses { inputToVector(input) };
    std::vector<int> fuels;
    std::transform(masses.cbegin(), masses.cend(), std::back_inserter(fuels), [this](int mass){ return getFuelRecursive(mass); });
    return sum(fuels);
}

int Year2019::Day2Part1(const std::string &input)
{
    IntCode ic { input };
    ic.replace(1, 12);
    ic.replace(2, 2);
    ic.process();
    return ic.getPosition(0);
}

int Year2019::Day2Part2(const std::string &input)
{
    std::vector<std::pair<int, int>> runValues;
    for (auto a { 0 }; a < 100; ++a)
    for (auto b { 0 }; b < 100; ++b) {
        runValues.push_back(std::make_pair(a, b));
    }

    IntCode ic { input };
    for (auto v : runValues) {
        ic.reboot();
        ic.replace(1, v.first);
        ic.replace(2, v.second);
        ic.process();
        if (ic.getPosition(0) == 19690720) {
            return 100 * v.first + v.second;
        }
    }
    return -1;
}

void Year2019::doStep(char direction, int& x, int& y) {
    switch (direction) {
        case 'D': --y; break;
        case 'U': ++y; break;
        case 'L': --x; break;
        case 'R': ++x; break;
        default: throw std::invalid_argument("Invalid direction.");
    }
}

int Year2019::Day3Part1(const std::string &input)
{
    auto wires { split(input, "\n") };

    int x1 { 0 }, y1 { 0 };
    auto w1steps { split(wires[0], ",") };
    std::set<std::pair<int, int>> w1positions;
    for (const auto& step : w1steps) {
        char direction;
        int distance;
        Parser(step) >> direction >> distance;
        for (auto x { 0 }; x < distance; ++x) {
            doStep(direction, x1, y1);
            w1positions.insert({x1, y1});
        }
    }

    int x2 { 0 }, y2 { 0 };
    auto w2steps { split(wires[1], ",") };
    std::set<std::pair<int, int>> intersections;
    for (const auto& step : w2steps) {
        char direction;
        int distance;
        Parser(step) >> direction >> distance;
        for (auto y { 0 }; y < distance; ++y) {
            doStep(direction, x2, y2);
            if (w1positions.contains({x2, y2})) {
                intersections.insert({x2, y2});
            }
        }
    }

    std::vector<int> distances;
    std::transform(
        intersections.cbegin(),
        intersections.cend(),
        std::back_inserter(distances),
        [](std::pair<int, int> point){ return abs(point.first) + abs(point.second); });
    auto leastDistance { std::min_element(distances.cbegin(), distances.cend()) };
    if (leastDistance != distances.cend()) {
        return *leastDistance;
    }
    return -1;
}

std::vector<std::pair<int, int>> Year2019::writeSteps(const std::string& wire) {
    std::vector<std::pair<int, int>> wirePositions;
    wirePositions.push_back(std::make_pair(0, 0));
    int xPos { 0 }, yPos { 0 };
    auto wireSteps { split(wire, ",") };
    for (const auto& step : wireSteps) {
        char direction;
        int distance;
        Parser(step) >> direction >> distance;
        for (auto x { 0 }; x < distance; ++x) {
            doStep(direction, xPos, yPos);
            wirePositions.push_back({ xPos, yPos });
        }
    }
    return wirePositions;
}

int Year2019::Day3Part2(const std::string &input)
{
    auto wires = split(input, "\n");

    auto w1positions { writeSteps(wires[0]) };
    auto w2positions { writeSteps(wires[1]) };

    std::map<std::string, int> w1distances;
    for (auto i { 0 }; i < w1positions.size(); ++i) {
        auto item { w1positions[i] };
        w1distances.insert({ toKey(item.first, item.second), i });
    }

    std::map<std::string, int> w2distances;
    for (auto i { 0 }; i < w2positions.size(); ++i) {
        auto item { w2positions[i] };
        w2distances.insert({ toKey(item.first, item.second), i });
    }

    std::vector<int> intersectionDistances;
    for (auto item : w1distances) {
        if (item.second > 0 && w2distances.contains(item.first))
            intersectionDistances.push_back(item.second + w2distances[item.first]);
    }

    std::partial_sort(intersectionDistances.begin(), intersectionDistances.begin() + 1, intersectionDistances.end());
    return intersectionDistances.at(0);
}
