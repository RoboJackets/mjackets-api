
/**
 ******************************************************************************
 * @file           : ExternalInterrupt.cpp
 * @brief          : External Interrupt API
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

#include "ExternalInterrupt.hpp"

/**
 * @brief Checks if an external interrupt is pending on the specified line
 *
 * @param line
 * @return true
 * @return false
 */
bool CheckPending(uint32_t line);

/**
 * @brief Clears any external interrupt flags on the specified line
 *
 * @param line
 */
void ClearPending(uint32_t line);

void Handler_Nothing(void) {}

void (*ExtIrq0Callback)() = &Handler_Nothing;
void (*ExtIrq1Callback)() = &Handler_Nothing;
void (*ExtIrq2Callback)() = &Handler_Nothing;
void (*ExtIrq3Callback)() = &Handler_Nothing;
void (*ExtIrq4Callback)() = &Handler_Nothing;
void (*ExtIrq5Callback)() = &Handler_Nothing;
void (*ExtIrq6Callback)() = &Handler_Nothing;
void (*ExtIrq7Callback)() = &Handler_Nothing;
void (*ExtIrq8Callback)() = &Handler_Nothing;
void (*ExtIrq9Callback)() = &Handler_Nothing;
void (*ExtIrq10Callback)() = &Handler_Nothing;
void (*ExtIrq11Callback)() = &Handler_Nothing;
void (*ExtIrq12Callback)() = &Handler_Nothing;
void (*ExtIrq13Callback)() = &Handler_Nothing;
void (*ExtIrq14Callback)() = &Handler_Nothing;
void (*ExtIrq15Callback)() = &Handler_Nothing;

/*******************************************************************************
 * External Interrupt Callbacks
 *******************************************************************************/

#if defined(STM32F7) | defined(STM32F4) | defined(STM32F1) | \
    defined(STM32F2) | defined(STM32F3) | defined(STM32G4) | \
    defined(STM32H7) | defined(STM32L1) | defined(STM32L4)

void EXTI0_IRQHandler(void) {
  ExtIrq0Callback();
  ClearPending(EXTI_LINE_0);
}

void EXTI1_IRQHandler(void) {
  ExtIrq1Callback();
  ClearPending(EXTI_LINE_1);
}

void EXTI2_IRQHandler(void) {
  ExtIrq2Callback();
  ClearPending(EXTI_LINE_2);
}

void EXTI3_IRQHandler(void) {
  ExtIrq3Callback();
  ClearPending(EXTI_LINE_3);
}

void EXTI4_IRQHandler(void) {
  ExtIrq4Callback();
  ClearPending(EXTI_LINE_4);
}

void EXTI9_5_IRQHandler(void) {
  if (CheckPending(EXTI_LINE_5)) {
    ExtIrq5Callback();
    ClearPending(EXTI_LINE_5);
  } else if (CheckPending(EXTI_LINE_6)) {
    ExtIrq6Callback();
    ClearPending(EXTI_LINE_6);
  } else if (CheckPending(EXTI_LINE_7)) {
    ExtIrq7Callback();
    ClearPending(EXTI_LINE_7);
  } else if (CheckPending(EXTI_LINE_8)) {
    ExtIrq8Callback();
    ClearPending(EXTI_LINE_8);
  } else if (CheckPending(EXTI_LINE_9)) {
    ExtIrq9Callback();
    ClearPending(EXTI_LINE_9);
  }
}

void EXTI15_10IRQHandler(void) {
  if (CheckPending(EXTI_LINE_10)) {
    ExtIrq10Callback();
    ClearPending(EXTI_LINE_10);
  } else if (CheckPending(EXTI_LINE_11)) {
    ExtIrq11Callback();
    ClearPending(EXTI_LINE_11);
  } else if (CheckPending(EXTI_LINE_12)) {
    ExtIrq12Callback();
    ClearPending(EXTI_LINE_12);
  } else if (CheckPending(EXTI_LINE_13)) {
    ExtIrq13Callback();
    ClearPending(EXTI_LINE_13);
  } else if (CheckPending(EXTI_LINE_14)) {
    ExtIrq14Callback();
    ClearPending(EXTI_LINE_14);
  } else if (CheckPending(EXTI_LINE_15)) {
    ExtIrq15Callback();
    ClearPending(EXTI_LINE_15);
  }
}

#endif

#if defined(STM32L0) | defined(STM32G0)

void EXTI0_1IRQHandler(void) {
  if (CheckPending(EXTI_LINE_0)) {
    ExtIrq0Callback();
    ClearPending(EXTI_LINE_0);
  } else if (CheckPending(EXTI_LINE_0)) {
    ExtIrq1Callback();
    ClearPending(EXTI_LINE_1);
  }
}

void EXTI2_3IRQHandler(void) {
  if (CheckPending(EXTI_LINE_2)) {
    ExtIrq2Callback();
    ClearPending(EXTI_LINE_2);
  } else if (CheckPending(EXTI_LINE_3)) {
    ExtIrq3Callback();
    ClearPending(EXTI_LINE_3);
  }
}

void EXTI4_15IRQHandler(void) {
  if (CheckPending(EXTI_LINE_4)) {
    ExtIrq4Callback();
    ClearPending(EXTI_LINE_4);
  } else if (CheckPending(EXTI_LINE_5)) {
    ExtIrq5Callback();
    ClearPending(EXTI_LINE_5);
  } else if (CheckPending(EXTI_LINE_6)) {
    ExtIrq6Callback();
    ClearPending(EXTI_LINE_6);
  } else if (CheckPending(EXTI_LINE_7)) {
    ExtIrq7Callback();
    ClearPending(EXTI_LINE_7);
  } else if (CheckPending(EXTI_LINE_8)) {
    ExtIrq8Callback();
    ClearPending(EXTI_LINE_8);
  } else if (CheckPending(EXTI_LINE_9)) {
    ExtIrq9Callback();
    ClearPending(EXTI_LINE_9);
  } else if (CheckPending(EXTI_LINE_10)) {
    ExtIrq10Callback();
    ClearPending(EXTI_LINE_10);
  } else if (CheckPending(EXTI_LINE_11)) {
    ExtIrq11Callback();
    ClearPending(EXTI_LINE_11);
  } else if (CheckPending(EXTI_LINE_12)) {
    ExtIrq12Callback();
    ClearPending(EXTI_LINE_12);
  } else if (CheckPending(EXTI_LINE_13)) {
    ExtIrq13Callback();
    ClearPending(EXTI_LINE_13);
  } else if (CheckPending(EXTI_LINE_14)) {
    ExtIrq14Callback();
    ClearPending(EXTI_LINE_14);
  } else if (CheckPending(EXTI_LINE_15)) {
    ExtIrq15Callback();
    ClearPending(EXTI_LINE_15);
  }
}

#endif

void ExternalInterrupt::Config(uint16_t pin, void (*function)(),
                               uint32_t priority) {
  switch (pin) {
#if defined(STM32F7) | defined(STM32F4) | defined(STM32F1) | \
    defined(STM32F2) | defined(STM32F3) | defined(STM32G4) | \
    defined(STM32H7) | defined(STM32L1) | defined(STM32L4)

    case 0:
      irqn_ = EXTI0_IRQn;
      ExtIrq0Callback = function;
      break;
    case 1:
      irqn_ = EXTI1_IRQn;
      ExtIrq1Callback = function;
      break;
    case 2:
      irqn_ = EXTI2_IRQn;
      ExtIrq2Callback = function;
      break;
    case 3:
      irqn_ = EXTI3_IRQn;
      ExtIrq3Callback = function;
      break;
    case 4:
      irqn_ = EXTI4_IRQn;
      ExtIrq4Callback = function;
      break;
    case 5:
      irqn_ = EXTI9_5_IRQn;
      ExtIrq5Callback = function;
      break;
    case 6:
      irqn_ = EXTI9_5_IRQn;
      ExtIrq6Callback = function;
      break;

    case 7:
      irqn_ = EXTI9_5_IRQn;
      ExtIrq7Callback = function;
      break;
    case 8:
      irqn_ = EXTI9_5_IRQn;
      ExtIrq8Callback = function;
      break;
    case 9:
      irqn_ = EXTI9_5_IRQn;
      ExtIrq9Callback = function;
      break;
    case 10:
      irqn_ = EXTI15_10_IRQn;
      ExtIrq10Callback = function;
      break;
    case 11:
      irqn_ = EXTI15_10_IRQn;
      ExtIrq11Callback = function;
      break;
    case 12:
      irqn_ = EXTI15_10_IRQn;
      ExtIrq12Callback = function;
      break;
    case 13:
      irqn_ = EXTI15_10_IRQn;
      ExtIrq13Callback = function;
      break;
    case 14:
      irqn_ = EXTI15_10_IRQn;
      ExtIrq14Callback = function;
      break;
    case 15:
      irqn_ = EXTI15_10_IRQn;
      ExtIrq15Callback = function;
      break;

#endif

#if defined(STM32L0) | defined(STM32G0)

    case 0:
      irqn_ = EXTI0_1IRQn;
      ExtIrq0Callback = function;
      break;
    case 1:
      irqn_ = EXTI0_1IRQn;
      ExtIrq1Callback = function;
      break;
    case 2:
      irqn_ = EXTI2_3IRQn;
      ExtIrq2Callback = function;
      break;
    case 3:
      irqn_ = EXTI2_3IRQn;
      ExtIrq3Callback = function;
      break;
    case 4:
      irqn_ = EXTI4_15IRQn;
      ExtIrq4Callback = function;
      break;
    case 5:
      irqn_ = EXTI4_15IRQn;
      ExtIrq5Callback = function;
      break;
    case 6:
      irqn_ = EXTI4_15IRQn;
      ExtIrq6Callback = function;
      break;
    case 7:
      irqn_ = EXTI4_15IRQn;
      ExtIrq7Callback = function;
      break;
    case 8:
      irqn_ = EXTI4_15IRQn;
      ExtIrq8Callback = function;
      break;
    case 9:
      irqn_ = EXTI4_15IRQn;
      ExtIrq9Callback = function;
      break;
    case 10:
      irqn_ = EXTI4_15IRQn;
      ExtIrq10Callback = function;
      break;
    case 11:
      irqn_ = EXTI4_15IRQn;
      ExtIrq11Callback = function;
      break;
    case 12:
      irqn_ = EXTI4_15IRQn;
      ExtIrq12Callback = function;
      break;
    case 13:
      irqn_ = EXTI4_15IRQn;
      ExtIrq13Callback = function;
      break;
    case 14:
      irqn_ = EXTI4_15IRQn;
      ExtIrq14Callback = function;
      break;
    case 15:
      irqn_ = EXTI4_15IRQn;
      ExtIrq15Callback = function;
      break;

#endif
  }

  HAL_NVIC_SetPriority(irqn_, priority, priority);
  HAL_NVIC_EnableIRQ(irqn_);
}

ExternalInterrupt::ExternalInterrupt(PinName pin, void (*function)(),
                                     PullType pull, InterruptMode mode,
                                     uint32_t priority) {
  assert_param(IS_EXTI_MODE(mode));
  assert_param(IS_EXTI_GPIO_PORT(pin.port));
  assert_param(IS_EXTI_GPIO_PIN(pin.pin));

  pin_ = pin;
  GPIO_InitTypeDef pin_structure = {};
  pin_structure.Pin = pin.pin;
  pin_structure.Mode = mode;
  pin_structure.Pull = pull;

  HAL_GPIO_Init(pin.port, &pin_structure);
  Config(pin.pin, function, priority);
}

ExternalInterrupt::~ExternalInterrupt() {
  HAL_GPIO_DeInit(pin_.port, pin_.pin);
}

int ExternalInterrupt::Read() { return HAL_GPIO_ReadPin(pin_.port, pin_.pin); }

void ExternalInterrupt::DisableIRQn() { HAL_NVIC_DisableIRQ(irqn_); }

void ExternalInterrupt::EnableIRQn() { HAL_NVIC_EnableIRQ(irqn_); }

bool CheckPending(uint32_t line) {
  assert_param(IS_EXTI_LINE(line));
  uint32_t linepos = (line & EXTI_PIN_MASK);
  uint32_t maskline = (1uL << linepos);
  return ((EXTI->PR & maskline) >> linepos);
}

void ClearPending(uint32_t line) {
  assert_param(IS_EXTI_LINE(line));
  uint32_t maskline = (1uL << (line & EXTI_PIN_MASK));
  EXTI->PR = maskline;
}