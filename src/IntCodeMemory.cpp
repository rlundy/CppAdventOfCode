#include "IntCodeMemory.hpp"
#include "Util.hpp"

IntCodeMemory::IntCodeMemory(const std::string &instructions)
{
    if (instructions.empty()) {
        throw std::invalid_argument("Can't create an IntCodeMemory with empty instructions.");
    }
    originalInstructions = instructions;
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
        output << "Bad index: " << position << ".  ";
        if (memory.empty()) {
            output << "There are no valid positions.";
        }
        else {
            output << "Valid positions are 0 to " << memory.size() - 1 << ".";
        }
        throw std::out_of_range(output.str());
    }
}

size_t IntCodeMemory::size() const
{
    return memory.size();
}

bool IntCodeMemory::empty() const
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
