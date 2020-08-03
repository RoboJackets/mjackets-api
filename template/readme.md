# readme.md

This directory contains a project template to serve as a starting point for mJackets based projects. 

## Project Setup Instructions
1. Copy the contents of this directory into your project directory.
2. Open a command line terminal in the project directory and type `git submodule init` to download and intialize the mJackets API into your project directory.
3. Uncomment the appropriate line in CMakeLists.txt file to match your target architecture.
4. Edit/replace the PinDefs.hpp file in the /bsp/config directory to match your target board. 
5. Copy your HAL config file from STM32CubeMX into the /bsp/config directory.
6. Copy the flash linker script generated by STM32CubeMX into the /bsp directory. 
7. Copy the startup.s file generated by STM32CubeMX into the /bsp directory. 
8. Uncomment the appropriate lines in CMakeLists.txt to enable the desired modules.
9. Add the line `#include "mJackets.h"` in your main.cpp file if not present to incorporate the mJackets API into your project. 

## TODO
- Add a script to check that the previously mentioned files are present before building. 