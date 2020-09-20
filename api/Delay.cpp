/**
  ******************************************************************************
  * @file           : Delay.cpp
  * @brief          : Time Delay API
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

#include "Delay.hpp"

uint32_t CurrentTick() {
    volatile uint32_t cur_tick = DWT->CYCCNT;
    return cur_tick;
}

void DelayTick(uint32_t ticks) {
    volatile uint32_t start_tick = DWT->CYCCNT;
    do {} while (DWT->CYCCNT - start_tick < ticks);
}

void DelayUs(uint32_t us) // microseconds
{
    volatile uint32_t delay_ticks = us * (SystemCoreClock/1000000L);
    volatile uint32_t start_tick = DWT->CYCCNT;

    do {} while (DWT->CYCCNT - start_tick < delay_ticks);
}

void DelayMs(uint32_t ms) // milliseconds
{
    HAL_Delay(ms);
}
