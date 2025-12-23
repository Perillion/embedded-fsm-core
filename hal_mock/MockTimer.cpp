#include "MockTimer.hpp"
#include <iostream>

namespace perillion::hal::mock {

MockTimer::MockTimer(std::string name) : m_name(std::move(name)) {}

void MockTimer::start(uint32_t timeout_ms) {
    m_running = true;
    m_timeout = std::chrono::milliseconds(timeout_ms);
    m_startTime = std::chrono::steady_clock::now();
    std::cout << "[MockTimer " << m_name << "] start: " << timeout_ms << "ms" << std::endl;
}

bool MockTimer::hasExpired() const {
    if (!m_running) return false;
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - m_startTime);
    bool expired = elapsed >= m_timeout;
    return expired;
}

void MockTimer::stop() {
    m_running = false;
    std::cout << "[MockTimer " << m_name << "] stop" << std::endl;
}

} // namespace perillion::hal::mock

