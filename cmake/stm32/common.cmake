# MIT License

# Copyright (c) 2020 Georgia Tech RoboJackets
# Copyright (c) 2012-2017 Konstantin Oblaukhov

# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

set(STM32_SUPPORTED_FAMILIES F4 F7)

function(stm32_get_chip_type FAMILY DEVICE TYPE)
    set(INDEX 0)
    foreach(C_TYPE ${STM32_${FAMILY}_TYPES})
        list(GET STM32_${FAMILY}_TYPE_MATCH ${INDEX} REGEXP)
        if(${DEVICE} MATCHES ${REGEXP})
            set(RESULT_TYPE ${C_TYPE})
        endif()
        math(EXPR INDEX "${INDEX}+1")
    endforeach()
    if(NOT RESULT_TYPE)
        message(WARNING "Invalid/unsupported device: ${DEVICE}")
    endif()
    set(${TYPE} ${RESULT_TYPE} PARENT_SCOPE)
endfunction()

function(stm32_get_chip_info CHIP FAMILY TYPE DEVICE)
    string(TOUPPER ${CHIP} CHIP)

    string(REGEX MATCH "^STM32([A-Z][0-9])([0-9A-Z][0-9][A-Z][0-9A-Z]).*$" CHIP ${CHIP})

    if((NOT CMAKE_MATCH_1) OR (NOT CMAKE_MATCH_2))
        message(FATAL_ERROR "Unknown chip ${CHIP}")
    endif()

    set(STM32_FAMILY ${CMAKE_MATCH_1})
    set(STM32_DEVICE "${CMAKE_MATCH_1}${CMAKE_MATCH_2}")

    list(FIND STM32_SUPPORTED_FAMILIES ${STM32_FAMILY} STM32_FAMILY_INDEX)
    if (STM32_FAMILY_INDEX EQUAL -1)
        message(FATAL_ERROR "Unsupported family ${STM32_FAMILY} for device ${CHIP}")
    endif()

    stm32_get_chip_type(${STM32_FAMILY} ${STM32_DEVICE} STM32_TYPE)

    set(${FAMILY} ${STM32_FAMILY} PARENT_SCOPE)
    set(${DEVICE} ${STM32_DEVICE} PARENT_SCOPE)
    set(${TYPE} ${STM32_TYPE} PARENT_SCOPE)
endfunction()

function(stm32_get_memory_info FAMILY DEVICE
    FLASH_SIZE RAM_SIZE CCRAM_SIZE STACK_SIZE HEAP_SIZE
    FLASH_ORIGIN RAM_ORIGIN CCRAM_ORIGIN
)
    string(REGEX REPLACE "^[FGHL][0-9][0-9A-Z][0-9].([3468BCDEFGHIZ])$" "\\1" SIZE_CODE ${DEVICE})

    if(SIZE_CODE STREQUAL "3")
        set(FLASH "8K")
    elseif(SIZE_CODE STREQUAL "4")
        set(FLASH "16K")
    elseif(SIZE_CODE STREQUAL "6")
        set(FLASH "32K")
    elseif(SIZE_CODE STREQUAL "8")
        set(FLASH "64K")
    elseif(SIZE_CODE STREQUAL "B")
        set(FLASH "128K")
    elseif(SIZE_CODE STREQUAL "C")
        set(FLASH "256K")
    elseif(SIZE_CODE STREQUAL "D")
        set(FLASH "384K")
    elseif(SIZE_CODE STREQUAL "E")
        set(FLASH "512K")
    elseif(SIZE_CODE STREQUAL "F")
        set(FLASH "768K")
    elseif(SIZE_CODE STREQUAL "G")
        set(FLASH "1024K")
    elseif(SIZE_CODE STREQUAL "H")
        set(FLASH "1536K")
    elseif(SIZE_CODE STREQUAL "I")
        set(FLASH "2048K")
    elseif(SIZE_CODE STREQUAL "Z")
        set(FLASH "192K")
    else()
        set(FLASH "16K")
        message(WARNING "Unknow flash size for device ${DEVICE}. Set to ${FLASH}")
    endif()

    stm32_get_chip_type(${FAMILY} ${DEVICE} TYPE)
    list(FIND STM32_${FAMILY}_TYPES ${TYPE} TYPE_INDEX)
    list(GET STM32_${FAMILY}_RAM_SIZES ${TYPE_INDEX} RAM)
    list(GET STM32_${FAMILY}_CCRAM_SIZES ${TYPE_INDEX} CCRAM)

    if(FAMILY STREQUAL "F1")
        stm32f1_get_memory_info(${DEVICE} ${TYPE} FLASH RAM)
    elseif(FAMILY STREQUAL "L1")
        stm32l1_get_memory_info(${DEVICE} ${TYPE} FLASH RAM)
    elseif(FAMILY STREQUAL "F2")
        stm32f2_get_memory_info(${DEVICE} ${TYPE} FLASH RAM)
    elseif(FAMILY STREQUAL "F3")
        stm32f3_get_memory_info(${DEVICE} ${TYPE} FLASH RAM)
    endif()

    set(${FLASH_SIZE} ${FLASH} PARENT_SCOPE)
    set(${RAM_SIZE} ${RAM} PARENT_SCOPE)
    set(${CCRAM_SIZE} ${CCRAM} PARENT_SCOPE)
    if (RAM STREQUAL "2K")
        # Potato MCUs
        set(${STACK_SIZE} 0x200 PARENT_SCOPE)
        set(${HEAP_SIZE} 0x100 PARENT_SCOPE)
    else()
        set(${STACK_SIZE} 0x400 PARENT_SCOPE)
        set(${HEAP_SIZE} 0x200 PARENT_SCOPE)
    endif()
    set(${FLASH_ORIGIN} 0x8000000 PARENT_SCOPE)
    set(${RAM_ORIGIN} 0x20000000 PARENT_SCOPE)
    set(${CCRAM_ORIGIN} 0x10000000 PARENT_SCOPE)
endfunction()

function(stm32_add_linker_script TARGET VISIBILITY SCRIPT)
    get_filename_component(SCRIPT "${SCRIPT}" ABSOLUTE)
    target_link_options(${TARGET} ${VISIBILITY} -T "${SCRIPT}")
endfunction()

function(STM32_ADD_HEX_BIN_TARGETS TARGET)
    if(EXECUTABLE_OUTPUT_PATH)
      set(FILENAME "${EXECUTABLE_OUTPUT_PATH}/${TARGET}")
    else()
      set(FILENAME "${TARGET}")
    endif()
    add_custom_target(${TARGET}.hex ALL DEPENDS ${TARGET} COMMAND ${CMAKE_OBJCOPY} -Oihex ${FILENAME} ${FILENAME}.hex)
    add_custom_target(${TARGET}.bin ALL DEPENDS ${TARGET} COMMAND ${CMAKE_OBJCOPY} -Obinary ${FILENAME} ${FILENAME}.bin)
endfunction()

function(STM32_PRINT_SIZE_OF_TARGETS TARGET)
    if(EXECUTABLE_OUTPUT_PATH)
      set(FILENAME "${EXECUTABLE_OUTPUT_PATH}/${TARGET}")
    else()
      set(FILENAME "${TARGET}")
    endif()
    add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND ${CMAKE_SIZE} ${FILENAME})
endfunction()

if(NOT (TARGET STM32::NoSys))
    add_library(STM32::NoSys INTERFACE IMPORTED)
    target_compile_options(STM32::NoSys INTERFACE $<$<C_COMPILER_ID:GNU>:--specs=nosys.specs>)
    target_link_options(STM32::NoSys INTERFACE $<$<C_COMPILER_ID:GNU>:--specs=nosys.specs>)
endif()



include(stm32/utilities)
include(stm32/f0)
include(stm32/f1)
include(stm32/f2)
include(stm32/f3)
include(stm32/f4)
include(stm32/f7)
include(stm32/g0)
include(stm32/g4)
include(stm32/h7)
include(stm32/l0)
include(stm32/l1)
include(stm32/l4)

stm32_get_chip_info(${CHIP} STM32_FAMILY STM32_TYPE STM32_DEVICE)
set(FAMILY ${STM32_FAMILY} CACHE STRING "STM32 Target Device Family")
set(TYPE ${STM32_TYPE} CACHE STRING "STM32${FAMILY} Target Device Type")
set(DEVICE ${STM32_DEVICE} CACHE STRING "STM32${FAMILY} Target Device")