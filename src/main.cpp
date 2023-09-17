#include <iostream>
#include <functional>

#include "Year2015.hpp"
#include "Year2016.hpp"
#include "Year2017.hpp"
#include "Year2018.hpp"
#include "Year2019.hpp"
#include "Year2020.hpp"
#include "Year2021.hpp"
#include "Year2022.hpp"
#include "Util.hpp"
#include "Timer.hpp"

int main() {
    std::cout << std::endl;

    Timer t;

    Year2015 y2015;
    auto input2015_1 { getPuzzleInput(2015, 1) };
    t.time([&](){ showResult(2015, 1, 1, y2015.Day1Part1(input2015_1)); });
    t.time([&](){ showResult(2015, 1, 2, y2015.Day1Part2(input2015_1)); });

    auto input2015_2 { getPuzzleInput(2015, 2) };
    t.time([&](){ showResult(2015, 2, 1, y2015.Day2Part1(input2015_2)); });
    t.time([&](){ showResult(2015, 2, 2, y2015.Day2Part2(input2015_2)); });

    std::cout << std::endl;

    Year2016 y2016;
    auto input2016_1 { getPuzzleInput(2016, 1) };
    t.time([&](){ showResult(2016, 1, 1, y2016.Day1Part1(input2016_1)); });
    t.time([&](){ showResult(2016, 1, 2, y2016.Day1Part2(input2016_1)); });

    auto input2016_2 { getPuzzleInput(2016, 2) };
    t.time([&](){ showResult(2016, 2, 1, y2016.Day2Part1(input2016_2)); });
    t.time([&](){ showResult(2016, 2, 2, y2016.Day2Part2(input2016_2)); });

    std::cout << std::endl;

    Year2017 y2017;
    auto input2017_1 { getPuzzleInput(2017, 1) };
    t.time([&](){ showResult(2017, 1, 1, y2017.Day1Part1(input2017_1)); });
    t.time([&](){ showResult(2017, 1, 2, y2017.Day1Part2(input2017_1)); });

    auto input2017_2 { getPuzzleInput(2017, 2) };
    t.time([&](){ showResult(2017, 2, 1, y2017.Day2Part1(input2017_2)); });
    t.time([&](){ showResult(2017, 2, 2, y2017.Day2Part2(input2017_2)); });

    std::cout << std::endl;

    Year2018 y2018;
    auto input2018_1 { getPuzzleInput(2018, 1) };
    t.time([&](){ showResult(2018, 1, 1, y2018.Day1Part1(input2018_1)); });
    t.time([&](){ showResult(2018, 1, 2, y2018.Day1Part2(input2018_1)); });

    auto input2018_2 { getPuzzleInput(2018, 2) };
    t.time([&](){ showResult(2018, 2, 1, y2018.Day2Part1(input2018_2)); });
    t.time([&](){ showResult(2018, 2, 2, y2018.Day2Part2(input2018_2)); });

    std::cout << std::endl;

    Year2019 y2019;
    auto input2019_1 { getPuzzleInput(2019, 1) };
    t.time([&](){ showResult(2019, 1, 1, y2019.Day1Part1(input2019_1)); });
    t.time([&](){ showResult(2019, 1, 2, y2019.Day1Part2(input2019_1)); });

    auto input2019_2 { getPuzzleInput(2019, 2) };
    t.time([&](){ showResult(2019, 2, 1, y2019.Day2Part1(input2019_2)); });
    t.time([&](){ showResult(2019, 2, 2, y2019.Day2Part2(input2019_2)); });

    std::cout << std::endl;

    Year2020 y2020;
    auto input2020_1 { getPuzzleInput(2020, 1) };
    t.time([&](){ showResult(2020, 1, 1, y2020.Day1Part1(input2020_1)); });
    t.time([&](){ showResult(2020, 1, 2, y2020.Day1Part2(input2020_1)); });

    auto input2020_2 { getPuzzleInput(2020, 2) };
    t.time([&](){ showResult(2020, 2, 1, y2020.Day2Part1(input2020_2)); });
    t.time([&](){ showResult(2020, 2, 2, y2020.Day2Part2(input2020_2)); });

    std::cout << std::endl;

    Year2021 y2021;
    auto input2021_1 { getPuzzleInput(2021, 1) };
    t.time([&](){ showResult(2021, 1, 1, y2021.Day1Part1(input2021_1)); });
    t.time([&](){ showResult(2021, 1, 2, y2021.Day1Part2(input2021_1)); });

    auto input2021_2 { getPuzzleInput(2021, 2) };
    t.time([&](){ showResult(2021, 2, 1, y2021.Day2Part1(input2021_2)); });
    t.time([&](){ showResult(2021, 2, 2, y2021.Day2Part2(input2021_2)); });

    std::cout << std::endl;

    Year2022 y2022;
    auto input2022_1 { getPuzzleInput(2022, 1) };
    t.time([&](){ showResult(2022, 1, 1, y2022.Day1Part1(input2022_1)); });
    t.time([&](){ showResult(2022, 1, 2, y2022.Day1Part2(input2022_1)); });
}
