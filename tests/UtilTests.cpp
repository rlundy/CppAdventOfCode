#include <string>

#include "catch_amalgamated.hpp"
#include "Util.hpp"

TEST_CASE("Split") {
    SECTION("Happy path") {
        std::string original { "abcxdefxghi" };
        auto parts { split(original, "x") };
        CHECK(parts.at(0) == "abc");
        CHECK(parts.at(1) == "def");
        CHECK(parts.at(2) == "ghi");
    }
    SECTION("Empty string") {
        std::string original { "" };
        auto parts { split(original, "abc") };
        CHECK(parts.size() == 0);
    }
    SECTION("With empty sections") {
        std::string original { "abc\ndef\n\nghi\n\n\njkl\n\n" };
        auto parts { split(original, "\n") };
        CHECK(parts.at(0) == "abc");
        CHECK(parts.at(1) == "def");
        CHECK(parts.at(2) == "ghi");
        CHECK(parts.at(3) == "jkl");
    }
    SECTION("Keep empty sections") {
        std::string original { "abc\ndef\n\nghi\n\n\njkl\n\n" };
        auto parts { split(original, "\n", true) };
        CHECK(parts.at(0) == "abc");
        CHECK(parts.at(1) == "def");
        CHECK(parts.at(3) == "ghi");
        CHECK(parts.at(6) == "jkl");
        CHECK(parts.at(8) == "");
    }
}

TEST_CASE("Join") {
    std::vector<std::string> strings { "aaaaa", "bbb", "x", "y", "z" };
    auto joined { join(strings, "-") };
    CHECK(joined == "aaaaa-bbb-x-y-z");
}

TEST_CASE("Read ints") {
    SECTION("Leading and trailing white space") {
        std::string original { "\n  111 \n 222\n \n333\n\n444  555  \n" };
        auto ints { readInts(original) };
        CHECK(ints.at(0) == 111);
        CHECK(ints.at(1) == 222);
        CHECK(ints.at(2) == 333);
        CHECK(ints.at(3) == 444);
        CHECK(ints.at(4) == 555);
    }
    SECTION("No leading or trailing white space") {
        std::string original { "111 \n 222\n \n333\n\n444  555" };
        auto ints { readInts(original) };
        CHECK(ints.at(0) == 111);
        CHECK(ints.at(1) == 222);
        CHECK(ints.at(2) == 333);
        CHECK(ints.at(3) == 444);
        CHECK(ints.at(4) == 555);
    }
}

TEST_CASE("Contains") {
    CHECK(contains("ABCdefGHI", "def"));
    CHECK_FALSE(contains("ABCdefGHI", "DEF"));
}

TEST_CASE("Trim") {
    SECTION("Happy path") {
        std::string original { " abc def " };
        CHECK(trim(original) == std::string { "abc def" });
    }
    SECTION("Empty string") {
        std::string original { "" };
        CHECK(trim(original) == "");
    }
    SECTION("Only spaces") {
        std::string original { "     " };
        CHECK(trim(original) == "");
    }
}

TEST_CASE("Binary string to int") {
    std::string binary { "10101" };
    auto result { toInt(binary) };
    CHECK(result == 0b10101);
}
