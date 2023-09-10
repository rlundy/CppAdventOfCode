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

int Year2022::Day1Part1(const std::string& input) {
    auto calories { toCalories(input) };
    std::vector<int> calorieSums;
    int currentSum { 0 };
    int i { 0 };
    while (i < calories.size()) {
        auto current { calories[i] };
        if (current == 0) {
            calorieSums.push_back(currentSum);
            currentSum = 0;
        }
        else {
            currentSum += current;
        }
        i++;
    }
    return *std::max_element(calorieSums.cbegin(), calorieSums.cend());
}

int Year2022::Day1Part2(const std::string& input) {
    return -1;
}
