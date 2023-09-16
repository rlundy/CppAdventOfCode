#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>

#include "Year2019.hpp"
#include "Util.hpp"
#include "IntCode.hpp"

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
    for (auto a { 0 }; a < 100; a++)
    for (auto b { 0 }; b < 100; b++) {
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
