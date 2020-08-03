#include "bsp.h"

#if defined STM32F4
    #include "stm32f4xx_hal.h"
#endif
#if defined STM32F7
    #include "stm32f7xx_hal.h"
#endif

/* MCU support package (MSP)*/

void HAL_MspInit(void)
{
    __HAL_RCC_PWR_CLK_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    // TODO
}

void HAL_MspDeInit(void)
{
    // TODO
}