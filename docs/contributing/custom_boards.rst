.. _custom-boards:

Custom Boards
#############

mJackets API provides the ability to define custom boards to be incorporated into the build system. Once a board has been fully defined, the end user can 
then use that board definition in their application by setting the board flag when calling CMake:

.. code-block:: CMake

    cmake configure . -D BOARD=<your_board>

Adding a New Board Definition
#############################

Refer to the following process when adding a new board.

1. Create a new folder under the `boards` directory for your board. You will need a separate `source` and `include` folders within your board folder. 

2. In your `include` directory, add your pin definition and HAL config files associated with your board. These two files are required, and they must conform with
the following naming convention. The pin definition file must be named :file:`PinDefs.hpp`, and the HAL config must use the default pattern used by STM32CubeMX of
:file:`stm32<FAMILY>xx_hal_conf.h`, where <FAMILY> is replaced by the STM32 Chip family of the microcontroller on your board. You can optionally add any other board specific 
configuration or header files into the `include` directory that you want added to the include path for the compiler. 

3. If your board uses a non-default startup program or linker script, you can place these files into the board directory's `source` folder. Make sure that the startup file has
the name :file:`Startup.s` and the linker script follows the naming convention :file:`STM32<DEVICE>.ld`, where <DEVICE> should be replaced by the chip device ID. These files
will be searched for automatically by cmake if the board is defined, and if they are not provided, cmake will default to using the default files.

4. In your board directory, you will need to add a `CMakeLists.txt` file to define a CMake project for your board. Several things need to be in this file in order
for the build system to correctly utilize your board definition. 

    - You will need to set the `BSP_PATH` variable to your board directory using the code below:

        .. code-block:: CMake

            set(BSP_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Path to BSP directory")

    - The entire STM32 microcontroller device ID needs to be specified:

        .. code-block:: CMake

            set(CHIP STM32F769NI CACHE STRING "Full STM32 Chip Model")

    - The board revision needs to be specified:

        .. code-block:: CMake

            set(BOARD_VERSION "1.0")
    
    - Source files need to be added to the board library:
    
        .. code-block:: CMake

            add_library(BSP
                source/board_init.c
            )
    
    - The include path where your pin definitions and HAL config exist needs to be specified:

        .. code-block:: CMake

            set(BOARD_INCLUDE_DIRS "${BSP_PATH}/include" CACHE STRING "Path to BSP include directory")
            target_include_directories(BSP PUBLIC ${BOARD_INCLUDE_DIRS})

    - The board project will need to be linked against the API project to bring in all of the HAL definitions:

        .. code-block:: CMake

            target_link_libraries(BSP PUBLIC API)

The full CMakeLists.txt should look similar to this:

.. code-block:: CMake

    cmake_minimum_required(VERSION 3.14)
    project(BSP LANGUAGES C CXX ASM)

    set(BSP_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "Path to BSP directory")
    set(CHIP STM32F769NI CACHE STRING "Full STM32 Chip Model")
    set(FAMILY F7 CACHE STRING "STM32 Target Device Family")

    set(BOARD_VERSION "1.0")

    add_library(BSP
        source/board_init.c
    )

    set(BOARD_INCLUDE_DIRS "${BSP_PATH}/include" CACHE STRING "Path to BSP include directory")

    target_include_directories(BSP PUBLIC ${BOARD_INCLUDE_DIRS})
    target_link_libraries(BSP PUBLIC API)


5. Finally, you will need to make the following modifications to the :file:`cmake/FindBoard.cmake` file to include your new board definition.

    - Add your board's define flag to the `BOARD_FIND_COMPONENTS` list.

    - Add the board project to the build if the board is defined by adding the following:

        .. code-block:: CMake

            if (BOARD)
                .
                .  // Other boards
                .

                if(BOARD STREQUAL "<YOUR_BOARD_DEFINE_FLAG>")
                    add_subdirectory(${MJACKETS_PATH}/boards/<PATH_TO_BOARD_DIR>)
                endif()
                .
                .
                .

That is it! If you followed the steps correctly you should be able to build for your specific board by specifing
the board flag when running cmake:

.. code-block:: CMake

    cmake configure . -D BOARD=<YOUR_BOARD_DEFINE_FLAG>

