cmake_minimum_required(VERSION 3.10)

project(
  mjackets-api
  LANGUAGES C CXX
  )

add_subdirectory(API)
add_subdirectory(HAL)
add_subdirectory(LIB)
# add_subdirectory(TEST) TODO: Add CMakeLists.txt
