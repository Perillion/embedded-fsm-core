#include <catch2/catch_test_macros.hpp>
#include "../hal_mock/MockGpio.hpp"

TEST_CASE("MockGpio basic operations", "[gpio]") {
    perillion::hal::mock::MockGpio gpio("TestLED");

    SECTION("Initial state is false") {
        REQUIRE(gpio.read() == false);
    }

    SECTION("Write true changes state to true") {
        gpio.write(true);
        REQUIRE(gpio.read() == true);
    }

    SECTION("Toggle inverts state") {
        gpio.write(true);
        gpio.toggle();
        REQUIRE(gpio.read() == false);
        gpio.toggle();
        REQUIRE(gpio.read() == true);
    }
}


