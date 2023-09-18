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
