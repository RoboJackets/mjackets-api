project(STM32_API_CPP_lib LANGUAGES CXX)

add_library(STM32_API_CPP
    src/AnalogIn.cpp
    src/DigitalIn.cpp
    src/DigitalOut.cpp
    src/I2C.cpp
    src/SPI.cpp
)

target_include_directories(STM32_API_CPP PUBLIC
    inc/
)

target_link_libraries(STM32_API_CPP PUBLIC ${STM32_FAMILY}_HAL BSP EXTERN_LIB)
