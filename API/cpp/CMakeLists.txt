project(${ARCH}_API_CPP_lib LANGUAGES CXX)

aux_source_directory(Src/ API_CPP_SRC)
aux_source_directory(../c/Src/ API_C_SRC)

add_library(${ARCH}_API_CPP
    ${API_CPP_SRC}
    ${API_C_SRC}
)

target_include_directories(${ARCH}_API_CPP PUBLIC
    Inc/
    ./
    ../c/Inc/
    ${CMAKE_SOURCE_DIR}/BSP/config/hal
)

target_link_libraries(${ARCH}_API_CPP PUBLIC ${ARCH}xx_HAL)