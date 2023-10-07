#pragma once

#include <string>

class Rucksack {
    private:
        char misplacedItem;
    public:
        Rucksack();
        Rucksack(std::string contents);
        int getPriority(char ch);
        int getMisplaceItemPriority();
};
