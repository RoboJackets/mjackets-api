cmake_minimum_required(VERSION 3.18)
project(BSP LANGUAGES C CXX ASM)

set(BSP_PATH ${CMAKE_CURRENT_SOURCE_DIR})

string(TOLOWER ${FAMILY} FAMILY_L)
string(TOLOWER ${TYPE} TYPE_L)

find_path(BSP_SOURCE_PATH
        NAMES bsp.c
        PATHS "${BSP_PATH}/src"
        NO_DEFAULT_PATH
)

find_file(BSP_SOURCE
    NAMES bsp.c
    PATHS "${BSP_PATH}/src"
    NO_DEFAULT_PATH
    REQUIRED
)
list(APPEND BSP_SOURCES "${BSP_SOURCE}")

list(APPEND BSP_SOURCES "${BSP_SOURCE_PATH}/interrupt_handlers.c")
list(APPEND BSP_SOURCES "${BSP_SOURCE_PATH}/default_handlers.c")
list(APPEND BSP_SOURCES "${BSP_SOURCE_PATH}/stm32${FAMILY_L}xx_hal_msp.c")

find_path(BSP_INCLUDE_PATH
    NAMES bsp.h
    PATHS "${BSP_PATH}/inc"
    NO_DEFAULT_PATH
    REQUIRED
)

add_library(BSP "${BSP_SOURCES}")
target_include_directories(BSP PUBLIC "${BSP_INCLUDE_PATH}")
target_link_libraries(BSP PUBLIC API)

