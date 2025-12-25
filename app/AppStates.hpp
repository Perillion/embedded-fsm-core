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
 * @class Phase1Green
 * @brief Traffic light phase 1: Traffic light 1 green, traffic light 2 red.
 * @details This state represents the north-south direction having green light
 *          while the east-west direction has red light. Duration: 3 seconds.
 */
class Phase1Green : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @class Phase1Yellow
 * @brief Transition phase: Traffic light 1 yellow, traffic light 2 red.
 * @details Yellow warning phase for north-south direction before switching.
 *          Duration: 1 second.
 */
class Phase1Yellow : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @class Phase1AllRed
 * @brief Safety phase: Both traffic lights red.
 * @details Safety clearance phase to ensure the intersection is empty
 *          before switching to the next green phase. Duration: 1 second.
 */
class Phase1AllRed : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @class Phase2RedYellow
 * @brief Transition phase: Traffic light 1 red, traffic light 2 red-yellow.
 * @details Red-yellow preparation phase for traffic light 2 (east-west)
 *          before switching to green. Duration: 1 second.
 */
class Phase2RedYellow : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @class Phase2Green
 * @brief Traffic light phase 2: Traffic light 1 red, traffic light 2 green.
 * @details This state represents the east-west direction having green light
 *          while the north-south direction has red light. Duration: 3 seconds.
 */
class Phase2Green : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @class Phase2Yellow
 * @brief Transition phase: Traffic light 1 red, traffic light 2 yellow.
 * @details Yellow warning phase for east-west direction before switching.
 *          Duration: 1 second.
 */
class Phase2Yellow : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @class Phase2AllRed
 * @brief Safety phase: Both traffic lights red.
 * @details Safety clearance phase to ensure the intersection is empty
 *          before switching back to phase 1. Duration: 1 second.
 */
class Phase2AllRed : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @class Phase1RedYellow
 * @brief Transition phase: Traffic light 1 red-yellow, traffic light 2 red.
 * @details Red-yellow preparation phase for traffic light 1 (north-south)
 *          before switching to green. Duration: 1 second.
 */
class Phase1RedYellow : public perillion::core::State {
public:
    void enter() override;
    void process() override;
    void exit() override;
};

/**
 * @brief Global state instances for the traffic light finite state machine.
 * @details These extern declarations allow the states to be shared across
 *          compilation units (defined in AppStates.cpp, used in main.cpp).
 */
extern Phase1Green phase1Green;         ///< Instance of Phase1Green state
extern Phase1Yellow phase1Yellow;       ///< Instance of Phase1Yellow state
extern Phase1AllRed phase1AllRed;       ///< Instance of Phase1AllRed state
extern Phase2RedYellow phase2RedYellow; ///< Instance of Phase2RedYellow state
extern Phase2Green phase2Green;         ///< Instance of Phase2Green state
extern Phase2Yellow phase2Yellow;       ///< Instance of Phase2Yellow state
extern Phase2AllRed phase2AllRed;       ///< Instance of Phase2AllRed state
extern Phase1RedYellow phase1RedYellow; ///< Instance of Phase1RedYellow state
