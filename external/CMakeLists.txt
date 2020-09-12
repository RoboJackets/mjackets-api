cmake_minimum_required(VERSION 3.14.7)

project(
  EXTERNAL_LIBS
  LANGUAGES C CXX ASM
)

if (FAMILY STREQUAL "F0")
    set(PORT "ARM_CM0")
elseif (FAMILY STREQUAL "F3")
    set(PORT "ARM_CM3")
elseif (FAMILY STREQUAL "F4")
    set(PORT "ARM_CM4F")
elseif (FAMILY STREQUAL "F7")
    set(PORT "ARM_CM7/r0p1")
endif()

if(PORT)

    add_library(FreeRTOS  STATIC
        stm32_mw_freertos/Source/CMSIS_RTOS/cmsis_os.c
        stm32_mw_freertos/Source/croutine.c
        stm32_mw_freertos/Source/event_groups.c
        stm32_mw_freertos/Source/list.c
        stm32_mw_freertos/Source/queue.c
        stm32_mw_freertos/Source/tasks.c
        stm32_mw_freertos/Source/timers.c
        stm32_mw_freertos/Source/portable/Common/mpu_wrappers.c
        stm32_mw_freertos/Source/portable/GCC/${PORT}/port.c
        stm32_mw_freertos/Source/portable/MemMang/heap_3.c
    )

    target_include_directories(FreeRTOS PUBLIC
        stm32_mw_freertos/Source/include
        stm32_mw_freertos/Source/CMSIS_RTOS
        stm32_mw_freertos/Source/portable/GCC/${PORT}
    )
endif()