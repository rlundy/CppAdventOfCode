#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>

#include "Year2018.hpp"
#include "Util.hpp"

int Year2018::Day1Part1(const std::string& input)
{
    return sum(inputToVector(input));
}

int Year2018::Day1Part2(const std::string& input)
{
    std::set<int> usedFrequencies;
    auto frequencies { inputToVector(input) };
    auto sum { 0 };
    usedFrequencies.insert(sum);

    auto current { 0 };
    while (true) {
        if (current >= frequencies.size()) {
            current = 0;
        }
        auto f { frequencies[current] };
        sum += f;
        auto inserted { usedFrequencies.insert(sum) };
        if (!inserted.second) {
            return sum;
        }
        current++;
    }

    return -1;
}
