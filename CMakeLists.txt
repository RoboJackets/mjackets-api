cmake_minimum_required(VERSION 3.14.7)

project(
  mjackets
  LANGUAGES C CXX ASM
)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(MJACKETS_PATH ${CMAKE_CURRENT_SOURCE_DIR})
include(stm32/common REQUIRED)

add_subdirectory(API)