#include <sstream>
#include <stdexcept>
#include <iostream>

#include "IntCode.hpp"
#include "IntCodeOperation.hpp"
#include "Util.hpp"

IntCode::IntCode(std::string instructions): memory { std::make_unique<IntCodeMemory>(instructions) }
{
    std::cout << "Initial instructions:" << std::endl << instructions << std::endl;
}

void IntCode::verifyPosition(int position) {
    if (position < 0 || position >= memory->size()) {
        std::ostringstream output;
        output << "Bad index.  ";
        if (memory->empty()) {
            output << "There are no valid positions.";
        }
        else {
            output << "Valid positions are 0 to " << memory->size() - 1 << ".";
        }
        throw std::out_of_range(output.str());
    }
}

void IntCode::process()
{
    auto currentPos { 0 };
    int inputPos1, inputPos2, outputPos;
    int stopper { 1000 };
    while (true) {
        auto op { static_cast<IntCodeOperation>(memory->get(currentPos)) };
        switch (op) {
            case IntCodeOperation::Add:
                inputPos1 = memory->get(currentPos + 1);
                inputPos2 = memory->get(currentPos + 2);
                outputPos = memory->get(currentPos + 3);
                memory->set(outputPos, memory->get(inputPos1) + memory->get(inputPos2));
                break;
            case IntCodeOperation::Multiply:
                inputPos1 = memory->get(currentPos + 1);
                inputPos2 = memory->get(currentPos + 2);
                outputPos = memory->get(currentPos + 3);
                memory->set(outputPos, memory->get(inputPos1) * memory->get(inputPos2));
                break;
            case IntCodeOperation::End:
                return;
        }
        currentPos += 4;
        stopper--;
        if (stopper == 0)
            return;
    }
}

void IntCode::replace(int position, int value) {
    memory->set(position, value);
}

int IntCode::getPosition(int position)
{
    return memory->get(position);
}

std::string IntCode::getState()
{
    std::ostringstream output;
    for (auto i { 0 }; i < memory->size(); i++) {
        if (i == 0) {
            output << memory->get(i);
        }
        else {
            output << "," << memory->get(i);
        }
    }
    return output.str();
}

void IntCode::reboot()
{
    memory->reboot();
}
