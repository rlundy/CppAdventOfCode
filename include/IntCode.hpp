#include <string>
#include <vector>
#include <initializer_list>

class IntCode {
    private:
        std::vector<int> memory;
        std::string originalInput;
        void verifyPosition(int position);
    public:
        void process();
        void replace(int position, int value);
        IntCode(std::string instructions);
        int getPosition(int position);
        std::string getState();
        void reset();
};
