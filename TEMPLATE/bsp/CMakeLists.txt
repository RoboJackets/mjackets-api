project(${ARCH}xx_lib LANGUAGES C ASM)

add_library(${ARCH}xx
    startup.s
    Src/bsp.c
    Src/interrupt_handlers.c
    Src/default_handlers.c
    Src/${ARCH}xx_hal_msp.c

    # Include any other source files here
)

target_include_directories(${ARCH}xx PUBLIC
    Inc
)

set_target_properties(${ARCH}xx PROPERTIES LINK_DEPENDS "${CMAKE_SOURCE_DIR}/BSP/flash.ld")

target_link_libraries(${ARCH}xx PUBLIC DSP ${ARCH}xx_HAL STM32_USB_Device)
