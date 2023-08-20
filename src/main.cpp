#include <iostream>

#include "Year2015.hpp"
#include "Util.hpp"

using std::cout;
using std::endl;

int main() {
    cout << "Hello, world!" << endl;

    Year2015 y;
    auto input2015day1 = readFileContents("C:/Users/rlund/OneDrive/Code/CppAdventOfCode/puzzleInput/Year2015Day1.txt");
    cout << "Year 2015 day 1 part 1: " << y.Day1Part1(input2015day1) << endl;
    cout << "Year 2015 day 1 part 2: " << y.Day1Part2(input2015day1) << endl;
}
