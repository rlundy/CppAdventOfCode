#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

#include "Year2022.hpp"
#include "Util.hpp"

std::vector<int> toCalories(const std::string& input) {
    std::vector<int> calories;
    auto calorieTexts { split(input, "\n") };
    std::for_each(calorieTexts.begin(), calorieTexts.end(), [](std::string& calorieText) { if (calorieText.empty()) { calorieText = "0"; } });
    std::transform(calorieTexts.cbegin(), calorieTexts.cend(), std::back_inserter(calories), [](const std::string& calorieText){ return std::stoi(calorieText); });
    return calories;
}

std::vector<int> toCalorieSums(const std::string& input) {
    auto calories { toCalories(input) };
    std::vector<int> calorieSums;
    int currentSum { 0 };
    int i { 0 };
    int current { 0 };
    while (i < calories.size()) {
        current = calories[i];
        if (current == 0) {
            calorieSums.push_back(currentSum);
            currentSum = 0;
        }
        else {
            currentSum += current;
        }
        i++;
    }
    calorieSums.push_back(currentSum);
    return calorieSums;
}

int Year2022::Day1Part1(const std::string& input) {
    return maxInt(toCalorieSums(input));
}

int Year2022::Day1Part2(const std::string& input) {
    auto calorieSums = toCalorieSums(input);
    std::sort(calorieSums.begin(), calorieSums.end());
    std::reverse(calorieSums.begin(), calorieSums.end());
    return calorieSums[0] + calorieSums[1] + calorieSums[2];
}
