project(BSP LANGUAGES C ASM)

add_library(BSP
    src/startup.s
    Src/bsp.c
    Src/interrupt_handlers.c
    Src/default_handlers.c
    Src/${STM32_FAMILY}xx_hal_msp.c
)

target_include_directories(BSP PUBLIC
    inc
)

target_link_libraries(BSP PUBLIC ${STM32_FAMILY}_HAL EXTERNAL_LIB)
