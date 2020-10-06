/**
  ******************************************************************************
  * @file           : DigitalIn.hpp
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

#pragma once

#include "mJackets.hpp"

class DigitalIn {
public:
    /** Configures GPIO pin for digital in
     *
     * @param pin Pin def external to board
     * @param pull Pin pull type
     */
    DigitalIn(PinName pin, PullType pull = PullType::PullNone);

    /**
     * @brief Deinitializes the GPIO pin as a digital input
     * 
     */
    void DeInit();

    /** Read current value of pin
     *
     * @return true (high) or false (low)
     */
    bool Read();

    /**
     * @brief Boolean operator overload to return current pin value
     * 
     * @return true 
     * @return false 
     */
    operator bool() {
        return Read();
    }

    /**
     * @brief Function to change pull type after object initialization
     * 
     * @param pull Pin pull type
     */
    void setPull(PullType pull);

private:
    /**
     * @brief GPIO pin associated with the class instance
     * 
     */
    PinName pin_;
};
