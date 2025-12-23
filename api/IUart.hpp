#pragma once
#include <span>
#include <cstdint>

namespace perillion::hal {

class IUart {
public:
    virtual ~IUart() = default;

    virtual void send(std::span<const uint8_t> data) = 0;
};

} // namespace perillion::hal

