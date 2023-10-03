#pragma once

#include <functional>

class Timer {
    private:
    public:
        void time(std::function<void()> f);
};
