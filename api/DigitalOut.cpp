/**
  ******************************************************************************
  * @file           : DigitalOut.cpp
  * @brief          : Digital Output API
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

#include "DigitalOut.hpp"

DigitalOut::DigitalOut(PinName pin, PullType pull, PinMode mode, PinSpeed speed,
        bool inverted) : pin(pin), inverted(inverted) {
    GPIO_InitTypeDef pin_structure = {};
    pin_structure.Pin = pin.pin;
    pin_structure.Mode = mode;
    pin_structure.Pull = pull;
    pin_structure.Speed = speed;
    
    HAL_GPIO_Init(pin.port, &pin_structure);
}

void DigitalOut::DeInit() {
    HAL_GPIO_DeInit(pin_.port, pin_.pin);
}

void DigitalOut::write(bool state) {
    HAL_GPIO_WritePin(pin.port, pin.pin, (GPIO_PinState)(state != inverted));
}

void DigitalOut::toggle() {
    HAL_GPIO_TogglePin(pin.port, pin.pin);
}

bool DigitalOut::read() {
    return HAL_GPIO_ReadPin(pin.port, pin.pin);
}
