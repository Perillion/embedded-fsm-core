cmake_minimum_required(VERSION 3.16)
project(PerillionCore VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Testing Setup
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)
FetchContent_MakeAvailable(Catch2)

enable_testing()

add_executable(unit_tests
    tests/test_main.cpp
)

target_link_libraries(unit_tests PRIVATE Catch2::Catch2WithMain)

# Integration with CTest
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)

# Include directories
include_directories(api)
include_directories(core)
include_directories(hal_mock)

# Source files
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

set(SOURCES_APP
    app/main.cpp
)

# Target: PerillionSim (Executable)
add_executable(PerillionSim
    ${SOURCES_API}
    ${SOURCES_HAL_MOCK}
    ${SOURCES_APP}
)
