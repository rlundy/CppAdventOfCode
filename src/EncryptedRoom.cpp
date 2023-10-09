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

void EncryptedRoom::countChars(const std::vector<std::string>& nameParts, std::map<char, int>& charCounts) {
    for (auto n : nameParts) {
        for (auto ch : n) {
            if (charCounts.contains(ch)) {
                charCounts.at(ch)++;
            }
            else {
                charCounts.insert({ ch, 1 });
            }
        }
    }
}

EncryptedRoom::EncryptedRoom(const std::string &roomNameSectorIdChecksum)
{
    this->roomNameSectorIdChecksum = roomNameSectorIdChecksum;
}

std::optional<int> EncryptedRoom::isValidRoom()
{
    auto parts { split(roomNameSectorIdChecksum, "]") };
    auto nameSectorIdChecksum { split(parts.at(0), "[") };
    auto checksum { nameSectorIdChecksum.at(1) };
    auto checksumLength { checksum.length() };
    std::set<char> checksumChars;
    for (auto ch : checksum) {
        checksumChars.insert(ch);
    }

    auto namePartsSectorId { split(nameSectorIdChecksum.at(0), "-") };

    auto sectorIdText { namePartsSectorId.back() };
    auto sectorId { std::stoi(sectorIdText) };
    namePartsSectorId.pop_back();
    auto nameParts { namePartsSectorId };

    // nameParts; sectorId; checksum

    std::map<char, int> charCounts;
    countChars(nameParts, charCounts);

    std::vector<std::pair<char, int>> sortedCollection;

    toSortedCollection(charCounts, sortedCollection);

    for (auto i { 0 }; i < checksumLength; ++i) {
        auto thisChar { sortedCollection.at(i).first };
        if (!checksumChars.contains(thisChar)) {
            return std::nullopt;
        }
    }
    return sectorId;
}
