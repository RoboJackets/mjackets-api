project($ENV{ARCH}_API_C_lib LANGUAGES C)

aux_source_directory(Src/ API_C_SRC)

add_library($ENV{ARCH}_API_C
    ${API_C_SRC}
)

target_include_directories($ENV{ARCH}_API_C PUBLIC
    Inc/
    ./
    ${CMAKE_SOURCE_DIR}/BSP/config/hal
)

target_link_libraries($ENV{ARCH}_API_C PUBLIC $ENV{ARCH}xx_HAL)