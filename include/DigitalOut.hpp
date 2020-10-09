#pragma once
#include "mJackets.hpp"

class DigitalOut {
public:
    /** Configures GPIO pin for digital in
     *
     * @param pin Pin def external to board
     * @param pull Pin pull type
     * @param mode Output mode (push-pull or open-drain)
     * @param speed GPIO frequency
     * @param inverted Inverts output value of pin
     */
    DigitalOut(PinName pin, PullType pull = PullType::PullNone,
        PinMode mode = PinMode::PushPull, PinSpeed speed = PinSpeed::Low,
        bool inverted = false);

    /**
     * @brief Deinitializes the GPIO pin as a digital output
     * 
     */
    void DeInit();

    /** Change output state of pin
     *
     * @param state Set output value of pin (0 or 1)
     *     In open-drain 0 is high-z, 1 is drive low
     */
    void write(bool state);

    /** Toggle pin output
     *
     */
    void toggle();

    /** Read current value of pin
     *
     * @return true (high) or false (low)
     */
    bool read();

    /**
     * @brief Assignment operator overload to set pin value
     * 
     * @param rhs 
     */
    void operator =(bool rhs) {
        write(rhs);
    }

    /**
     * @brief Boolean operator overload to set pin value
     * 
     * @return true 
     * @return false 
     */
    operator bool() {
        return read();
    }

protected:
    /**
     * @brief GPIO pin associated with the class instance
     * 
     */
    PinName pin;

    /**
     * @brief Parameter defining whether the output logic should be inverted
     * 
     */
    bool inverted;
};
