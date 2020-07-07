project(${ARCH}_API_CPP_lib LANGUAGES CXX)

aux_source_directory(src/ API_CPP_SRC)

add_library(${ARCH}_API_CPP
    ${API_CPP_SRC}
)

target_include_directories(${ARCH}_API_CPP PUBLIC
    inc/
    ./
    ${CMAKE_SOURCE_DIR}/bsp/config/
)

target_link_libraries(${ARCH}_API_CPP PUBLIC ${ARCH}xx_HAL)
