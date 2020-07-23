cmake_minimum_required(VERSION 3.14.7)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/mjackets-api/cmake/stm32-gcc-arm-none-eabi.cmake)

# Set your project name
project(myProject LANGUAGES C CXX ASM)

# Set your full chip model here!
set(CHIP STM32F405RG CACHE STRING "Full STM32 Chip Model")
add_definitions(-DSTM32F405xx)
add_definitions(-DSTM32F4)

add_subdirectory(mjackets-api)
add_subdirectory(bsp)

set(PROJECT_SOURCES
	main.cpp
)

# Add any additional source files here
add_executable(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCES} ${CMSIS_SOURCES} ${BSP_SOURCES} ${HAL_${FAMILY}_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC API BSP)
