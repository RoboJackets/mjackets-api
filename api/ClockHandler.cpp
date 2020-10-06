
/**
  ******************************************************************************
  * @file           : ClockHandler.cpp
  * @brief          : Clock Configuration API
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

 #include "ClockHandler.hpp"

void GpioClockInit(PinName pin)
{
    assert_param(IS_GPIO_ALL_INSTANCE(pin.port));
    
    #if defined(GPIOA)
    if (pin.port == GPIOA){
      if (__HAL_RCC_GPIOA_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOA_CLK_ENABLE();
          }
    }
    #endif //GPIOA

    #if defined(GPIOB)
    if (pin.port == GPIOB){
      if (__HAL_RCC_GPIOB_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOB_CLK_ENABLE();
          }
    }
    #endif //GPIOB

    #if defined(GPIOC)
    if (pin.port == GPIOC){
      if (__HAL_RCC_GPIOC_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOC_CLK_ENABLE();
          }
    }
    #endif //GPIOC

    #if defined(GPIOD)
    if (pin.port == GPIOD){
      if (__HAL_RCC_GPIOD_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOD_CLK_ENABLE();
          }
    }
    #endif //GPIOD
    
    #if defined(GPIOE)
    if (pin.port == GPIOE){
      if (__HAL_RCC_GPIOE_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOE_CLK_ENABLE();
          }
    }
    #endif //GPIOE

    #if defined(GPIOF)
    if (pin.port == GPIOF){
      if (__HAL_RCC_GPIOF_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOF_CLK_ENABLE();
          }
    }
    #endif //GPIOF

    #if defined(GPIOG)
    if (pin.port == GPIOG){
      if (__HAL_RCC_GPIOG_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOG_CLK_ENABLE();
          }
    }
    #endif //GPIOG

    #if defined(GPIOH)
    if (pin.port == GPIOH){
      if (__HAL_RCC_GPIOH_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOH_CLK_ENABLE();
          }
    }
    #endif //GPIOH

    #if defined(GPIOI)
    if (pin.port == GPIOI){
      if (__HAL_RCC_GPIOI_IS_CLK_ENABLED() == 0)
          {
              __HAL_RCC_GPIOI_CLK_ENABLE();
          }
    }
    #endif //GPIOI

}