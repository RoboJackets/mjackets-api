/**
  ******************************************************************************
  * @file           : hardware_init.c
  * @brief          : HAL initialization functions
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

#if defined STM32F0
    #include "stm32f0xx_hal_conf.h"
    #include "stm32f0xx_hal.h"
#endif
#if defined STM32F1
    #include "stm32f1xx_hal_conf.h"
    #include "stm32f1xx_hal.h"
#endif
#if defined STM32F2
    #include "stm32f2xx_hal_conf.h"
    #include "stm32f2xx_hal.h"
#endif
#if defined STM32F3
    #include "stm32f3xx_hal_conf.h"
    #include "stm32f3xx_hal.h"
#endif
#if defined STM32F4
    #include "stm32f4xx_hal_conf.h"
    #include "stm32f4xx_hal.h"
#endif
#if defined STM32F7
    #include "stm32f7xx_hal_conf.h"
    #include "stm32f7xx_hal.h"
#endif

#include "hardware_init.h"

/**
  * @brief  System Clock Configuration
  *
  * @param  None
  * @retval None
  */
void SystemClock_Config(ClockInitStruct clock_init)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /**Configure LSE Drive Capability 
  */
  // HAL_PWR_EnableBkUpAccess();
  /**Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  //__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  if (clock_init.ClockSource == CLOCK_SOURCE_HSE)
  {
      RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
      if (HSE_VALUE != clock_init.SystemFrequency)
      {
        RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
        RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
        RCC_OscInitStruct.PLL.PLLN = clock_init.HSEMultiplier;
        RCC_OscInitStruct.PLL.PLLM = clock_init.HSEDivider1;
        RCC_OscInitStruct.PLL.PLLP = clock_init.HSEDivider2;
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
        // TODO: implement sys clock solver

      }
      else  // Sysclock = External Oscillator
      {
        RCC_OscInitStruct.HSEState = RCC_HSE_ON;
        RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
      }

      RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
      RCC_OscInitStruct.PLL.PLLQ = clock_init.HSE48CKDivider;
      // TODO: implement peripheral 48MHz clock solver
  }

  // TODO: implement additional clock sources
  
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /**Initializes the CPU, AHB and APB busses clocks 
   * TODO: Automatically set AHB and APB frequencies
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  
  RCC_ClkInitStruct.AHBCLKDivider = clock_init.AHBClkDivider;
  RCC_ClkInitStruct.APB1CLKDivider = clock_init.APB1ClkDivider;
  RCC_ClkInitStruct.APB2CLKDivider = clock_init.APB2ClkDivider;

  // TODO: Automatically select Flash Latency based on device and frequency
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, clock_init.FlashLatency) != HAL_OK)
  {
    Error_Handler();
  }
}

#ifdef __MPU_PRESENT
/**
  * @brief  Configure the MPU attributes as Write Through for Internal SRAM1/2.
  * @note   The Base Address is 0x20020000 since this memory interface is the AXI.
  *         The Configured Region Size is 512KB because the internal SRAM1/2 
  *         memory size is 384KB.
  * @param  None
  * @retval None
  */
void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20020000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_512KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}
#endif

void DWT_Config(void)
{
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CYCCNT = 0;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

#if defined(__ICACHE_PRESENT) && defined (__DCACHE_PRESENT)
/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}
#endif

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

__attribute__((weak)) void HAL_MspInit(void)
{
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_RCC_SYSCFG_CLK_ENABLE();
}