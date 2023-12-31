#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <numeric>
#include <set>

#include "Year2022.hpp"
#include "Util.hpp"
#include "Parser.hpp"
#include "Rucksack.hpp"

std::vector<int> toCalories(const std::string& input) {
    std::vector<int> calories;
    auto calorieTexts { split(input, "\n", true) };
    std::for_each(calorieTexts.begin(), calorieTexts.end(), [](std::string& calorieText) { if (calorieText.empty()) { calorieText = "0"; } });
    std::transform(calorieTexts.cbegin(), calorieTexts.cend(), std::back_inserter(calories), [](const std::string& calorieText){ return std::stoi(calorieText); });
    return calories;
}

std::vector<int> toCalorieSums(const std::string& input) {
    auto calories { toCalories(input) };
    std::vector<int> calorieSums;
    int currentSum { 0 };
    int current { 0 };
    for (auto i { 0 }; i < calories.size(); ++i) {
        current = calories[i];
        if (current == 0) {
            calorieSums.push_back(currentSum);
            currentSum = 0;
        }
        else {
            currentSum += current;
        }
    }
    calorieSums.push_back(currentSum);
    return calorieSums;
}

int Year2022::Day1Part1(const std::string& input) {
    return maxInt(toCalorieSums(input));
}

int Year2022::Day1Part2(const std::string& input) {
    auto calorieSums { toCalorieSums(input) };
    std::partial_sort(calorieSums.rbegin(), calorieSums.rend() - 2, calorieSums.rend());
    return calorieSums[0] + calorieSums[1] + calorieSums[2];
}

RpsResult Year2022::getScore(RPS hisPlay, RPS myPlay) {
    if (hisPlay == myPlay) {
        return RpsResult::Draw;
    }
    if (hisPlay == RPS::Rock) {
        if (myPlay == RPS::Scissors) {
            return RpsResult::Loss;
        }
        else if (myPlay == RPS::Paper) {
            return RpsResult::Win;
        }
    }
    else if (hisPlay == RPS::Scissors) {
        if (myPlay == RPS::Rock) {
            return RpsResult::Win;
        }
        else if (myPlay == RPS::Paper) {
            return RpsResult::Loss;
        }
    }
    else if (hisPlay == RPS::Paper) {
        if (myPlay == RPS::Rock) {
            return RpsResult::Loss;
        }
        else if (myPlay == RPS::Scissors) {
            return RpsResult::Win;
        }
    }
    throw std::logic_error("Invalid play.");
}

RPS Year2022::getPlay(RPS hisPlay, RpsResult expectedResult) {
    if (expectedResult == RpsResult::Draw) {
        return hisPlay;
    }
    if (hisPlay == RPS::Rock) {
        if (expectedResult == RpsResult::Win) {
            return RPS::Paper;
        }
        else if (expectedResult == RpsResult::Loss) {
            return RPS::Scissors;
        }
    }
    else if (hisPlay == RPS::Scissors) {
        if (expectedResult == RpsResult::Win) {
            return RPS::Rock;
        }
        else if (expectedResult == RpsResult::Loss) {
            return RPS::Paper;
        }
    }
    else if (hisPlay == RPS::Paper) {
        if (expectedResult == RpsResult::Win) {
            return RPS::Scissors;
        }
        else if (expectedResult == RpsResult::Loss) {
            return RPS::Rock;
        }
    }
    throw std::logic_error("Invalid play and expected result combination.");
}

RPS Year2022::asPlay(char letter) {
    switch (letter) {
        case 'A':
        case 'X':
            return RPS::Rock;
        case 'B':
        case 'Y':
            return RPS::Paper;
        case 'C':
        case 'Z':
            return RPS::Scissors;
        default:
            throw std::logic_error((std::ostringstream() << "Bad play: " << letter).str());
    }
}

RpsResult Year2022::asExpectedResult(char letter) {
    switch (letter) {
        case 'X': return RpsResult::Loss;
        case 'Y': return RpsResult::Draw;
        case 'Z': return RpsResult::Win;
        default: throw std::logic_error((std::ostringstream() << "Bad expected result: " << letter).str());
    }
}

int Year2022::Day2Part1(const std::string &input)
{
    auto rounds { split(input, "\n") };
    auto totalScore { 0 };
    for (auto round : rounds) {
        Parser parser(round);
        char hisPlayChar, myPlayChar;
        parser >> hisPlayChar >> myPlayChar;
        auto hisPlay { asPlay(hisPlayChar) };
        auto myPlay { asPlay(myPlayChar) };
        auto score { getScore(hisPlay, myPlay) };
        totalScore += (int)score + (int)myPlay;
    }
    return totalScore;
}

int Year2022::Day2Part2(const std::string &input)
{
    auto rounds { split(input, "\n") };
    auto totalScore { 0 };
    for (auto round : rounds) {
        char hisPlayChar, expectedResultChar;
        Parser parser(round);
        parser >> hisPlayChar >> expectedResultChar;
        auto hisPlay { asPlay(hisPlayChar) };
        auto expectedResult { asExpectedResult(expectedResultChar) };
        auto myPlay { getPlay(hisPlay, expectedResult) };
        auto score { getScore(hisPlay, myPlay) };
        totalScore += (int)score + (int)myPlay;
    }
    return totalScore;
}

int Year2022::Day3Part1(const std::string &input)
{
    auto rucksackTexts { split(input, "\n") };
    std::vector<Rucksack> rucksacks;
    std::for_each(rucksackTexts.cbegin(), rucksackTexts.cend(), [&rucksacks](std::string rucksackText){ rucksacks.emplace_back(rucksackText); });
    auto total { std::accumulate(rucksacks.cbegin(), rucksacks.cend(), 0, [](auto runningTotal, Rucksack r){ return runningTotal + r.getMisplaceItemPriority(); }) };
    return total;
}

int Year2022::Day3Part2(const std::string &input)
{
    Rucksack r;
    auto sharedItemSums { 0 };
    auto rucksackTexts { split(input, "\n") };
    for (auto i { 0 }; i < rucksackTexts.size(); i += 3) {
        auto r1 { rucksackTexts[i] };
        auto r2 { rucksackTexts[i + 1] };
        auto r3 { rucksackTexts[i + 2] };
        std::set<char> items1;
        std::set<char> items2;
        std::set<char> items3;
        std::set<char> possibleDuplicates;
        std::for_each(r1.cbegin(), r1.cend(), [&items1](char ch){ items1.insert(ch); });
        std::for_each(r2.cbegin(), r2.cend(), [&items2](char ch){ items2.insert(ch); });
        std::for_each(r3.cbegin(), r3.cend(), [&items3](char ch){ items3.insert(ch); });

        std::for_each(items2.cbegin(), items2.cend(), [&items1, &items2, &possibleDuplicates](char ch){
            auto result { items1.insert(ch) };
            if (!result.second) {
                possibleDuplicates.insert(ch);
            }
        });
        for (auto item : items3) {
            auto result { possibleDuplicates.insert(item) };
            if (!result.second) {
                sharedItemSums += r.getPriority(item);
                break;
            }
        }
    }
    return sharedItemSums;
}
