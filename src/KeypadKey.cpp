#include "KeypadKey.hpp"

KeypadKey::KeypadKey(char value, std::optional<char> north = std::nullopt, std::optional<char> south = std::nullopt, std::optional<char> east = std::nullopt, std::optional<char> west = std::nullopt)
{
    this->value = value;
    if (north.has_value())
        this->north = north;
    if (south.has_value())
        this->south = south;
    if (west.has_value())
        this->west = west;
    if (east.has_value())
        this->east = east;
}

char KeypadKey::getValue() { return value; }

std::optional<char> KeypadKey::getNorth() { return north; }
std::optional<char> KeypadKey::getSouth() { return south; }
std::optional<char> KeypadKey::getEast() { return east; }
std::optional<char> KeypadKey::getWest() { return west; }
