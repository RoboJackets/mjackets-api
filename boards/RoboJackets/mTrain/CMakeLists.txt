cmake_minimum_required(VERSION 3.14)
project(BSP LANGUAGES C CXX ASM)

set(BSP_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CHIP STM32F769NI CACHE STRING "Full STM32 Chip Model")

set(BOARD_VERSION "1.0")

add_library(BSP PUBLIC
    source/board_init.c
)

set(BOARD_INCLUDE_DIRS "${BSP_PATH}/include")

target_include_directories(BSP PUBLIC ${BOARD_INCLUDE_DIRS})
target_link_libraries(BSP PUBLIC API)

