cmake_minimum_required(VERSION 3.14.7)

project(
  mjackets-api
  LANGUAGES C CXX ASM
)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(MJACKETS_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(stm32/common REQUIRED)

add_library(API
    api/AnalogIn.cpp
    api/DigitalIn.cpp
    api/DigitalOut.cpp
    api/default_handlers.c
    api/interrupt_handlers.c
    api/hardware_init.c
)

target_include_directories(API PUBLIC
    include/
)

target_include_directories(API PRIVATE
    ${CMAKE_SOURCE_DIR}/bsp/inc
)

find_package(HAL COMPONENTS STM32${FAMILY} REQUIRED)
find_package(CMSIS COMPONENTS STM32${DEVICE} REQUIRED)

target_compile_features(API PRIVATE cxx_std_17)
set_property(TARGET API PROPERTY CXX_STANDARD 17)

target_link_libraries(API
    HAL::STM32::${FAMILY}
    HAL::STM32::${FAMILY}::ADC
    HAL::STM32::${FAMILY}::CORTEX
    HAL::STM32::${FAMILY}::DAC
    HAL::STM32::${FAMILY}::EXTI
    HAL::STM32::${FAMILY}::GPIO
    HAL::STM32::${FAMILY}::RCC
    HAL::STM32::${FAMILY}::TIM
    CMSIS::STM32::${DEVICE}
    STM32::NoSys
    BSP
)

add_subdirectory ("docs")
add_subdirectory("tests")
