#include <map>
#include <string>
#include <algorithm>
#include <set>

#include "EncryptedRoom.hpp"
#include "Util.hpp"

EncryptedRoom::EncryptedRoom(const std::string& roomNameSectorIdChecksum)
{
    this->roomNameSectorIdChecksum = roomNameSectorIdChecksum;
}

std::optional<int> EncryptedRoom::isValidRoom()
{
    std::cout << "Room: " << roomNameSectorIdChecksum << std::endl;

    //aaaaa-bbb-z-y-x-123[abxyz]

    auto parts { split(roomNameSectorIdChecksum, "]") };
    std::cout << parts.size() << " parts" << std::endl;
    for (auto p : parts) {
        std::cout << p << std::endl;
    }

    auto nameSectorIdChecksum { split(parts.at(0), "[") };
    std::cout << nameSectorIdChecksum.size() << " nameSectorIdChecksum" << std::endl;
    for (auto p : nameSectorIdChecksum) {
        std::cout << p << std::endl;
    }

    auto checksum { nameSectorIdChecksum.at(1) };
    std::set<char> checksumChars;
    for (auto ch : checksum) {
        checksumChars.insert(ch);
    }

    auto namePartsSectorId { split(nameSectorIdChecksum.at(0), "-") };
    std::cout << namePartsSectorId.size() << " namePartsSectorId" << std::endl;
    for (auto p : namePartsSectorId) {
        std::cout << p << std::endl;
    }

    auto sectorIdText { namePartsSectorId.back() };
    auto sectorId { std::stoi(sectorIdText) };
    namePartsSectorId.pop_back();
    auto nameParts { namePartsSectorId };

    // nameParts; sectorId; checksum

    std::cout << nameParts.size() << " nameParts" << std::endl;
    for (auto p : nameParts) {
        std::cout << p << std::endl;
    }

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

    for (auto item : charCounts) {
        std::cout << item.first << " : " << item.second << std::endl;
    }

    std::vector<std::pair<char, int>> sortableCharCounts;
    std::for_each(charCounts.cbegin(), charCounts.cend(), [&sortableCharCounts](std::pair<char, int> item){ sortableCharCounts.push_back(item); });
    std::sort(sortableCharCounts.begin(), sortableCharCounts.end(), [](std::pair<char, int> a, std::pair<char, int> b){ 
        auto result { a.second > b.second };
        return result ? result : a.first < b.first;
     });

     std::cout << "Sorted:" << std::endl;
     for (auto x : sortableCharCounts) {
        std::cout << x.first << " : " << x.second << std::endl;
     }

     for (auto i { 0 }; i < 5; ++i) {
        auto thisChar { sortableCharCounts.at(i).first };
        if (!checksumChars.contains(thisChar)) {
            return std::nullopt;
        }
     }
     return sectorId;
}
