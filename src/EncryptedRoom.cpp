#include <map>
#include <string>
#include <algorithm>
#include <set>

#include "EncryptedRoom.hpp"
#include "Util.hpp"

std::vector<std::pair<char, int>> EncryptedRoom::toSortedCollection(std::map<char, int> charCounts)
{
    std::vector<std::pair<char, int>> sortableCharCounts;
    std::for_each(charCounts.cbegin(), charCounts.cend(), [&sortableCharCounts](std::pair<char, int> item){ sortableCharCounts.push_back(item); });
    std::sort(sortableCharCounts.begin(), sortableCharCounts.end(), [](std::pair<char, int> a, std::pair<char, int> b){
        auto result { a.second > b.second };
        return result ? result : a.first < b.first;
    });
    return sortableCharCounts;
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

    auto sortableCharCounts { toSortedCollection(charCounts) };

    for (auto i { 0 }; i < 5; ++i) {
        auto thisChar { sortableCharCounts.at(i).first };
        if (!checksumChars.contains(thisChar)) {
            return std::nullopt;
        }
    }
    return sectorId;
}
