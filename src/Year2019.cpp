#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>

#include "Year2019.hpp"
#include "Util.hpp"

int Year2019::getFuel(const int mass) {
    return mass / 3 - 2;
}

int Year2019::getFuelRecursive(const int mass) {
    auto currentMass { mass };
    auto fuel { 0 };
    while (currentMass > 0) {
        auto newFuel { std::max(getFuel(currentMass), 0) };
        fuel += newFuel;
        currentMass = newFuel;
    }
    return fuel;
}

int Year2019::Day1Part1(const std::string &input)
{
    auto massesText { split(input, "\n") };
    auto masses { textToInt(massesText) };
    std::vector<int> fuels;
    std::transform(masses.cbegin(), masses.cend(), std::back_inserter(fuels), [this](int mass){ return getFuel(mass); });
    return std::accumulate(fuels.cbegin(), fuels.cend(), 0);
}

int Year2019::Day1Part2(const std::string &input)
{
    auto massesText { split(input, "\n") };
    auto masses { textToInt(massesText) };
    std::vector<int> fuels;
    std::transform(masses.cbegin(), masses.cend(), std::back_inserter(fuels), [this](int mass){ return getFuelRecursive(mass); });
    return std::accumulate(fuels.cbegin(), fuels.cend(), 0);
}
