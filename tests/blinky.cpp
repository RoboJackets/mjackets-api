/**
  ******************************************************************************
  * @file           : blinky.cpp
  * @brief          : Test to blink an LED
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

#include "mJackets.hpp"

 int main(void)
{
  /* GPIO Configuration */
  DigitalOut my_led(TEST_LED1, PullNone, PushPull);

  /* Infinite loop */
  while (1)
  {
    my_led.Toggle();
    HAL_Delay(500);
  }

}