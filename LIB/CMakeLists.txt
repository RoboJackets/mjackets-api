project(External_Libraries LANGUAGES C)

add_subdirectory(CMSIS/DSP_Lib)
add_subdirectory(CMSIS/Drivers)
add_subdirectory(CMSIS/Core)
add_subdirectory(CMSIS/Core_A)
add_subdirectory(FreeRTOS)
add_subdirectory(FatFs)
add_subdirectory(STM32_USB_Device_Library)