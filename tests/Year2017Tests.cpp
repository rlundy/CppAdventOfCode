#include <string>
#include <unordered_map>
#include "catch_amalgamated.hpp"
#include "Year2017.hpp"

TEST_CASE("Year 2017 Day 1 Part 1") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("1122") == 3);
    CHECK(test("1111") == 4);
    CHECK(test("1234") == 0);
    CHECK(test("91212129") == 9);
}

TEST_CASE("Year 2017 Day 1 Part 2") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("1212") == 6);
    CHECK(test("1221") == 0);
    CHECK(test("123425") == 4);
    CHECK(test("123123") == 12);
    CHECK(test("12131415") == 4);
}

TEST_CASE("Year 2017 Day 2 Part 1") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day2Part1, &y, std::placeholders::_1) };
    CHECK(test("5\t1\t9\t5\n7\t5\t3\n2\t4\t6\t8") == 18);
}

TEST_CASE("Year 2017 Day 2 Part 2") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day2Part2, &y, std::placeholders::_1) };
    CHECK(test("5\t9\t2\t8\n9\t4\t7\t3\n3\t8\t6\t5") == 9);
}

TEST_CASE("Year 2017 Day 3 Part 1") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day3Part1, &y, std::placeholders::_1) };
    CHECK(test("1") == 0);
    CHECK(test("12") == 3);
    CHECK(test("23") == 2);
    CHECK(test("1024") == 31);
}

TEST_CASE("Can get sum of surrounding positions") {
    Year2017 y;
    std::unordered_map<std::string, int> positions;
    positions.emplace("1,1", 3);
    positions.emplace("1,0", 4);
    positions.emplace("0,1", 6);
    positions.emplace("2,2", 99);
    positions.emplace("3,0", 88);
    auto sum { y.getSumOfSurroundings(0, 0, positions) };
    CHECK(sum == 13);
}

TEST_CASE("Year 2017 Day 3 Part 2") {
    Year2017 y;
    auto test { std::bind(&Year2017::Day3Part2, &y, std::placeholders::_1) };
    CHECK(test("1") == 2);
    CHECK(test("2") == 4);
    CHECK(test("4") == 5);
    CHECK(test("5") == 10);
    CHECK(test("10") == 11);
    CHECK(test("11") == 23);
    CHECK(test("23") == 25);
    CHECK(test("25") == 26);
    CHECK(test("26") == 54);
    CHECK(test("54") == 57);
    CHECK(test("57") == 59);
    CHECK(test("59") == 122);
    CHECK(test("122") == 133);
    CHECK(test("133") == 142);
    CHECK(test("142") == 147);
    CHECK(test("147") == 304);
    CHECK(test("304") == 330);
    CHECK(test("330") == 351);
    CHECK(test("351") == 362);
    CHECK(test("362") == 747);
    CHECK(test("747") == 806);
}
