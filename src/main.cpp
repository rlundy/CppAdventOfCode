#include <iostream>
#include <functional>

#include "Year2015.hpp"
#include "Year2016.hpp"
#include "Year2017.hpp"
#include "Year2018.hpp"
#include "Year2019.hpp"
#include "Year2020.hpp"
#include "Year2021.hpp"
#include "Util.hpp"

void showResult(int year, int day, int part, int result) {
    auto puzzleInput { getPuzzleInput(year, day) };
    std::cout
        << "Year " << year
        << " day " << day
        << " part " << part << ": "
        << result << std::endl;
}

int main() {
    std::cout << std::endl;

    Year2015 y2015;
    auto input2015_1 { getPuzzleInput(2015, 1) };
    showResult(2015, 1, 1, y2015.Day1Part1(input2015_1));
    showResult(2015, 1, 2, y2015.Day1Part2(input2015_1));

    std::cout << std::endl;

    Year2016 y2016;
    auto input2016_1 { getPuzzleInput(2016, 1) };
    showResult(2016, 1, 1, y2016.Day1Part1(input2016_1));
    showResult(2016, 1, 2, y2016.Day1Part2(input2016_1));

    std::cout << std::endl;

    Year2017 y2017;
    auto input2017_1 { getPuzzleInput(2017, 1) };
    showResult(2017, 1, 1, y2017.Day1Part1(input2017_1));
    showResult(2017, 1, 2, y2017.Day1Part2(input2017_1));

    std::cout << std::endl;

    Year2018 y2018;
    auto input2018_1 { getPuzzleInput(2018, 1) };
    showResult(2018, 1, 1, y2018.Day1Part1(input2018_1));
    showResult(2018, 1, 2, y2018.Day1Part2(input2018_1));

    std::cout << std::endl;

    Year2019 y2019;
    auto input2019_1 { getPuzzleInput(2019, 1) };
    showResult(2019, 1, 1, y2019.Day1Part1(input2019_1));
    showResult(2019, 1, 2, y2019.Day1Part2(input2019_1));

    std::cout << std::endl;

    Year2020 y2020;
    auto input2020_1 { getPuzzleInput(2020, 1) };
    showResult(2020, 1, 1, y2020.Day1Part1(input2020_1));
    showResult(2020, 1, 2, y2020.Day1Part2(input2020_1));

    std::cout << std::endl;

    Year2021 y2021;
    auto input2021_1 { getPuzzleInput(2021, 1) };
    showResult(2021, 1, 1, y2021.Day1Part1(input2021_1));
    showResult(2021, 1, 2, y2021.Day1Part2(input2021_1));
}
