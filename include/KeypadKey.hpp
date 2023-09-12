#include <optional>

class KeypadKey {
    private:
        char value;
        std::optional<char> north;
        std::optional<char> south;
        std::optional<char> east;
        std::optional<char> west;
    public:
        KeypadKey(const char value, const std::optional<char> north, const std::optional<char> south, const std::optional<char> east, const std::optional<char> west);
        char getValue();
        std::optional<char> getNorth();
        std::optional<char> getSouth();
        std::optional<char> getEast();
        std::optional<char> getWest();
};
