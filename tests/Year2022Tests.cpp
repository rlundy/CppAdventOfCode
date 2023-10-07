#include "catch_amalgamated.hpp"
#include "Year2022.hpp"
#include "Rucksack.hpp"

TEST_CASE("Year 2022 Day 1 Part 1") {
    Year2022 y;
    auto test { std::bind(&Year2022::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("1000\n2000\n3000\n\n4000\n\n5000\n6000\n\n7000\n8000\n9000\n\n10000") == 24000);
}

TEST_CASE("Year 2022 Day 1 Part 2") {
    Year2022 y;
    auto test { std::bind(&Year2022::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("1000\n2000\n3000\n\n4000\n\n5000\n6000\n\n7000\n8000\n9000\n\n10000") == 45000);
}

TEST_CASE("Year 2022 Day 2 Part 1") {
    Year2022 y;
    auto test { std::bind(&Year2022::Day2Part1, &y, std::placeholders::_1) };
    CHECK(test("A Y\nB X\nC Z") == 15);
}

TEST_CASE("Year 2022 Day 2 Part 2") {
    Year2022 y;
    auto test { std::bind(&Year2022::Day2Part2, &y, std::placeholders::_1) };
    CHECK(test("A Y\nB X\nC Z") == 12);
}

TEST_CASE("Year 2022 Day 3 Part 1") {
    Year2022 y;
    auto test { std::bind(&Year2022::Day3Part1, &y, std::placeholders::_1) };
    CHECK(test("vJrwpWtwJgWrhcsFMMfFFhFp\njqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\nPmmdzqPrVvPwwTWBwg\nwMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\nttgJtRGJQctTZtZT\nCrZsJsPPZsGzwwsLwLmpwMDw") == 157);
}

TEST_CASE("Year 2022 Day 3 Part 2") {
    Year2022 y;
    auto test { std::bind(&Year2022::Day3Part2, &y, std::placeholders::_1) };
    CHECK(test("vJrwpWtwJgWrhcsFMMfFFhFp\njqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL\nPmmdzqPrVvPwwTWBwg\nwMqvLMZHhHMvwLHjbvcjnnSBnvTQFn\nttgJtRGJQctTZtZT\nCrZsJsPPZsGzwwsLwLmpwMDw") == 70);
}

TEST_CASE("Rucksack item priority") {
    Rucksack r;
    CHECK(r.getPriority('a') == 1);
    CHECK(r.getPriority('z') == 26);
    CHECK(r.getPriority('A') == 27);
    CHECK(r.getPriority('Z') == 52);
}
