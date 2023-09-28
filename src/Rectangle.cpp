#include <sstream>

#include "Rectangle.hpp"
#include "Util.hpp"

Rectangle::Rectangle(const std::string &line)
{
    std::istringstream iss(line);
    char hash, at, comma, colon, by;
    iss >> hash >> id >> at >> x >> comma >> y >> colon >> width >> by >> height;
}
