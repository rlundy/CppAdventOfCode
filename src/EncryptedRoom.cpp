#include <map>
#include <string>
#include <algorithm>
#include <set>

#include "EncryptedRoom.hpp"
#include "Util.hpp"

void EncryptedRoom::toSortedCollection(const std::map<char, int>& charCounts, std::vector<std::pair<char, int>>& sortedCollection)
{
    std::for_each(charCounts.cbegin(), charCounts.cend(), [&sortedCollection](std::pair<char, int> item){ sortedCollection.push_back(item); });
    std::sort(
        sortedCollection.begin(),
        sortedCollection.end(),
        [](std::pair<char, int> a, std::pair<char, int> b) {
            auto result { a.second > b.second };
            return result ? result : a.first < b.first;
        }
    );
}

void EncryptedRoom::countChars(std::map<char, int>& charCounts) {
    for (auto n : nameParts) {
        for (auto ch : n) {
            ++charCounts[ch];
        }
    }
}

EncryptedRoom::EncryptedRoom(const std::string &roomNameSectorIdChecksum) : roomNameSectorIdChecksum { roomNameSectorIdChecksum } {
    auto parts { split(roomNameSectorIdChecksum, "]") };
    auto nameSectorIdChecksum { split(parts.at(0), "[") };
    auto checksum { nameSectorIdChecksum.at(1) };
    for (auto ch : checksum) {
        checksumChars.insert(ch);
    }

    auto namePartsSectorId { split(nameSectorIdChecksum.at(0), "-") };

    auto sectorIdText { namePartsSectorId.back() };
    sectorId = std::stoi(sectorIdText);
    namePartsSectorId.pop_back();
    nameParts = namePartsSectorId;
    roomName = join(nameParts, "-");
}

std::optional<int> EncryptedRoom::isValidRoom()
{
    std::map<char, int> charCounts;
    countChars(charCounts);

    std::vector<std::pair<char, int>> sortedCollection;

    toSortedCollection(charCounts, sortedCollection);

    for (auto i { 0 }; i < checksumChars.size(); ++i) {
        auto thisChar { sortedCollection.at(i).first };
        if (!checksumChars.contains(thisChar)) {
            return std::nullopt;
        }
    }
    return sectorId;
}
