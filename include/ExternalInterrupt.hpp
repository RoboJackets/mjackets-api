#pragma once

#include "mJackets.hpp"

/**
 * @brief External Interrupt Modes
 *
 */
typedef enum InterruptMode {
  INTERRUPT_RISING = GPIO_MODE_IT_RISING,
  INTERRUPT_FALLING = GPIO_MODE_IT_FALLING,
  INTERRUPT_RISING_FALLING = GPIO_MODE_IT_RISING_FALLING
};

class ExternalInterrupt {
 public:
  /** Configures GPIO pin to generate an external interrupt
   *
   * @param pin Pin def external to board
   * @param function Interrupt callback function
   * @param pull Pin pull type (pull up, pull down, or no pull)
   * @param mode Interrupt mode (rising edge, falling edge, or both edges)
   * @param priority Interrupt priority
   */
  ExternalInterrupt(PinName pin, void (*function)(), PullType pull = PullNone,
                    InterruptMode mode = INTERRUPT_RISING,
                    uint32_t priority = 0);

  ~ExternalInterrupt();

  /** Reads current value of pin
   *
   * @param pin Pin def external to board
   * @return 1 (high) or 0 (low)
   */
  int Read(void);

 protected:
  PinName pin_;

  /**
   * @brief Configures external interrupt
   *
   * Enables the external interrupt and sets the interrupt priority
   * and callback function.
   *
   * @param pin
   * @param function
   * @param priority
   */
  void Config(uint16_t pin, void (*function)(), uint32_t priority);
};

/**
 * @brief Checks if interrupt is active on the specified line
 *
 * @param line
 * @return true
 * @return false
 */
bool Pending(uint32_t line);