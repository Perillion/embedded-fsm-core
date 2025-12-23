#include <catch2/catch_test_macros.hpp>
#include "StateMachine.hpp"

// --- Minimal FSM Example for Testing ---
struct LightContext {
    bool isLightOn = false;
};

enum class Event { TOGGLE };

class LightState : public State<LightContext, Event> {};

class OnState : public LightState {
public:
    void enter(LightContext& ctx) override { ctx.isLightOn = true; }
};

class OffState : public LightState {
public:
    void enter(LightContext& ctx) override { ctx.isLightOn = false; }
};

// --- Tests ---

TEST_CASE("Hello World Test", "[basic]") {
    REQUIRE(1 + 1 == 2);
    REQUIRE(true);
}

TEST_CASE("FSM Transitions", "[fsm]") {
    LightContext ctx;
    StateMachine<LightContext, Event> fsm(ctx);

    OnState on;
    OffState off;

    SECTION("Initial State Entry") {
        fsm.initialize(&off);
        REQUIRE(fsm.getCurrentState() == &off);
        REQUIRE(ctx.isLightOn == false);
    }

    SECTION("State Transition Logic") {
        fsm.initialize(&off);

        // Switch to ON
        fsm.transitionTo(&on);
        REQUIRE(fsm.getCurrentState() == &on);
        REQUIRE(ctx.isLightOn == true);

        // Switch back to OFF
        fsm.transitionTo(&off);
        REQUIRE(fsm.getCurrentState() == &off);
        REQUIRE(ctx.isLightOn == false);
    }
}
