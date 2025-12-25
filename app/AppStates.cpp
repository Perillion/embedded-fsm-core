#include "AppStates.hpp"
#include "StateMachine.hpp"
#include <iostream>

#include "MockGpio.hpp"
#include "MockTimer.hpp"

/**
 * @brief Definition of the mock hardware components used in the states.
 */
perillion::hal::mock::MockGpio led("UserLED");
perillion::hal::mock::MockTimer timer("BlinkTimer");

/**
 * @brief Enter method for LedOnState.
 */
void LedOnState::enter()
{
    led.write(true);
    timer.start(1000);
}

/**
 * @brief Process method for LedOnState.
 */
void LedOnState::process()
{
    if (timer.hasExpired())
    {
        std::cout << "  -> Zeit um! Wechsel zu OFF" << std::endl;
        fsm.setState(stateOff);
    }
}

/**
 * @brief Enter method for LedOffState.
 */
void LedOffState::enter()
{
    led.write(false);
    timer.start(1000);
}

/**
 * @brief Process method for LedOffState.
 */
void LedOffState::process()
{
    if (timer.hasExpired())
    {
        std::cout << "  -> Zeit um! Wechsel zu ON" << std::endl;
        fsm.setState(stateOn);
    }
}

