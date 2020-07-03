project(${ARCH}_API_C_lib LANGUAGES C)

aux_source_directory(Src/ API_C_SRC)

add_library(${ARCH}_API_C
    ${API_C_SRC}
)

target_include_directories(${ARCH}_API_C PUBLIC
    Inc/
    ./
    ${CMAKE_SOURCE_DIR}/bsp/config
)

target_link_libraries(${ARCH}_API_C PUBLIC ${ARCH}xx_HAL)