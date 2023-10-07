#include "Rucksack.hpp"

#include <stdexcept>

int Rucksack::getPriority(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 1;
    }
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 1 + 26;
    }
    throw std::domain_error("getPriority is only valid for letters a-z and A-Z.");
}
