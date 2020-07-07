cmake_minimum_required(VERSION 3.4)

project(
    myProject
    LANGUAGES C CXX
)

add_definitions(-Wall)
set(CMAKE_BUILD_TYPE Debug)

set (CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_STANDARD_REQUIRED  ON )

set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} \
    -T '${CMAKE_SOURCE_DIR}/bsp/flash.ld'")

add_subdirectory(BSP)

# Uncomment the appropriate option to match the architecture on your board!
# set( ARCH STM32F4 INTERNAL )
# set( ARCH STM32F7 INTERNAL )

## Global preprocessor definitions 

add_compile_definitions( -D${ARCH}xx )

# Hardware Modules to Include
# add_compile_definitions( -DUSE_USB_FS )
# add_compile_definitions( -DUSE_USB_HS )
# add_compile_definitions( -DUSE_QSPI )

# OS Modules to include
# add_compile_definitions( -DUSE_RTOS )



