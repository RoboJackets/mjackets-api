project(Test LANGUAGES C CXX)

function(add_test test_file)
    get_filename_component(test_name ${test_file} NAME_WE)

    add_executable(${test_name}.elf
        ../rtos_hooks.c
        ${test_file}
    )

    target_link_libraries(${test_name}.elf ${ARCH}xx ${ARCH}_API_CPP FreeRTOS)

    add_custom_target(test-${test_name} ALL
        arm-none-eabi-objcopy -Obinary "${test_name}.elf" "${test_name}.bin"
        WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
        DEPENDS ${test_name}.elf
        COMMENT "objcopying to make binary executable for ${test_name}"
    )

    add_custom_target(upload-${test_name}
        COMMAND ${FLASH_COPY_SCRIPT} "${test_name}.bin"
        WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
        DEPENDS test-${test_name}
        COMMENT "Copying binary ${test_name} to MCU"
    )
endfunction()

file(GLOB files "./*.cpp")
foreach(file ${files})
    add_test(${file})
endforeach()
