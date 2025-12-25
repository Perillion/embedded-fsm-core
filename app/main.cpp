/**
 * @file main.cpp
 * @brief Main application entry point for traffic light control simulation.
 * @details This file initializes the finite state machine and runs the
 *          traffic light control loop for a two-phase intersection.
 */

#include <iostream>
#include <thread>
#include <chrono>

#include "StateMachine.hpp"
#include "AppStates.hpp"

/**
 * @brief Global FSM instance for traffic light control.
 * @details This instance is shared across all state implementations.
 */
perillion::core::StateMachine fsm;


/**
 * @brief Main application function.
 * @details Initializes the traffic light FSM with Phase1Green as the initial state
 *          and runs the simulation for approximately 16 seconds, allowing multiple
 *          complete cycles through both traffic light phases.
 * @return Exit code (0 for success)
 */
int main()
{
    std::cout << "=== Perillion Ampelsteuerung (Kreuzung mit 2 Ampeln) ===" << std::endl;
    std::cout << "Ampel 1: Nord-Süd Richtung" << std::endl;
    std::cout << "Ampel 2: Ost-West Richtung\n" << std::endl;

    // Set initial state: Phase 1 (Traffic light 1 green, traffic light 2 red)
    fsm.setState(phase1Green);

    // Simulate multiple traffic light cycles (approx. 16 seconds)
    for( int i=0; i<160; ++i )
    {
        fsm.process( );
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "\n=== Simulation beendet ===" << std::endl;
    return 0;
}
