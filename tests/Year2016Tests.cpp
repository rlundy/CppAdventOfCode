#include "catch_amalgamated.hpp"
#include "Year2016.hpp"
#include "CompassDirection.hpp"

TEST_CASE("Year 2016 helper methods") {
    Year2016 y;
    auto newDirection { y.makeTurn(CompassDirection::NORTH, 'R') };
    CHECK(newDirection == CompassDirection::EAST);
    auto newDirection2 { y.makeTurn(CompassDirection::NORTH, 'L') };
    CHECK(newDirection2 == CompassDirection::WEST);
}

TEST_CASE("Year 2016 Day 1 Part 1") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("R2, L3") == 5);
    CHECK(test("R2, R2, R2") == 2);
    CHECK(test("R5, L5, R5, R3") == 12);
}

TEST_CASE("Year 2016 Day 1 Part 2") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("R8, R4, R4, R8") == 4);
}

TEST_CASE("Year 2016 Day 2 Part 1") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day2Part1, &y, std::placeholders::_1) };

    CHECK(test("ULL\nRRDDD\nLURDL\nUUUUD") == "1985");
    CHECK(test("UUULLL\nRDRURRR\nDLDLDLDL\nRURDRDR") == "1379");
}

TEST_CASE("Year 2016 Day 2 Part 2") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day2Part2, &y, std::placeholders::_1) };
    CHECK(test("ULL\nRRDDD\nLURDL\nUUUUD") == "5DB3");
}

TEST_CASE("Year 2016 Day 3 Part 1") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day3Part1, &y, std::placeholders::_1) };
    CHECK(test(" 5 10 25 \n 10 11 12 \n 1 1 13 \n 3 4 5 ") == 2);
}

TEST_CASE("Year 2016 Day 3 Part 2") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day3Part2, &y, std::placeholders::_1) };
    CHECK(test(" 5 10 1 \n 10 11 1 \n 25 12 13 ") == 1);
}

TEST_CASE("Year 2016 Day 4 Part 1") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day4Part1, &y, std::placeholders::_1) };
    CHECK(test("aaaaa-bbb-z-y-x-123[abxyz]\na-b-c-d-e-f-g-h-987[abcde]\nnot-a-real-room-404[oarel]\ntotally-real-room-200[decoy]") == 1514);
}

TEST_CASE("Year 2016 Day 4 Part 2") {
    Year2016 y;
    auto test { std::bind(&Year2016::Day4Part2, &y, std::placeholders::_1) };
    CHECK(test("") == 0);
}
