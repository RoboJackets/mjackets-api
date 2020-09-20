cmake_minimum_required(VERSION 3.14.7)

if(BOARD)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/stm32-gcc-arm-none-eabi.cmake)
endif()

project(
  mjackets-api
  LANGUAGES C CXX ASM
)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(MJACKETS_PATH ${CMAKE_CURRENT_SOURCE_DIR})

if(BOARD)
    find_package(BOARD COMPONENTS ${BOARD} REQUIRED)
endif()

include(stm32/common REQUIRED)
add_subdirectory(external)

add_library(API
    api/AnalogIn.cpp
    api/DigitalIn.cpp
    api/DigitalOut.cpp
    api/default_handlers.c
    api/hardware_init.c
    api/Delay.cpp
    api/ClockHandler.cpp
    api/ExternalInterrupt.cpp
)

target_include_directories(API PUBLIC
    include/
)

find_package(HAL COMPONENTS STM32${FAMILY} REQUIRED)
find_package(CMSIS COMPONENTS STM32${DEVICE} REQUIRED)

target_compile_features(API PRIVATE cxx_std_17)
set_property(TARGET API PROPERTY CXX_STANDARD 17)

target_link_libraries(API
    HAL::STM32::${FAMILY}
    ${HAL_${FAMILY}_DRIVERS}
    ${HAL_${FAMILY}_DRIVERS_EX}
    ${HAL_${FAMILY}_DRIVERS_LL}
    CMSIS::STM32::${DEVICE}
    STM32::NoSys
    BSP
    FreeRTOS
)

add_subdirectory ("docs")
add_subdirectory("tests")
