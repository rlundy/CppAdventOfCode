#pragma once

#include <string>
#include <optional>
#include <map>
#include <vector>

class EncryptedRoom {
    private:
        std::string roomNameSectorIdChecksum;
        std::vector<std::pair<char, int>> toSortedCollection(std::map<char, int> charCounts);
    public:
        EncryptedRoom(const std::string& roomNameSectorIdChecksum);
        std::optional<int> isValidRoom();
};
