#pragma once
#include "IUart.hpp"
#include <string>

namespace perillion::hal::mock {

class MockUart : public IUart {
public:
    explicit MockUart(std::string name);
    void send(std::span<const uint8_t> data) override;

private:
    std::string m_name;
};

} // namespace perillion::hal::mock

