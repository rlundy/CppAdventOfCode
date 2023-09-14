#include <sstream>
#include <stdexcept>

#include "IntCode.hpp"
#include "Util.hpp"

IntCode::IntCode(std::string instructions)
{
    originalInput = instructions;
    reset();
}

void IntCode::verifyPosition(int position) {
    if (position < 0 || position >= memory.size()) {
        std::ostringstream output;
        output << "Bad index.  ";
        if (memory.empty()) {
            output << "There are no valid positions.";
        }
        else {
            output << "Valid positions are 0 to " << memory.size() - 1;
        }
        throw std::out_of_range(output.str());
    }
}

void IntCode::process()
{
    auto currentPos { 0 };
    int inputPos1, inputPos2, outputPos;
    int stopper { 100 };
    while (true) {
        switch (memory[currentPos]) {
            case 1:
                inputPos1 = memory[currentPos + 1];
                inputPos2 = memory[currentPos + 2];
                outputPos = memory[currentPos + 3];
                verifyPosition(inputPos1);
                verifyPosition(inputPos2);
                verifyPosition(outputPos);
                memory[outputPos] = memory[inputPos1] + memory[inputPos2];
                break;
            case 2:
                inputPos1 = memory[currentPos + 1];
                inputPos2 = memory[currentPos + 2];
                outputPos = memory[currentPos + 3];
                verifyPosition(inputPos1);
                verifyPosition(inputPos2);
                verifyPosition(outputPos);
                memory[outputPos] = memory[inputPos1] * memory[inputPos2];
                break;
            case 99:
                return;
        }
        currentPos += 4;
        stopper--;
        if (stopper == 0)
            return;
    }
}

void IntCode::replace(int position, int value) {
    verifyPosition(position);
    memory[position] = value;
}

int IntCode::getPosition(int position)
{
    return memory.at(position);
}

std::string IntCode::getState()
{
    std::ostringstream output;
    auto isEmpty { true };
    for (auto pos : memory) {
        if (isEmpty) {
            isEmpty = false;
            output << pos;
        }
        else {
            output << ",";
            output << pos;
        }
    }
    return output.str();
}

void IntCode::reset()
{
    auto numberTexts { split(originalInput, ",") };
    auto numbers { textToInt(numberTexts) };
    memory.insert(memory.begin(), numbers.cbegin(), numbers.cend());
}
