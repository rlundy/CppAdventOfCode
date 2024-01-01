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

    auto input2015_3 { getPuzzleInput(2015, 3) };
    t.time([&](){ showResult(2015, 3, 1, y2015.Day3Part1(input2015_3)); });
    t.time([&](){ showResult(2015, 3, 2, y2015.Day3Part2(input2015_3)); });

    // For now, skipping year 2015 day 4, which is about MD5 hashing.
    // It's slow and I'd rather do other things.
    // I'll come back to it later, maybe.

    std::cout << std::endl;

    Year2016 y2016;
    auto input2016_1 { getPuzzleInput(2016, 1) };
    t.time([&](){ showResult(2016, 1, 1, y2016.Day1Part1(input2016_1)); });
    t.time([&](){ showResult(2016, 1, 2, y2016.Day1Part2(input2016_1)); });

    auto input2016_2 { getPuzzleInput(2016, 2) };
    t.time([&](){ showResult(2016, 2, 1, y2016.Day2Part1(input2016_2)); });
    t.time([&](){ showResult(2016, 2, 2, y2016.Day2Part2(input2016_2)); });

    auto input2016_3 { getPuzzleInput(2016, 3) };
    t.time([&](){ showResult(2016, 3, 1, y2016.Day3Part1(input2016_3)); });
    t.time([&](){ showResult(2016, 3, 2, y2016.Day3Part2(input2016_3)); });

    auto input2016_4 { getPuzzleInput(2016, 4) };
    t.time([&](){ showResult(2016, 4, 1, y2016.Day4Part1(input2016_4)); });
    t.time([&](){ showResult(2016, 4, 2, y2016.Day4Part2(input2016_4)); });

    std::cout << std::endl;

    Year2017 y2017;
    auto input2017_1 { getPuzzleInput(2017, 1) };
    t.time([&](){ showResult(2017, 1, 1, y2017.Day1Part1(input2017_1)); });
    t.time([&](){ showResult(2017, 1, 2, y2017.Day1Part2(input2017_1)); });

    auto input2017_2 { getPuzzleInput(2017, 2) };
    t.time([&](){ showResult(2017, 2, 1, y2017.Day2Part1(input2017_2)); });
    t.time([&](){ showResult(2017, 2, 2, y2017.Day2Part2(input2017_2)); });

    auto input2017_3 { getPuzzleInput(2017, 3) };
    t.time([&](){ showResult(2017, 3, 1, y2017.Day3Part1(input2017_3)); });
    t.time([&](){ showResult(2017, 3, 2, y2017.Day3Part2(input2017_3)); });

    auto input2017_4 { getPuzzleInput(2017, 4) };
    t.time([&](){ showResult(2017, 4, 1, y2017.Day4Part1(input2017_4)); });
    t.time([&](){ showResult(2017, 4, 2, y2017.Day4Part2(input2017_4)); });

    std::cout << std::endl;

    Year2018 y2018;
    auto input2018_1 { getPuzzleInput(2018, 1) };
    t.time([&](){ showResult(2018, 1, 1, y2018.Day1Part1(input2018_1)); });
    t.time([&](){ showResult(2018, 1, 2, y2018.Day1Part2(input2018_1)); });

    auto input2018_2 { getPuzzleInput(2018, 2) };
    t.time([&](){ showResult(2018, 2, 1, y2018.Day2Part1(input2018_2)); });
    t.time([&](){ showResult(2018, 2, 2, y2018.Day2Part2(input2018_2)); });

    auto input2018_3 { getPuzzleInput(2018, 3) };
    t.time([&](){ showResult(2018, 3, 1, y2018.Day3Part1(input2018_3)); });
    t.time([&](){ showResult(2018, 3, 2, y2018.Day3Part2(input2018_3)); });

    std::cout << std::endl;

    Year2019 y2019;
    auto input2019_1 { getPuzzleInput(2019, 1) };
    t.time([&](){ showResult(2019, 1, 1, y2019.Day1Part1(input2019_1)); });
    t.time([&](){ showResult(2019, 1, 2, y2019.Day1Part2(input2019_1)); });

    auto input2019_2 { getPuzzleInput(2019, 2) };
    t.time([&](){ showResult(2019, 2, 1, y2019.Day2Part1(input2019_2)); });
    t.time([&](){ showResult(2019, 2, 2, y2019.Day2Part2(input2019_2)); });

    auto input2019_3 { getPuzzleInput(2019, 3) };
    t.time([&](){ showResult(2019, 3, 1, y2019.Day3Part1(input2019_3)); });
    t.time([&](){ showResult(2019, 3, 2, y2019.Day3Part2(input2019_3)); });

    std::cout << std::endl;

    Year2020 y2020;
    auto input2020_1 { getPuzzleInput(2020, 1) };
    t.time([&](){ showResult(2020, 1, 1, y2020.Day1Part1(input2020_1)); });
    t.time([&](){ showResult(2020, 1, 2, y2020.Day1Part2(input2020_1)); });

    auto input2020_2 { getPuzzleInput(2020, 2) };
    t.time([&](){ showResult(2020, 2, 1, y2020.Day2Part1(input2020_2)); });
    t.time([&](){ showResult(2020, 2, 2, y2020.Day2Part2(input2020_2)); });

    auto input2020_3 { getPuzzleInput(2020, 3) };
    t.time([&](){ showResult(2020, 3, 1, y2020.Day3Part1(input2020_3)); });
    t.time([&](){ showResult(2020, 3, 2, y2020.Day3Part2(input2020_3)); });

    std::cout << std::endl;

    Year2021 y2021;
    auto input2021_1 { getPuzzleInput(2021, 1) };
    t.time([&](){ showResult(2021, 1, 1, y2021.Day1Part1(input2021_1)); });
    t.time([&](){ showResult(2021, 1, 2, y2021.Day1Part2(input2021_1)); });

    auto input2021_2 { getPuzzleInput(2021, 2) };
    t.time([&](){ showResult(2021, 2, 1, y2021.Day2Part1(input2021_2)); });
    t.time([&](){ showResult(2021, 2, 2, y2021.Day2Part2(input2021_2)); });

    auto input2021_3 { getPuzzleInput(2021, 3) };
    t.time([&](){ showResult(2021, 3, 1, y2021.Day3Part1(input2021_3)); });
    t.time([&](){ showResult(2021, 3, 2, y2021.Day3Part2(input2021_3)); });

    std::cout << std::endl;

    Year2022 y2022;
    auto input2022_1 { getPuzzleInput(2022, 1) };
    t.time([&](){ showResult(2022, 1, 1, y2022.Day1Part1(input2022_1)); });
    t.time([&](){ showResult(2022, 1, 2, y2022.Day1Part2(input2022_1)); });

    auto input2022_2 { getPuzzleInput(2022, 2) };
    t.time([&](){ showResult(2022, 2, 1, y2022.Day2Part1(input2022_2)); });
    t.time([&](){ showResult(2022, 2, 2, y2022.Day2Part2(input2022_2)); });

    auto input2022_3 { getPuzzleInput(2022, 3) };
    t.time([&](){ showResult(2022, 3, 1, y2022.Day3Part1(input2022_3)); });
    t.time([&](){ showResult(2022, 3, 2, y2022.Day3Part2(input2022_3)); });
}
