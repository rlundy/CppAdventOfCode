#pragma once

#include <vector>
#include <sstream>

class IntCodeMemory {
    private:
        std::vector<int> memory;
        std::string originalInstructions;
        void verifyPosition(size_t position) const;
    public:
        IntCodeMemory(const std::string& instructions);
        size_t size() const;
        bool empty() const;
        void reboot();
        int get(size_t index) const;
        void set(size_t index, int value);
};
