#pragma once

#include <string>
#include <optional>
#include <map>
#include <vector>

class EncryptedRoom {
    private:
        std::string roomNameSectorIdChecksum;
        void toSortedCollection(const std::map<char, int>& charCounts, std::vector<std::pair<char, int>>& sortedCollection);
        void countChars(const std::vector<std::string>& nameParts, std::map<char, int>& charCounts);

    public:
        EncryptedRoom(const std::string& roomNameSectorIdChecksum);
        std::optional<int> isValidRoom();
};
