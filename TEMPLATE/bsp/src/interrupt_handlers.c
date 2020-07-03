
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

/* Private function prototypes -----------------------------------------------*/

extern void osSystickHandler(void);

void SysTick_Handler(void)
{
    HAL_IncTick();
    osSystickHandler();
}

/* USB Event Interrupt Handlers */
#ifdef USE_USB_FS || USE_USB_HS
    extern PCD_HandleTypeDef hpcd;
#endif
#ifdef USE_USB_FS
    void OTG_FS_IRQHandler(void)
    {
        HAL_PCD_IRQHandler(&hpcd);
    }
#elif USE_USB_HS
    void OTG_HS_IRQHandler(void)
    {
        HAL_PCD_IRQHandler(&hpcd);
    }
#endif

/* QSPI Event Interrupt Handlers */
#ifdef USE_QSPI
    extern QSPI_HandleTypeDef QSPIHandle;

    void QUADSPI_IRQHandler(void)
    {
        HAL_QSPI_IRQHandler(&QSPIHandle);
    }
#endif

/* User-Defined Interrupt Handlers */
