#include "KeypadKey.hpp"

KeypadKey::KeypadKey(char value, std::optional<char> north, std::optional<char> south, std::optional<char> east, std::optional<char> west): value(value), north(north), south(south), east(east), west(west) { }

char KeypadKey::getValue() { return value; }

std::optional<char> KeypadKey::getNorth() const { return north; }
std::optional<char> KeypadKey::getSouth() const { return south; }
std::optional<char> KeypadKey::getEast() const { return east; }
std::optional<char> KeypadKey::getWest() const { return west; }
