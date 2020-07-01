project($ENV{ARCH}_API_CPP_lib LANGUAGES CXX)

aux_source_directory(Src/ API_CPP_SRC)
aux_source_directory(../c/Src/ API_C_SRC)

add_library($ENV{ARCH}_API_CPP
    ${API_CPP_SRC}
    ${API_C_SRC}
)

target_include_directories($ENV{ARCH}_API_CPP PUBLIC
    Inc/
    ./
    ../c/Inc/
    ${CMAKE_SOURCE_DIR}/BSP/config/hal
)

target_link_libraries($ENV{ARCH}_API_CPP PUBLIC $ENV{ARCH}xx_HAL)