#include <string>

class Rectangle {
    private:
    public:
        Rectangle(int x, int y, int width, int height);
        Rectangle(const std::string& input);
        int x;
        int y;
        int width;
        int height;
};
