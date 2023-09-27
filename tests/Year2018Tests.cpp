#include "catch_amalgamated.hpp"
#include "Year2018.hpp"

TEST_CASE("Year 2018 Day 1 Part 1") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day1Part1, &y, std::placeholders::_1) };
    CHECK(test("+1\n-2\n+3\n+1") == 3);
    CHECK(test("+1\n+1\n+1") == 3);
    CHECK(test("+1\n+1\n-2") == 0);
    CHECK(test("-1\n-2\n-3") == -6);
}

TEST_CASE("Year 2018 Day 1 Part 2") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day1Part2, &y, std::placeholders::_1) };
    CHECK(test("+1\n-2\n+3\n+1") == 2);
    CHECK(test("+1\n-1") == 0);
    CHECK(test("+3\n+3\n+4\n-2\n-4") == 10);
    CHECK(test("-6\n+3\n+8\n+5\n-6") == 5);
    CHECK(test("+7\n+7\n-2\n-7\n-4") == 14);
}

TEST_CASE("Year 2018 Day 2 Part 1") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day2Part1, &y, std::placeholders::_1) };
    CHECK(test("abcdef\nbababc\nabbcde\nabcccd\naabcdd\nabcdee\nababab") == 12);
}

TEST_CASE("How does erase work?") {
    SECTION("Erase first char") {
        std::string text { "abcdef" };
        text.erase(0, 1);
        CHECK(text == "bcdef");
    }
    SECTION("Erase middle char") {
        std::string text { "abcdef" };
        text.erase(2, 1);
        CHECK(text == "abdef");
    }
    SECTION("Erase last char") {
        std::string text { "abcdef" };
        text.erase(5, 1);
        CHECK(text == "abcde");
    }
}

TEST_CASE("Year 2018 Day 2 Part 2") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day2Part2, &y, std::placeholders::_1) };
    CHECK(test("abcde\nfghij\nklmno\npqrst\nfguij\naxcye\nwvxyz") == "fgij");
}

TEST_CASE("Year 2018 Day 3 Part 1") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day3Part1, &y, std::placeholders::_1) };
    CHECK(test("#1 @ 1,3: 4x4\n#2 @ 3,1: 4x4\n#3 @ 5,5: 2x2") == 4);
}

TEST_CASE("Year 2018 Day 3 Part 2") {
    Year2018 y;
    auto test { std::bind(&Year2018::Day3Part2, &y, std::placeholders::_1) };
    CHECK(test("#1 @ 1,3: 4x4\n#2 @ 3,1: 4x4\n#3 @ 5,5: 2x2") == 3);
}
