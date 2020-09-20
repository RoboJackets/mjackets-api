#pragma once

#include "mJackets.hpp"

/**
 * @brief External Interrupt Modes
 *
 */
enum InterruptMode {
  kInterruptRising = GPIO_MODE_IT_RISING,
  kInterruptFalling = GPIO_MODE_IT_FALLING,
  kInterruptEdge = GPIO_MODE_IT_RISING_FALLING
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
                    InterruptMode mode = kInterruptRising,
                    uint32_t priority = 0);

  ~ExternalInterrupt();

  /** Reads current value of pin
   *
   * @param pin Pin def external to board
   * @return 1 (high) or 0 (low)
   */
  int Read(void);

  /**
   * @brief Disables the interrupt request
   *
   */
  void DisableIRQn(void);

  /**
   * @brief Enables the interrupt request
   *
   */
  void EnableIRQn();

 protected:
  PinName pin_;
  IRQn_Type irqn_;

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