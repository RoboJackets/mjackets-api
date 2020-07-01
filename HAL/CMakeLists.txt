project($ENV{ARCH}xx_HAL LANGUAGES C)

aux_source_directory($ENV{ARCH}xx_HAL_Drivers/Src $ENV{ARCH}xx_HAL_SRC)

ifeq ($ENV{ARCH}, STM32F4)
	add_library($ENV{ARCH}xx_HAL
		${$ENV{ARCH}xx_HAL_SRC}
	)
endif

ifeq ($ENV{ARCH}, STM32F7)
	add_library($ENV{ARCH}xx_HAL
		${$ENV{ARCH}xx_HAL_SRC}
		CMSIS/Device/$ENV{ARCH}xx/Src/system_stm32f7xx.c
	)
endif



target_include_directories($ENV{ARCH}xx_HAL PUBLIC
   	$ENV{ARCH}xx_HAL_Drivers/Inc
	CMSIS/Device/$ENV{ARCH}xx/Include
    	CMSIS/Include
)

# Include HAL configuration from BSP
target_compile_definitions($ENV{ARCH}xx_HAL PUBLIC USE_HAL_DRIVER)
target_include_directories($ENV{ARCH}xx_HAL PUBLIC ${CMAKE_SOURCE_DIR}/BSP/config/hal)

target_link_libraries($ENV{ARCH}xx_HAL PUBLIC DSP)