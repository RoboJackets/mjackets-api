/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
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
#include "mJackets.hpp"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

int sampleFunction(int);

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* Standard Hal Initialization */
  HAL_Init();

  /* Clock Setup - Change to match your target config*/
  ClockInitStruct init;
  init.ClockSource = CLOCK_SOURCE_HSE;
  init.SystemFrequency = SYS_FREQ_100MHZ;
  init.HSEMultiplier = 432;
  init.HSEDivider1 =  25;
  init.HSEDivider2 = RCC_PLLP_DIV2;
  init.HSE48CKDivider = 2;
  init.AHBClkDivider = RCC_SYSCLK_DIV1;
  init.APB1ClkDivider = RCC_HCLK_DIV4;
  init.APB2ClkDivider = RCC_HCLK_DIV2;
  init.FlashLatency = 7;
  SystemClock_Config(init);
  
  /* User Code */

  /* Infinite loop */
  while (1)
  {
      /* User Code */
  }

}

/**
  * @brief  Function Description
  * @note Put any Notes Here
  * @param val Sample input argument
  * @retval Returns input argument
  */
int sampleFunction(int val)
{
    return val;
}

