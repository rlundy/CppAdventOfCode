#pragma once

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

#include "IntCodeMemory.hpp"

class IntCode {
    private:
        std::unique_ptr<IntCodeMemory> memory;
        void verifyPosition(int position);
    public:
        void process();
        void replace(int position, int value);
        IntCode(std::string instructions);
        int getPosition(int position);
        std::string getState();
        void reboot();
};
