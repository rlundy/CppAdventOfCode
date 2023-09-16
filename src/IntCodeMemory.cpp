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
    std::cout << "Resetting IntCodeMemory..." << std::endl;
    std::cout << "Instructions: [" << originalInstructions << "]" << std::endl;
    std::cout << "Split original instructions..." << std::endl;
    auto numberTexts { split(originalInstructions, ",") };
    std::cout << "Quitting if no instructions..." << std::endl;
    std::cout << "Found " << numberTexts.size() << " number text(s)." << std::endl;
    std::cout << "Number texts: ";
    std::for_each(numberTexts.cbegin(), numberTexts.cend(), [](std::string text){ std::cout << text << ","; });
    if (numberTexts.empty()) {
        return;
    }
    std::cout << "Initializing numbers..." << std::endl;
    auto numbers { textToInt(numberTexts) };
    std::cout << "Clearing memory..." << std::endl;
    memory.clear();
    std::cout << "Initializing memory..." << std::endl;
    memory.insert(memory.begin(), numbers.cbegin(), numbers.cend());
    std::cout << "Reset complete." << std::endl;
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
