/**
  ******************************************************************************
  * @file           : DigitalIn.cpp
  * @brief          : Digital Input API
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

#include "DigitalIn.hpp"

DigitalIn::DigitalIn(PinName pin, PullType pull) : pin(pin) {
    GPIO_InitTypeDef pin_structure;
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = GPIO_MODE_INPUT;
    pin_structure.Pull = pull;
    
    HAL_GPIO_Init(pin.port, &pin_structure);
}
DigitalIn::~DigitalIn() {
    HAL_GPIO_DeInit(pin.port, pin.pin);
}

bool DigitalIn::read() {
    return HAL_GPIO_ReadPin(pin.port, pin.pin);
}
