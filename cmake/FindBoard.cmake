if(NOT BOARD_FIND_COMPONENTS)
    set(BOARD_FIND_COMPONENTS
       MTRAIN
    )
endif()


if (BOARD)

    if(BOARD STREQUAL "MTRAIN")
        add_subdirectory(Robojackets/mTrain)
    endif()

    if(NOT BOARD_HAL_CONFIG)
        find_file(BOARD_HAL_CONFIG
            NAMES stm32${FAMILY_LOWER}xx_hal_conf.h
            PATHS "${BOARD_INCLUDE_DIRS}"
            NO_DEFAULT_PATH
        )
    endif()

    if(NOT BOARD_PIN_DEFS)
        find_file(BOARD_PIN_DEFS
            NAMES PinDefs.hpp
            PATHS "${BOARD_INCLUDE_DIRS}"
            NO_DEFAULT_PATH
        )
    endif()

endif()

if(BOARD_HAL_CONFIG AND BOARD_PIN_DEFS)
    set(BOARD_FOUND TRUE)
else()
    set(BOARD_FOUND FALSE)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(BOARD
    REQUIRED_VARS BOARD_INCLUDE_DIRS
    FOUND_VAR BOARD_FOUND
    VERSION_VAR BOARD_VERSION
    HANDLE_COMPONENTS
)