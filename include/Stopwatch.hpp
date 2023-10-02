#pragma once

#include <chrono>

class Stopwatch {
    std::chrono::high_resolution_clock::time_point startTime;
    public:
        Stopwatch();
        long long msElapsed();
};
