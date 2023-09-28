#include <sstream>

#include "Rectangle.hpp"
#include "Util.hpp"

Rectangle::Rectangle(const std::string &line)
{
    char hash, at, comma, colon, by;
    std::istringstream(line) >> hash >> id >> at >> x >> comma >> y >> colon >> width >> by >> height;
}
