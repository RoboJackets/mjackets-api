/**
  ******************************************************************************
  * @file           : ClockHandler.hpp
  * @brief          : Clock configuration API
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

 #pragma once

 #include "mJackets.hpp"

/**
 * @brief Initialized the GPIO clock of a pin if not already initialized
 * 
 * @param pin Pin def external to board
 */
 void GpioClockInit(PinName pin);