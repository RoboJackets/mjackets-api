cmake_minimum_required(VERSION 3.14)
project(BSP LANGUAGES C CXX ASM)

set(BSP_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Path to BSP directory")
set(CHIP STM32F769NI CACHE STRING "Full STM32 Chip Model")
set(FAMILY F7 CACHE STRING "STM32 Target Device Family")

set(BOARD_VERSION "1.0")

add_library(BSP
    source/board_init.c
)

set(BOARD_INCLUDE_DIRS "${BSP_PATH}/include" CACHE STRING "Path to BSP include directory")

target_include_directories(BSP PUBLIC ${BOARD_INCLUDE_DIRS})
target_link_libraries(BSP PUBLIC API)

