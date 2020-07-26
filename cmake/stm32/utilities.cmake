# MIT License

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

function(stm32_util_create_family_targets FAMILY)
    if(NOT (TARGET STM32::${FAMILY}))
        add_library(STM32::${FAMILY} INTERFACE IMPORTED)
        target_compile_options(STM32::${FAMILY} INTERFACE 
            --sysroot="${TOOLCHAIN_SYSROOT}"
            -mthumb -mabi=aapcs -Wall -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin -ffast-math
            $<$<CONFIG:Debug>:-Og>
            $<$<CONFIG:Release>:-Os>
        )
        target_link_options(STM32::${FAMILY} INTERFACE 
            --sysroot="${TOOLCHAIN_SYSROOT}"
            -mthumb -mabi=aapcs -Wl,--gc-sections
            $<$<CONFIG:Debug>:-Og>
            $<$<CONFIG:Release>:-Os -s>
        )
        target_compile_definitions(STM32::${FAMILY} INTERFACE 
            STM32${FAMILY}
        )
    endif()
    foreach(TYPE ${STM32_${FAMILY}_TYPES})
        if(NOT (TARGET STM32::${TYPE}))
            add_library(STM32::${TYPE} INTERFACE IMPORTED)
            target_link_libraries(STM32::${TYPE} INTERFACE STM32::${FAMILY})
            target_compile_definitions(STM32::${TYPE} INTERFACE 
                STM32${TYPE}
            )
        endif()
    endforeach()
endfunction()