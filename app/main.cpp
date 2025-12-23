#include "MockGpio.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Perillion Core: FSM & HAL Simulation Start" << std::endl;

    // Setup Mock Hardware
    perillion::hal::mock::MockGpio led("StatusLED");

    // Simple "Hello World" loop (Blinky)
    for (int i = 0; i < 5; ++i) {
        led.toggle();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Simulation Finished." << std::endl;
    return 0;
}

