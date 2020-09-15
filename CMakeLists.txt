cmake_minimum_required(VERSION 3.14.7)

project(
  mjackets-api
  LANGUAGES C CXX ASM
)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(MJACKETS_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(stm32/common REQUIRED)
add_subdirectory(external)

add_library(API
    api/AnalogIn.cpp
    api/DigitalIn.cpp
    api/DigitalOut.cpp
    api/InterruptIn.cpp
    api/SPI.cpp
    api/I2C.cpp
    api/default_handlers.c
    api/interrupt_handlers.c
    api/hardware_init.c
    api/delay.c
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
