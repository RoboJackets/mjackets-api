project(${ARCH}xx_HAL LANGUAGES C)

aux_source_directory(${ARCH}xx_HAL_Drivers/Src ${ARCH}xx_HAL_SRC)

ifeq (${ARCH}, STM32F4)
	add_library(${ARCH}xx_HAL
		${${ARCH}xx_HAL_SRC}
		CMSIS/Device/${ARCH}xx/Src/system_stm32f4xx.c
	)
endif

ifeq (${ARCH}, STM32F7)
	add_library(${ARCH}xx_HAL
		${${ARCH}xx_HAL_SRC}
		CMSIS/Device/${ARCH}xx/Src/system_stm32f7xx.c
	)
endif



target_include_directories(${ARCH}xx_HAL PUBLIC
   	${ARCH}xx_HAL_Drivers/Inc
	CMSIS/Device/${ARCH}xx/Include
)

# Include HAL configuration from BSP
target_compile_definitions(${ARCH}xx_HAL PUBLIC USE_HAL_DRIVER)
target_include_directories(${ARCH}xx_HAL PUBLIC ${CMAKE_SOURCE_DIR}/bsp/config)

target_link_libraries(${ARCH}xx_HAL PUBLIC DSP)