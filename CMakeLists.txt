cmake_minimum_required(VERSION 3.16)
project(PerillionCore VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Dependencies ---
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

# --- Sources ---
set(SOURCES_API
    api/IGpio.hpp
    api/ITimer.hpp
    api/IUart.hpp
)

set(SOURCES_HAL_MOCK
    hal_mock/MockGpio.hpp
    hal_mock/MockGpio.cpp
    hal_mock/MockTimer.hpp
    hal_mock/MockTimer.cpp
    hal_mock/MockUart.hpp
    hal_mock/MockUart.cpp
)

set(SOURCES_CORE
    core/State.hpp
    core/StateMachine.hpp
)

# --- Library (Core + HAL) ---
# Wir bündeln den Code in eine Library, damit Tests und App darauf zugreifen können
add_library(perillion_lib STATIC
    ${SOURCES_API}
    ${SOURCES_HAL_MOCK}
    ${SOURCES_CORE}
)

target_include_directories(perillion_lib PUBLIC
    api
    core
    hal_mock
)

# --- Tests ---
enable_testing()

add_executable(unit_tests
    tests/test_gpio.cpp
)

# Linkt gegen Catch2 UND unsere eigene Library
target_link_libraries(unit_tests PRIVATE
    Catch2::Catch2WithMain
    perillion_lib
)

include(CTest)
include(Catch)
catch_discover_tests(unit_tests)

# --- Application (Simulation) ---
add_executable(PerillionSim
    app/main.cpp
)

target_link_libraries(PerillionSim PRIVATE
    perillion_lib
)
