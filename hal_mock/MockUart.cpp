#include "MockUart.hpp"
#include <iostream>
#include <iomanip>

namespace perillion::hal::mock {

MockUart::MockUart(std::string name) : m_name(std::move(name)) {}

void MockUart::send(std::span<const uint8_t> data) {
    std::cout << "[MockUart " << m_name << "] send (" << data.size() << " bytes): ";
    std::cout << std::hex << std::setfill('0');
    for (auto byte : data) {
        std::cout << "0x" << std::setw(2) << static_cast<int>(byte) << " ";
    }
    std::cout << std::dec << std::endl;
}

} // namespace perillion::hal::mock

