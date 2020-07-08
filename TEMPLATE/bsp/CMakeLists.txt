project(BSP LANGUAGES C ASM)

add_library(BSP
    startup.s
    Src/bsp.c
    Src/interrupt_handlers.c
    Src/default_handlers.c
    Src/${ARCH}xx_hal_msp.c

    # Include any other source files here
)

target_include_directories(BSP PUBLIC
    inc
)

set_target_properties(BSP PROPERTIES LINK_DEPENDS "${CMAKE_SOURCE_DIR}/BSP/flash.ld")

target_link_libraries(BSP PUBLIC DSP ${ARCH}xx_HAL STM32_USB_Device)
