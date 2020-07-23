
/**
  ******************************************************************************
  * @file           : bsp.h
  * @brief          : Hardware intialization code
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/

/* Include board specific hardware initialization files here */

/* Private function prototypes -----------------------------------------------*/
extern void bsp_config(void);

void SystemClock_Config(void);
void Error_Handler(void);
void MPU_Config(void);
void DWT_Config(void);

#ifdef __cplusplus
}
#endif

#endif /* _BSP_H */