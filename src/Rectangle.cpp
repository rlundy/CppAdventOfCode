#include "Rectangle.hpp"
#include "Util.hpp"

Rectangle::Rectangle(int x, int y, int width, int height) : x { x }, y { y }, width { width }, height { height } { }

Rectangle::Rectangle(const std::string &line)
{
    auto parts { split(line, " ") };
    auto xyText { split(parts[2], ",") };
    x = std::stoi(xyText[0]);
    y = std::stoi(xyText[1]);
    auto whText { split(parts[3], "x") };
    width = std::stoi(whText[0]);
    height = std::stoi(whText[1]);
}
