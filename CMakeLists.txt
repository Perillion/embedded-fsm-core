cmake_minimum_required(VERSION 3.16)
project(PerillionCore VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(api)
include_directories(core)
include_directories(hal_mock)

# Source files
set(SOURCES_API
    api/IGpio.hpp
)

set(SOURCES_HAL_MOCK
    hal_mock/MockGpio.hpp
    hal_mock/MockGpio.cpp
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

