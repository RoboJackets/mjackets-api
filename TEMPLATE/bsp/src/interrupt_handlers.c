
/**
  ******************************************************************************
  * @file           : interrupt_handelers.c
  * @brief          : Code for handling interrupts
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 RoboJackets.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by RoboJackets under Apache License
  * 2.0; You may not use this file except in compliance with the License. You 
  * may obtain a copy of the License at: 
  *                    https://www.apache.org/licenses/LICENSE-2.0
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "bsp.h"
#if defined STM32F4
    #include "stm32f4xx_hal.h"
#endif
#if defined STM32F7
    #include "stm32f7xx_hal.h"
#endif

/* Private function prototypes -----------------------------------------------*/

extern void osSystickHandler(void);

void SysTick_Handler(void)
{
    HAL_IncTick();
    osSystickHandler();
}

/* User-Defined Interrupt Handlers */
