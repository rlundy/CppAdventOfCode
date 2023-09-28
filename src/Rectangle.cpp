#include "Rectangle.hpp"
#include "Util.hpp"

Rectangle::Rectangle(const std::string &line)
{
    auto parts { split(line, " ") };
    auto xyText { split(parts[2], ",") };
    x = std::stoi(xyText[0]);
    y = std::stoi(xyText[1]);
    auto whText { split(parts[3], "x") };
    width = std::stoi(whText[0]);
    height = std::stoi(whText[1]);
    id = std::stoi(parts[0].substr(1));
}
