#pragma once

#include <string>
#include <optional>

class EncryptedRoom {
    private:
        std::string roomNameSectorIdChecksum;
    public:
        EncryptedRoom(const std::string& roomNameSectorIdChecksum);
        std::optional<int> isValidRoom();
};
