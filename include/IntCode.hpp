#pragma once

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

#include "IntCodeMemory.hpp"

class IntCode {
    private:
        std::unique_ptr<IntCodeMemory> memory;
    public:
        void process();
        void replace(int position, int value);
        IntCode(const std::string& instructions);
        int getPosition(int position) const;
        std::string getState() const;
        void reboot();
};
