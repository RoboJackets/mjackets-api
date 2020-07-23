if(NOT CMSIS_FIND_COMPONENTS)
    set(CMSIS_FIND_COMPONENTS
        STM32F4 STM32F7
    )
endif()

include(stm32/devices)

if(NOT CMSIS_CORE_PATH)
    set(CMSIS_CORE_PATH ${MJACKETS_PATH}/LIB/cmsis_core CACHE PATH "Path to cmsis_core")
endif()

if(NOT CMSIS_CORE_VERSION)
    find_file(CMSIS_CORE_PDSC
        NAMES ARM.CMSIS.pdsc
        PATHS "${CMSIS_CORE_PATH}"
        NO_DEFAULT_PATH
    )
    if (NOT CMSIS_CORE_PDSC)
        set(CMSIS_CORE_VERSION "0.0.0")
    else()
        file(STRINGS "${CMSIS_CORE_PDSC}" VERSION_STRINGS REGEX "<release version=\"([0-9]*\\.[0-9]*\\.[0-9]*)\" date=\"[0-9]+\\-[0-9]+\\-[0-9]+\">")
        list(GET VERSION_STRINGS 0 STR)
        string(REGEX MATCH "<release version=\"([0-9]*)\\.([0-9]*)\\.([0-9]*)\" date=\"[0-9]+\\-[0-9]+\\-[0-9]+\">" MATCHED ${STR})
        set(CMSIS_CORE_VERSION "${CMAKE_MATCH_1}.${CMAKE_MATCH_2}.${CMAKE_MATCH_3}" CACHE INTERNAL "CMSIS STM32 Core version")
    endif()
endif()

set(CMSIS_${COMP}_VERSION ${CMSIS_CORE_VERSION})
set(CMSIS_VERSION ${CMSIS_${COMP}_VERSION})

find_path(CMSIS_CORE_COMMON_INCLUDE
    NAMES cmsis_gcc.h
    PATHS "${CMSIS_CORE_PATH}/Include"
    NO_DEFAULT_PATH
)
list(APPEND CMSIS_INCLUDE_DIRS "${CMSIS_CORE_COMMON_INCLUDE}")
    
function(cmsis_generate_default_linker_script FAMILY DEVICE)
    stm32_get_memory_info(${FAMILY} ${DEVICE} 
        FLASH_SIZE RAM_SIZE CCRAM_SIZE STACK_SIZE HEAP_SIZE 
        FLASH_ORIGIN RAM_ORIGIN CCRAM_ORIGIN
    )
    add_custom_command(OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/STM32${DEVICE}.ld"
        COMMAND ${CMAKE_COMMAND} 
            -DFLASH_ORIGIN="${FLASH_ORIGIN}" 
            -DRAM_ORIGIN="${RAM_ORIGIN}" 
            -DCCRAM_ORIGIN="${CCRAM_ORIGIN}" 
            -DFLASH_SIZE="${FLASH_SIZE}" 
            -DRAM_SIZE="${RAM_SIZE}" 
            -DCCRAM_SIZE="${CCRAM_SIZE}" 
            -DSTACK_SIZE="${STACK_SIZE}" 
            -DHEAP_SIZE="${HEAP_SIZE}" 
            -DLINKER_SCRIPT="${CMAKE_CURRENT_BINARY_DIR}/STM32${DEVICE}.ld"
            -P "${MJACKETS_PATH}/cmake/stm32/linker_ld.cmake"
    )
    add_custom_target(CMSIS_LD_STM32_${DEVICE} DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/STM32${DEVICE}.ld)
    add_dependencies(CMSIS::STM32::${DEVICE} CMSIS_LD_STM32_${DEVICE})
    stm32_add_linker_script(CMSIS::STM32::${DEVICE} INTERFACE "${CMAKE_CURRENT_BINARY_DIR}/STM32${DEVICE}.ld")
endfunction() 

foreach(COMP ${CMSIS_FIND_COMPONENTS})
    string(TOLOWER ${COMP} COMP_L)
    string(TOUPPER ${COMP} COMP)
    
    string(REGEX MATCH "^STM32([A-Z][0-9])([0-9A-Z][0-9][A-Z][0-9A-Z])?.*$" COMP ${COMP})
    
    if((NOT CMAKE_MATCH_1) AND (NOT CMAKE_MATCH_2))
        message(FATAL_ERROR "Unknown CMSIS component: ${COMP}")
    endif()
    if(CMAKE_MATCH_2)
        set(FAMILY ${CMAKE_MATCH_1})
        set(DEVICES "${CMAKE_MATCH_1}${CMAKE_MATCH_2}")
    else()
        set(FAMILY ${CMAKE_MATCH_1})
        stm32_get_devices_by_family(${FAMILY} DEVICES)
    endif()
    string(TOLOWER ${FAMILY} FAMILY_L) 

    find_path(CMSIS_${FAMILY}_INCLUDE
        NAMES stm32${FAMILY_L}xx.h
        PATHS "${MJACKETS_PATH}/HAL/CMSIS/Device/STM32${FAMILY}/Include"
        NO_DEFAULT_PATH
    )
    list(APPEND CMSIS_INCLUDE_DIRS "${CMSIS_${FAMILY}_INCLUDE}")

    find_file(CMSIS_${FAMILY}_SOURCE
        NAMES system_stm32${FAMILY_L}xx.c
        PATHS "${MJACKETS_PATH}/HAL/CMSIS/Device/STM32${FAMILY}/Source/Templates"
        NO_DEFAULT_PATH
    )
    list(APPEND CMSIS_SOURCES "${CMSIS_${FAMILY}_SOURCE}")
    
    if ((NOT CMSIS_CORE_COMMON_INCLUDE) OR 
        (NOT CMSIS_${FAMILY}_INCLUDE) OR 
        (NOT CMSIS_${FAMILY}_SOURCE))
        continue()
    endif()

    if(NOT (TARGET CMSIS::STM32::${FAMILY}))
        add_library(CMSIS::STM32::${FAMILY} INTERFACE IMPORTED)
        target_link_libraries(CMSIS::STM32::${FAMILY} INTERFACE STM32::${FAMILY})
        target_include_directories(CMSIS::STM32::${FAMILY} INTERFACE "${CMSIS_CORE_COMMON_INCLUDE}")
        target_include_directories(CMSIS::STM32::${FAMILY} INTERFACE "${CMSIS_${FAMILY}_INCLUDE}")
        target_sources(CMSIS::STM32::${FAMILY} INTERFACE "${CMSIS_${FAMILY}_SOURCE}")
    endif()

    set(DEVICES_FOUND TRUE)
    
    foreach(DEVICE ${DEVICES})
        stm32_get_chip_type(${FAMILY} ${DEVICE} TYPE)
        string(TOLOWER ${DEVICE} DEVICE_L)
        string(TOLOWER ${TYPE} TYPE_L)
        
        find_file(CMSIS_${FAMILY}_${TYPE}_STARTUP
            NAMES startup_stm32${TYPE_L}.s
            PATHS "${CMAKE_SOURCE_DIR}/bsp/src"
            NO_DEFAULT_PATH
        )
        if(CMSIS_${FAMILY}_${TYPE}_STARTUP)
            message(STATUS "Using startup_stm32${TYPE_L}.s found in BSP sources")
        endif()

        if(NOT(${CMSIS_${FAMILY}_${TYPE}_STARTUP}))
            find_file(CMSIS_${FAMILY}_${TYPE}_STARTUP
                NAMES startup_stm32${TYPE_L}.s
                PATHS "${MJACKETS_PATH}/HAL/CMSIS/Device/STM32${FAMILY}/Source/Templates/gcc"
                NO_DEFAULT_PATH
            )
            message(STATUS "Startup file not specified. Using default file: ${CMSIS_${FAMILY}_${TYPE}_STARTUP}")
        endif()

        list(APPEND CMSIS_SOURCES "${CMSIS_${FAMILY}_${TYPE}_STARTUP}")
        if(NOT CMSIS_${FAMILY}_${TYPE}_STARTUP)
            set(DEVICES_FOUND FALSE)
            break()
        endif()
        
        if(NOT (TARGET CMSIS::STM32::${TYPE}))
            add_library(CMSIS::STM32::${TYPE} INTERFACE IMPORTED)
            target_link_libraries(CMSIS::STM32::${TYPE} INTERFACE CMSIS::STM32::${FAMILY} STM32::${TYPE})
            target_sources(CMSIS::STM32::${TYPE} INTERFACE "${CMSIS_${FAMILY}_${TYPE}_STARTUP}")
        endif()
        
        add_library(CMSIS::STM32::${DEVICE} INTERFACE IMPORTED)
        target_link_libraries(CMSIS::STM32::${DEVICE} INTERFACE CMSIS::STM32::${TYPE})
        cmsis_generate_default_linker_script(${FAMILY} ${DEVICE})
    endforeach()
        
    if(CMSIS_CORE_COMMON_INCLUDE AND 
       CMSIS_${FAMILY}_INCLUDE AND 
       CMSIS_${FAMILY}_SOURCE AND
       DEVICES_FOUND)
       set(CMSIS_${COMP}_FOUND TRUE)
    else()
       set(CMSIS_${COMP}_FOUND FALSE)
    endif()
endforeach()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CMSIS
    REQUIRED_VARS CMSIS_INCLUDE_DIRS CMSIS_SOURCES
    FOUND_VAR CMSIS_FOUND
    VERSION_VAR CMSIS_VERSION
    HANDLE_COMPONENTS
)