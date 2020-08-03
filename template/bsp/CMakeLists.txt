cmake_minimum_required(VERSION 3.18)
project(BSP LANGUAGES C CXX ASM)

set(BSP_PATH ${CMAKE_CURRENT_SOURCE_DIR})

string(TOLOWER ${FAMILY} FAMILY_L)
string(TOLOWER ${TYPE} TYPE_L)


find_path(BSP_INCLUDE_PATH
    NAMES PinDefs.hpp
    PATHS "${BSP_PATH}/inc"
    NO_DEFAULT_PATH
    REQUIRED
)

add_library(BSP "${BSP_SOURCES}")
target_include_directories(BSP PUBLIC "${BSP_INCLUDE_PATH}")
target_link_libraries(BSP PUBLIC API)

