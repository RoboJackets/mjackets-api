cmake_minimum_required(VERSION 3.4)

project(myProject LANGUAGES C CXX)

## Uncomment the line below and specify the full STM32 chip code to hardcode the
## build target. Otherwise, pass the chip code during build time using the 
## build flag -DCHIP=<YOUR_CHIP_ID>. The latter option is preferred so you can 
## easily build for multiple targets.
# set(CHIP <FULL_STM32_CHIP_ID)

include("gcc_stm32")

add_subdirectory(BSP)
add_subdirectory(mJackets-api)

# Top level source files
add_executable(${CMAKE_PROJECT_NAME} 
	"${CMAKE_SOURCE_DIR}/main.cpp"
)

# Libraries the top level executable is dependant on
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
	${STM32_FAMILY}_HAL
	STM32_API_CPP
	EXTERN_LIB
)
