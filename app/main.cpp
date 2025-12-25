#include <iostream>
#include <thread>
#include <chrono>

#include "StateMachine.hpp"
#include "AppStates.hpp"

/**
 * @brief Definition of the global FSM instance.
 * @details This instance is used across different files to manage state transitions.
 */
perillion::core::StateMachine fsm;

/**
 * @var LED State Instances
 * @details These instances represent the different states of the FSM.
 */
LedOnState stateOn;
LedOffState stateOff;

/**
 * @brief Main function to run the FSM demo.
 * @return int Exit code.
 */
int main()
{
    std::cout << "=== Perillion Blinky FSM Demo (Split Files) ===" << std::endl;

    // Set initial state to LED ON
    fsm.setState(stateOn);

    // Simulate a loop that processes the FSM
    for( int i=0; i<20; ++i )
    {
        fsm.process( );
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
