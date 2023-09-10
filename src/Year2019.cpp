#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>

#include "Year2019.hpp"
#include "Util.hpp"

int Year2019::Day1Part1(const std::string &input)
{
    auto massesText { split(input, "\n") };
    auto masses { textToInt(massesText) };
    std::vector<int> fuels;
    std::transform(masses.cbegin(), masses.cend(), std::back_inserter(fuels), [](int mass){ return mass / 3 - 2; });
    return std::accumulate(fuels.cbegin(), fuels.cend(), 0);
}

int Year2019::Day1Part2(const std::string &input)
{
    return -1;
}
