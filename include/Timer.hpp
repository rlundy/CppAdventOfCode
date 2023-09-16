#include <functional>

class Timer {
    private:
    public:
        void time(std::function<void()> f);
};



/*
#include <chrono>
#include <iostream>

int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
  
    // Call your function here
    int result = Year2019::Day2Part2("your_input_string");
  
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
        end_time - start_time).count();
  
    std::cout << "Year2019::Day2Part2 took " << duration << " microseconds to run.\n";
    std::cout << "Result: " << result << "\n";

    return 0;
}
*/
