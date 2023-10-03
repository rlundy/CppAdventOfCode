#include "Stopwatch.hpp"

Stopwatch::Stopwatch()
{
    startTime = std::chrono::high_resolution_clock::now();
}

long long Stopwatch::msElapsed()
{
    auto currentTime { std::chrono::high_resolution_clock::now() };
    auto duration { std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() };
    return duration;
}
