#pragma once

#include <string>
#include <optional>
#include <map>
#include <vector>
#include <set>

class EncryptedRoom {
    private:
        std::string roomNameSectorIdChecksum;
        void toSortedCollection(const std::map<char, int>& charCounts, std::vector<std::pair<char, int>>& sortedCollection);
        void countChars(std::map<char, int>& charCounts);
        std::string roomName;
        std::vector<std::string> nameParts;
        std::set<char> checksumChars;
        int sectorId;
    public:
        EncryptedRoom(const std::string& roomNameSectorIdChecksum);
        std::optional<int> isValidRoom();
};
