#include <vector>
#include <algorithm>
#include <iterator>

#include "Year2015.hpp"
#include "Util.hpp"

int Year2015::Day1Part1(const std::string &input)
{
    auto up { std::count(input.cbegin(), input.cend(), '(') };
    auto down { std::count(input.cbegin(), input.cend(), ')') };
    return static_cast<int>(up - down);
}

int Year2015::Day1Part2(const std::string& input)
{
    auto floor { 0 };
    for (auto i { 0 }; i < input.length(); i++) {
        auto step { input[i] };
        if (step == '(') {
            floor++;
        }
        else if (step == ')') {
            floor--;
        }
        if (floor < 0) {
            return i + 1;
        }
    }
    return -1;
}

int Year2015::getWrappingPaper(const std::string& dimensions) {
    auto dimsText { split(dimensions, "x") };
    auto dims { textToInt(dimsText) };
    auto l { dims[0] }, w { dims[1] }, h { dims[2] };
    auto s1 { l * w };
    auto s2 { w * h };
    auto s3 { l * h };
    auto minSide = std::min({ s1, s2, s3 });
    return s1 * 2 + s2 * 2 + s3 * 2 + minSide;
}

int Year2015::getRibbon(const std::string &dimensions)
{
    auto dimsText { split(dimensions, "x") };
    auto dims { textToInt(dimsText) };
    auto l { dims[0] }, w { dims[1] }, h { dims[2] };
    auto p1 = 2 * l + 2 * w;
    auto p2 = 2 * l + 2 * h;
    auto p3 = 2 * w + 2 * h;
    auto smallest = std::min({ p1, p2, p3 });
    auto bow = l * w * h;
    return smallest + bow;
}

int Year2015::Day2Part1(const std::string& input)
{
    auto dimensions { split(input, "\n") };
    std::vector<int> paper;
    std::transform(
        dimensions.cbegin(),
        dimensions.cend(),
        std::back_inserter(paper),
        [this](const std::string& dim) { return this->getWrappingPaper(dim); }
    );
    return sum(paper);
}

// The ribbon required to wrap a present is the shortest distance around its sides, or the smallest perimeter of any one face. Each present also requires a bow made out of ribbon as well; the feet of ribbon required for the perfect bow is equal to the cubic feet of volume of the present. Don't ask how they tie the bow, though; they'll never tell.
int Year2015::Day2Part2(const std::string& input)
{
    auto dimensions = split(input, "\n");
    std::vector<int> ribbon;
    std::transform(
        dimensions.cbegin(),
        dimensions.cend(),
        std::back_inserter(ribbon),
        [this](const std::string& dim) { return this->getRibbon(dim); }
    );
    return sum(ribbon);
}
