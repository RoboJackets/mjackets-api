cmake_minimum_required(VERSION 3.14.7)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/mjackets-api/cmake/stm32-gcc-arm-none-eabi.cmake)

# Set your project name
project(myProject LANGUAGES C CXX ASM)

# Set your full chip model here!
set(CHIP STM32F769NI CACHE STRING "Full STM32 Chip Model")

add_subdirectory(mjackets-api)
add_subdirectory(bsp)

# Source files go here!
set(PROJECT_SOURCES
	main.cpp
)

add_executable(mJackets.elf ${PROJECT_SOURCES})

target_link_libraries(mJackets.elf PUBLIC API)

