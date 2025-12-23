#include "MockGpio.hpp"
#include <iostream>

namespace perillion::hal::mock {

MockGpio::MockGpio(std::string name) : m_name(std::move(name)) {}

void MockGpio::write(bool state) {
    m_state = state;
    std::cout << "[MockGpio " << m_name << "] write: " << (m_state ? "HIGH" : "LOW") << std::endl;
}

void MockGpio::toggle() {
    m_state = !m_state;
    std::cout << "[MockGpio " << m_name << "] toggle: " << (m_state ? "HIGH" : "LOW") << std::endl;
}

bool MockGpio::read() const {
    std::cout << "[MockGpio " << m_name << "] read: " << (m_state ? "HIGH" : "LOW") << std::endl;
    return m_state;
}

} // namespace perillion::hal::mock

