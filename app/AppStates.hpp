#pragma once
#include "State.hpp"

/**
 * @namespace perillion::core
 * @brief Core components of the Perillion framework.
 * @details This namespace contains the StateMachine class used for managing states.
 */
namespace perillion::core {
    class StateMachine;
}

/**
 * @brief External definition of the global FSM instance.
 * @details This instance is used across different files to manage state transitions.
 */
extern perillion::core::StateMachine fsm;

/**
 * @brief State representing the LED being ON.
 * @details In this state, the LED is turned on and a timer is started.
 */
class LedOnState : public perillion::core::State {
public:
    void enter() override;
    void process() override;
};

/**
 * @brief State representing the LED being OFF.
 * @details In this state, the LED is turned off and a timer is started.
 */
class LedOffState : public perillion::core::State {
public:
    void enter() override;
    void process() override;
};

/**
 * @var LED State Instances
 * @details These instances represent the different states of the FSM.
 */
extern LedOnState stateOn;
extern LedOffState stateOff;

