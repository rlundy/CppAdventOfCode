#include "catch_amalgamated.hpp"
#include "Year2019.hpp"
#include "IntCode.hpp"

TEST_CASE("Year 2019 Day 1 Part 1") {
    Year2019 y;
    auto test { std::bind(&Year2019::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("12") == 2);
    CHECK(test("14") == 2);
    CHECK(test("1969") == 654);
    CHECK(test("100756") == 33583);
}

TEST_CASE("Year 2019 Day 1 Part 2") {
    Year2019 y;
    auto test { std::bind(&Year2019::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("14") == 2);
    CHECK(test("1969") == 966);
    CHECK(test("100756") == 50346);
}

TEST_CASE("Year 2019 Day 3 Part 1") {
    Year2019 y;
    auto test { std::bind(&Year2019::Day3Part1, &y, std::placeholders::_1) };
    CHECK(test("R8,U5,L5,D3\nU7,R6,D4,L4") == 6);
    CHECK(test("R75,D30,R83,U83,L12,D49,R71,U7,L72\nU62,R66,U55,R34,D71,R55,D58,R83") == 159);
    CHECK(test("R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51\nU98,R91,D20,R16,D67,R40,U7,R15,U6,R7") == 135);
}

TEST_CASE("Year 2019 Day 3 Part 2") {

}
