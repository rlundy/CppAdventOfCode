#include <stdexcept>
#include <cassert>
#include <set>
#include <algorithm>

#include "Rucksack.hpp"

Rucksack::Rucksack() {}

Rucksack::Rucksack(std::string contents)
{
    auto contentSize { contents.length() };
    auto pocket1text { contents.substr(0, contentSize / 2) };
    auto pocket2text { contents.substr(contentSize / 2) };
    assert(pocket1text.size() == pocket2text.size());
    std::set<char> pocket1;
    std::set<char> pocket2;
    std::for_each(pocket1text.cbegin(), pocket1text.cend(), [&pocket1](char ch){ pocket1.insert(ch); });
    std::for_each(pocket2text.cbegin(), pocket2text.cend(), [&pocket2](char ch){ pocket2.insert(ch); });
    for (auto ch : pocket1) {
        auto result { pocket2.insert(ch) };
        if (!result.second) {
            misplacedItem = ch;
            break;
        }
    }
}

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

int Rucksack::getMisplaceItemPriority()
{
    return getPriority(misplacedItem);
}
