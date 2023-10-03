#include <chrono>
#include <iostream>

#include "Timer.hpp"

void Timer::time(std::function<void()> f)
{
    auto startTime { std::chrono::high_resolution_clock::now() };

    f();

    auto endTime { std::chrono::high_resolution_clock::now() };
    auto duration { std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() };

    std::cout << duration << "ms" << std::endl << std::endl;
}
