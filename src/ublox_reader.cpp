#include "ublox_reader.h"
#include <cstdint>
#include <iostream>

GPSPosition UbloxReader::decodeUBX(const std::vector<uint8_t>& msg) {
    // NAV-POSLLH UBX payload should be at least 28 bytes
    if (msg.size() < 28) {
        std::cerr << "Invalid UBX message size\n";
        return {0.0, 0.0};
    }

    auto to_i32 = [&](size_t off) -> int32_t {
        return (int32_t)(msg[off] | (msg[off+1] << 8) |
                         (msg[off+2] << 16) | (msg[off+3] << 24));
    };

    // Correct offsets: lon = [4..7], lat = [8..11]
    int32_t lon_raw = to_i32(4);
    int32_t lat_raw = to_i32(8);

    GPSPosition pos;
    pos.lon = lon_raw / 1e7;  // degrees
    pos.lat = lat_raw / 1e7;  // degrees
    return pos;
}
