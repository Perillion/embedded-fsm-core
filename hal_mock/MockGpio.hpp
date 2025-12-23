#pragma once
#include "IGpio.hpp"
#include <string>

namespace perillion::hal::mock {

class MockGpio : public IGpio {
public:
    explicit MockGpio(std::string name);
    void write(bool state) override;
    void toggle() override;
    bool read() const override;

private:
    std::string m_name;
    bool m_state = false;
};

} // namespace perillion::hal::mock

