#include "catch_amalgamated.hpp"
#include "Year2020.hpp"

TEST_CASE("Year 2020 Day 1 Part 1") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("1721\n979\n366\n299\n675\n1456") == 514579);
}

TEST_CASE("Year 2020 Day 1 Part 2") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("1721\n979\n366\n299\n675\n1456") == 241861950);
}

TEST_CASE("Year 2020 Day 2 Part 1") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day2Part1, &y, std::placeholders::_1) };
    CHECK(test("1-3 a: abcde\n1-3 b: cdefg\n2-9 c: ccccccccc") == 2);
}

TEST_CASE("Year 2020 Day 2 Part 2") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day2Part2, &y, std::placeholders::_1) };
    CHECK(y.IsValidPart2("1-3 a: abcde") == true);
    CHECK(y.IsValidPart2("1-3 b: cdefg") == false);
    CHECK(y.IsValidPart2("2-9 c: ccccccccc") == false);
    CHECK(test("1-3 a: abcde\n1-3 b: cdefg\n2-9 c: ccccccccc") == 1);
}

TEST_CASE("Year 2020 Day 3 Part 1") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day3Part1, &y, std::placeholders::_1) };
    CHECK(test("..##.......\n#...#...#..\n.#....#..#.\n..#.#...#.#\n.#...##..#.\n..#.##.....\n.#.#.#....#\n.#........#\n#.##...#...\n#...##....#\n.#..#...#.#") == 7);
}

TEST_CASE("Year 2020 Day 3 Part 2") {
    Year2020 y;
    auto test { std::bind(&Year2020::Day3Part2, &y, std::placeholders::_1) };
    CHECK(test("..##.......\n#...#...#..\n.#....#..#.\n..#.#...#.#\n.#...##..#.\n..#.##.....\n.#.#.#....#\n.#........#\n#.##...#...\n#...##....#\n.#..#...#.#") == 336);
}
