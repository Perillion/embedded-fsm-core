/**
 * @file AppStates.cpp
 * @brief Implementation of traffic light control states.
 * @details This file contains the implementation of all traffic light states
 *          for a two-phase intersection control system with safety phases.
 */

#include "AppStates.hpp"
#include "StateMachine.hpp"
#include <iostream>

#include "MockGpio.hpp"
#include "MockTimer.hpp"

/**
 * @brief Mock hardware components for traffic light control.
 * @details
 * - Traffic Light 1: North-South direction (3 LEDs: red, yellow, green)
 * - Traffic Light 2: East-West direction (3 LEDs: red, yellow, green)
 * - Timer: Phase timing control
 */
perillion::hal::mock::MockGpio ampel1_red("Ampel1-Rot");       ///< Traffic light 1 red LED
perillion::hal::mock::MockGpio ampel1_yellow("Ampel1-Gelb");   ///< Traffic light 1 yellow LED
perillion::hal::mock::MockGpio ampel1_green("Ampel1-Grün");    ///< Traffic light 1 green LED

perillion::hal::mock::MockGpio ampel2_red("Ampel2-Rot");       ///< Traffic light 2 red LED
perillion::hal::mock::MockGpio ampel2_yellow("Ampel2-Gelb");   ///< Traffic light 2 yellow LED
perillion::hal::mock::MockGpio ampel2_green("Ampel2-Grün");    ///< Traffic light 2 green LED

perillion::hal::mock::MockTimer timer("PhasenTimer");          ///< Phase duration timer

/**
 * @brief State instances for the traffic light FSM.
 * @details These global instances are used by the state machine to manage
 *          the traffic light cycle.
 */
Phase1Green phase1Green;
Phase1Yellow phase1Yellow;
Phase1AllRed phase1AllRed;
Phase2RedYellow phase2RedYellow;
Phase2Green phase2Green;
Phase2Yellow phase2Yellow;
Phase2AllRed phase2AllRed;
Phase1RedYellow phase1RedYellow;

// ============================================================================
// Phase 1: Traffic Light 1 Green, Traffic Light 2 Red
// ============================================================================

/**
 * @brief Enter Phase1Green state.
 * @details Sets traffic light 1 to green and traffic light 2 to red.
 *          Starts a 3-second timer for this phase.
 */
void Phase1Green::enter()
{
    std::cout << "\n=== Phase 1: Ampel1 GRÜN | Ampel2 ROT ===" << std::endl;
    // Traffic light 1: Green
    ampel1_red.write(false);
    ampel1_yellow.write(false);
    ampel1_green.write(true);

    // Traffic light 2: Red
    ampel2_red.write(true);
    ampel2_yellow.write(false);
    ampel2_green.write(false);

    timer.start(3000); // 3 seconds green phase
}

/**
 * @brief Process Phase1Green state.
 * @details Checks if the timer has expired. If so, transitions to yellow phase.
 */
void Phase1Green::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu Gelb (Ampel1)" << std::endl;
        fsm.setState(phase1Yellow);
    }
}

/**
 * @brief Exit Phase1Green state.
 * @details No cleanup required for this state.
 */
void Phase1Green::exit()
{
    // Nothing to do
}

// ============================================================================
// Phase 1 Transition: Traffic Light 1 Yellow
// ============================================================================

/**
 * @brief Enter Phase1Yellow state.
 * @details Sets traffic light 1 to yellow (warning phase).
 *          Traffic light 2 remains red. Starts a 1-second timer.
 */
void Phase1Yellow::enter()
{
    std::cout << "\n=== Übergang: Ampel1 GELB | Ampel2 ROT ===" << std::endl;
    // Traffic light 1: Yellow
    ampel1_red.write(false);
    ampel1_yellow.write(true);
    ampel1_green.write(false);

    // Traffic light 2: remains Red

    timer.start(1000); // 1 second yellow phase
}

/**
 * @brief Process Phase1Yellow state.
 * @details Checks if the timer has expired. If so, transitions to safety phase.
 */
void Phase1Yellow::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu Sicherheitsphase (Beide ROT)" << std::endl;
        fsm.setState(phase1AllRed);
    }
}

/**
 * @brief Exit Phase1Yellow state.
 * @details No cleanup required for this state.
 */
void Phase1Yellow::exit()
{
    // Nothing to do
}

// ============================================================================
// Phase 2: Traffic Light 1 Red, Traffic Light 2 Green
// ============================================================================

/**
 * @brief Enter Phase2Green state.
 * @details Sets traffic light 1 to red and traffic light 2 to green.
 *          Starts a 3-second timer for this phase.
 */
void Phase2Green::enter()
{
    std::cout << "\n=== Phase 2: Ampel1 ROT | Ampel2 GRÜN ===" << std::endl;
    // Traffic light 1: Red
    ampel1_red.write(true);
    ampel1_yellow.write(false);
    ampel1_green.write(false);

    // Traffic light 2: Green
    ampel2_red.write(false);
    ampel2_yellow.write(false);
    ampel2_green.write(true);

    timer.start(3000); // 3 seconds green phase
}

/**
 * @brief Process Phase2Green state.
 * @details Checks if the timer has expired. If so, transitions to yellow phase.
 */
void Phase2Green::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu Gelb (Ampel2)" << std::endl;
        fsm.setState(phase2Yellow);
    }
}

/**
 * @brief Exit Phase2Green state.
 * @details No cleanup required for this state.
 */
void Phase2Green::exit()
{
    // Nothing to do
}

// ============================================================================
// Phase 2 Transition: Traffic Light 2 Yellow
// ============================================================================

/**
 * @brief Enter Phase2Yellow state.
 * @details Sets traffic light 2 to yellow (warning phase).
 *          Traffic light 1 remains red. Starts a 1-second timer.
 */
void Phase2Yellow::enter()
{
    std::cout << "\n=== Übergang: Ampel1 ROT | Ampel2 GELB ===" << std::endl;
    // Traffic light 1: remains Red

    // Traffic light 2: Yellow
    ampel2_red.write(false);
    ampel2_yellow.write(true);
    ampel2_green.write(false);

    timer.start(1000); // 1 second yellow phase
}

/**
 * @brief Process Phase2Yellow state.
 * @details Checks if the timer has expired. If so, transitions to safety phase.
 */
void Phase2Yellow::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu Sicherheitsphase (Beide ROT)" << std::endl;
        fsm.setState(phase2AllRed);
    }
}

/**
 * @brief Exit Phase2Yellow state.
 * @details No cleanup required for this state.
 */
void Phase2Yellow::exit()
{
    // Nothing to do
}

// ============================================================================
// Safety Phase 1: Both Traffic Lights Red
// ============================================================================

/**
 * @brief Enter Phase1AllRed state.
 * @details Safety clearance phase. Both traffic lights are set to red
 *          to ensure the intersection is clear before phase transition.
 *          Starts a 1-second timer.
 */
void Phase1AllRed::enter()
{
    std::cout << "\n=== SICHERHEIT: Beide Ampeln ROT ===" << std::endl;
    // Traffic light 1: Red
    ampel1_red.write(true);
    ampel1_yellow.write(false);
    ampel1_green.write(false);

    // Traffic light 2: Red
    ampel2_red.write(true);
    ampel2_yellow.write(false);
    ampel2_green.write(false);

    timer.start(1000); // 1 second safety clearance
}

/**
 * @brief Process Phase1AllRed state.
 * @details Checks if the timer has expired. If so, transitions to red-yellow phase.
 */
void Phase1AllRed::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu Rot-Gelb (Ampel2)" << std::endl;
        fsm.setState(phase2RedYellow);
    }
}

/**
 * @brief Exit Phase1AllRed state.
 * @details No cleanup required for this state.
 */
void Phase1AllRed::exit()
{
    // Nothing to do
}

// ============================================================================
// Phase 2 Preparation: Traffic Light 2 Red-Yellow
// ============================================================================

/**
 * @brief Enter Phase2RedYellow state.
 * @details Preparation phase for traffic light 2. Sets red and yellow
 *          simultaneously to announce upcoming green phase (German traffic rules).
 *          Starts a 1-second timer.
 */
void Phase2RedYellow::enter()
{
    std::cout << "\n=== Übergang: Ampel1 ROT | Ampel2 ROT-GELB ===" << std::endl;
    // Traffic light 1: remains Red
    ampel1_red.write(true);
    ampel1_yellow.write(false);
    ampel1_green.write(false);

    // Traffic light 2: Red + Yellow (green announcement)
    ampel2_red.write(true);
    ampel2_yellow.write(true);
    ampel2_green.write(false);

    timer.start(1000); // 1 second red-yellow phase
}

/**
 * @brief Process Phase2RedYellow state.
 * @details Checks if the timer has expired. If so, transitions to green phase.
 */
void Phase2RedYellow::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu GRÜN (Ampel2)" << std::endl;
        fsm.setState(phase2Green);
    }
}

/**
 * @brief Exit Phase2RedYellow state.
 * @details No cleanup required for this state.
 */
void Phase2RedYellow::exit()
{
    // Nothing to do
}

// ============================================================================
// Safety Phase 2: Both Traffic Lights Red
// ============================================================================

/**
 * @brief Enter Phase2AllRed state.
 * @details Safety clearance phase. Both traffic lights are set to red
 *          to ensure the intersection is clear before returning to phase 1.
 *          Starts a 1-second timer.
 */
void Phase2AllRed::enter()
{
    std::cout << "\n=== SICHERHEIT: Beide Ampeln ROT ===" << std::endl;
    // Traffic light 1: Red
    ampel1_red.write(true);
    ampel1_yellow.write(false);
    ampel1_green.write(false);

    // Traffic light 2: Red
    ampel2_red.write(true);
    ampel2_yellow.write(false);
    ampel2_green.write(false);

    timer.start(1000); // 1 second safety clearance
}

/**
 * @brief Process Phase2AllRed state.
 * @details Checks if the timer has expired. If so, transitions to red-yellow phase.
 */
void Phase2AllRed::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu Rot-Gelb (Ampel1)" << std::endl;
        fsm.setState(phase1RedYellow);
    }
}

/**
 * @brief Exit Phase2AllRed state.
 * @details No cleanup required for this state.
 */
void Phase2AllRed::exit()
{
    // Nothing to do
}

// ============================================================================
// Phase 1 Preparation: Traffic Light 1 Red-Yellow
// ============================================================================

/**
 * @brief Enter Phase1RedYellow state.
 * @details Preparation phase for traffic light 1. Sets red and yellow
 *          simultaneously to announce upcoming green phase (German traffic rules).
 *          Starts a 1-second timer.
 */
void Phase1RedYellow::enter()
{
    std::cout << "\n=== Übergang: Ampel1 ROT-GELB | Ampel2 ROT ===" << std::endl;
    // Traffic light 1: Red + Yellow (green announcement)
    ampel1_red.write(true);
    ampel1_yellow.write(true);
    ampel1_green.write(false);

    // Traffic light 2: remains Red
    ampel2_red.write(true);
    ampel2_yellow.write(false);
    ampel2_green.write(false);

    timer.start(1000); // 1 second red-yellow phase
}

/**
 * @brief Process Phase1RedYellow state.
 * @details Checks if the timer has expired. If so, returns to green phase (phase 1).
 */
void Phase1RedYellow::process()
{
    if (timer.hasExpired()) {
        std::cout << "  -> Wechsel zu GRÜN (Ampel1)" << std::endl;
        fsm.setState(phase1Green);
    }
}

/**
 * @brief Exit Phase1RedYellow state.
 * @details No cleanup required for this state.
 */
void Phase1RedYellow::exit()
{
    // Nothing to do
}
