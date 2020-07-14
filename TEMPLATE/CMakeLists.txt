cmake_minimum_required(VERSION 3.4)

project(myProject LANGUAGES C CXX)

include("gcc_stm32")

add_subdirectory(BSP)
add_subdirectory(mJackets-api)

# Top level source files
add_executable(${CMAKE_PROJECT_NAME} 
	"${CMAKE_SOURCE_DIR}/main.cpp"
)

# Libraries the top level executable is dependant on
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC
	STM32_HAL
	STM32_API_CPP
	EXTERN_LIB
)
