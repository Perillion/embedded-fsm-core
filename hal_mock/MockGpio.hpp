#pragma once
} // namespace perillion::hal::mock

};
    bool m_state = false;
    std::string m_name;
private:

    bool read() const override;
    void toggle() override;
    void write(bool state) override;
    explicit MockGpio(std::string name);
public:
class MockGpio : public IGpio {

namespace perillion::hal::mock {

#include <string>
#include "IGpio.hpp"

