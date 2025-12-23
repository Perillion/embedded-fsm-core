#pragma once
#include "ITimer.hpp"
#include <chrono>
#include <string>

namespace perillion::hal::mock {

class MockTimer : public ITimer {
public:
    explicit MockTimer(std::string name);
    void start(uint32_t timeout_ms) override;
    bool hasExpired() const override;
    void stop() override;

private:
    std::string m_name;
    bool m_running = false;
    std::chrono::steady_clock::time_point m_startTime;
    std::chrono::milliseconds m_timeout{0};
};

} // namespace perillion::hal::mock

