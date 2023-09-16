#include "IntCodeMemory.hpp"
#include "Util.hpp"

#include <iostream>
#include <algorithm>

IntCodeMemory::IntCodeMemory(const std::string &instructions): originalInstructions(instructions)
{
    reboot();
}

void IntCodeMemory::reboot()
{
    auto numberTexts { split(originalInstructions, ",") };
    auto numbers { textToInt(numberTexts) };
    memory.clear();
    memory.insert(memory.begin(), numbers.cbegin(), numbers.cend());
}

void IntCodeMemory::verifyPosition(size_t position) const {
    if (position < 0 || position >= memory.size()) {
        std::ostringstream output;
        output << "Bad index.  ";
        if (memory.empty()) {
            output << "There are no valid positions.";
        }
        else {
            output << "Valid positions are 0 to " << memory.size() - 1 << ".";
        }
        throw std::out_of_range(output.str());
    }
}

size_t IntCodeMemory::size()
{
    return memory.size();
}

void IntCodeMemory::clear()
{
    memory.clear();
}

bool IntCodeMemory::empty()
{
    return memory.empty();
}

int IntCodeMemory::get(size_t index) const
{
    verifyPosition(index);
    return memory[index];
}

void IntCodeMemory::set(size_t index, int value)
{
    verifyPosition(index);
    memory[index] = value;
}
