if(NOT CMSIS_FIND_COMPONENTS)
    set(CMSIS_FIND_COMPONENTS
       MTRAIN
    )
endif()

if(BOARD STREQUAL "MTRAIN")
    add_subdirectory(Robojackets/mTrain)
endif()

if( BOARD_HAL_CONFIG AND
    BOARD_PIN_DEFS)

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