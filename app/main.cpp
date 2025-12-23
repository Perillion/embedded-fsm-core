#include "MockGpio.hpp"
#include "MockTimer.hpp"
#include "MockUart.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

int main() {
    std::cout << "Perillion Core: FSM & HAL Simulation Start" << std::endl;

    // Setup Mock Hardware
    perillion::hal::mock::MockGpio led("StatusLED");
    perillion::hal::mock::MockTimer timer("Watchdog");
    perillion::hal::mock::MockUart uart("DebugConsole");

    // Simple "Hello World" loop (Blinky)
    timer.start(2000); // Start 2s timer

    std::vector<uint8_t> helloMsg = {0x48, 0x65, 0x6C, 0x6C, 0x6F}; // "Hello"

    for (int i = 0; i < 5; ++i) {
        led.toggle();
        uart.send(helloMsg);

        if (timer.hasExpired()) {
            std::cout << "Timer expired! Restarting..." << std::endl;
            timer.start(2000);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Simulation Finished." << std::endl;
    return 0;
}

