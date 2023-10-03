#pragma once

#include <chrono>
#include <iostream>

#include "Timer.hpp"
#include "Stopwatch.hpp"

void Timer::time(std::function<void()> f)
{
    Stopwatch watch;
    f();
    std::cout << watch.msElapsed() << "ms" << std::endl << std::endl;
}
