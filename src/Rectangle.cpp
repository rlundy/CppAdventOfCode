#include <sstream>

#include "Rectangle.hpp"
#include "Util.hpp"
#include "Parser.hpp"

Rectangle::Rectangle(const std::string &line)
{
    (Parser(line)) >> '#' >> id >> '@' >> x >> ',' >> y >> ':' >> width >> 'x' >> height;
}
