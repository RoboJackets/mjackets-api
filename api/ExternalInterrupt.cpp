#include "ExternalInterrupt.hpp"

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

void EXTI0_IRQHandler(void) { ExtIrq0Callback(); }

void EXTI1_IRQHandler(void) { ExtIrq1Callback(); }

void EXTI2_IRQHandler(void) { ExtIrq2Callback(); }

void EXTI3_IRQHandler(void) { ExtIrq3Callback(); }

void EXTI4_IRQHandler(void) { ExtIrq4Callback(); }

void EXTI9_5_IRQHandler(void) {
  if (Pending(EXTI_LINE_5))  // External Interrupt 5
  {
    ExtIrq5Callback();
  } else if (Pending(EXTI_LINE_6))  // External Interrupt 6
  {
    ExtIrq6Callback();
  } else if (Pending(EXTI_LINE_7))  // External Interrupt 7
  {
    ExtIrq7Callback();
  } else if (Pending(EXTI_LINE_8))  // External Interrupt 8
  {
    ExtIrq8Callback();
  } else if (Pending(EXTI_LINE_9))  // External Interrupt 9
  {
    ExtIrq9Callback();
  }
}

void EXTI15_10IRQHandler(void) {
  if (Pending(EXTI_LINE_10))  // External Interrupt 10
  {
    ExtIrq10Callback();
  } else if (Pending(EXTI_LINE_11))  // External Interrupt 11
  {
    ExtIrq11Callback();
  } else if (Pending(EXTI_LINE_12))  // External Interrupt 12
  {
    ExtIrq12Callback();
  } else if (Pending(EXTI_LINE_13))  // External Interrupt 13
  {
    ExtIrq13Callback();
  } else if (Pending(EXTI_LINE_14))  // External Interrupt 14
  {
    ExtIrq14Callback();
  } else if (Pending(EXTI_LINE_15))  // External Interrupt 15
  {
    ExtIrq15Callback();
  }
  // Clear interrupt
}

#endif

#if defined(STM32L0) | defined(STM32G0)

void EXTI0_1IRQHandler(void) {
  if (Pending(EXTI_LINE_0))  // External Interrupt 0
  {
    ExtIrq0Callback();
  } else if (Pending(EXTI_LINE_0))  // External Interrupt 1
  {
    ExtIrq1Callback();
  }
}

void EXTI2_3IRQHandler(void) {
  if (Pending(EXTI_LINE_2))  // External Interrupt 2
  {
    ExtIrq2Callback();
  } else if (Pending(EXTI_LINE_3))  // External Interrupt 3
  {
    ExtIrq3Callback();
  }
}

void EXTI4_15IRQHandler(void) {
  if (Pending(EXTI_LINE_4))  // External Interrupt 4
  {
    ExtIrq4Callback();
  } else if (Pending(EXTI_LINE_5))  // External Interrupt 5
  {
    ExtIrq5Callback();
  } else if (Pending(EXTI_LINE_6))  // External Interrupt 6
  {
    ExtIrq6Callback();
  } else if (Pending(EXTI_LINE_7))  // External Interrupt 7
  {
    ExtIrq7Callback();
  } else if (Pending(EXTI_LINE_8))  // External Interrupt 8
  {
    ExtIrq8Callback();
  } else if (Pending(EXTI_LINE_9))  // External Interrupt 9
  {
    ExtIrq9Callback();
  } else if (Pending(EXTI_LINE_10))  // External Interrupt 10
  {
    ExtIrq10Callback();
  } else if (Pending(EXTI_LINE_11))  // External Interrupt 11
  {
    ExtIrq11Callback();
  } else if (Pending(EXTI_LINE_12))  // External Interrupt 12
  {
    ExtIrq12Callback();
  } else if (Pending(EXTI_LINE_13))  // External Interrupt 13
  {
    ExtIrq13Callback();
  } else if (Pending(EXTI_LINE_14))  // External Interrupt 14
  {
    ExtIrq14Callback();
  } else if (Pending(EXTI_LINE_15))  // External Interrupt 15
  {
    ExtIrq15Callback();
  }
  // Clear interrupt
}

#endif

void ExternalInterrupt::Config(uint16_t pin, void (*function)(),
                               uint32_t priority) {
  IRQn_Type irqn;
  switch (pin) {
#if defined(STM32F7) | defined(STM32F4) | defined(STM32F1) | \
    defined(STM32F2) | defined(STM32F3) | defined(STM32G4) | \
    defined(STM32H7) | defined(STM32L1) | defined(STM32L4)

    case 0:
      irqn = EXTI0_IRQn;
      ExtIrq0Callback = function;
      break;
    case 1:
      irqn = EXTI1_IRQn;
      ExtIrq1Callback = function;
      break;
    case 2:
      irqn = EXTI2_IRQn;
      ExtIrq2Callback = function;
      break;
    case 3:
      irqn = EXTI3_IRQn;
      ExtIrq3Callback = function;
      break;
    case 4:
      irqn = EXTI4_IRQn;
      ExtIrq4Callback = function;
      break;
    case 5:
      irqn = EXTI9_5_IRQn;
      ExtIrq5Callback = function;
      break;
    case 6:
      irqn = EXTI9_5_IRQn;
      ExtIrq6Callback = function;
      break;

    case 7:
      irqn = EXTI9_5_IRQn;
      ExtIrq7Callback = function;
      break;
    case 8:
      irqn = EXTI9_5_IRQn;
      ExtIrq8Callback = function;
      break;
    case 9:
      irqn = EXTI9_5_IRQn;
      ExtIrq9Callback = function;
      break;
    case 10:
      irqn = EXTI15_10_IRQn;
      ExtIrq10Callback = function;
      break;
    case 11:
      irqn = EXTI15_10_IRQn;
      ExtIrq11Callback = function;
      break;
    case 12:
      irqn = EXTI15_10_IRQn;
      ExtIrq12Callback = function;
      break;
    case 13:
      irqn = EXTI15_10_IRQn;
      ExtIrq13Callback = function;
      break;
    case 14:
      irqn = EXTI15_10_IRQn;
      ExtIrq14Callback = function;
      break;
    case 15:
      irqn = EXTI15_10_IRQn;
      ExtIrq15Callback = function;
      break;

#endif

#if defined(STM32L0) | defined(STM32G0)

    case 0:
      irqn = EXTI0_1IRQn;
      ExtIrq0Callback = function;
      break;
    case 1:
      irqn = EXTI0_1IRQn;
      ExtIrq1Callback = function;
      break;
    case 2:
      irqn = EXTI2_3IRQn;
      ExtIrq2Callback = function;
      break;
    case 3:
      irqn = EXTI2_3IRQn;
      ExtIrq3Callback = function;
      break;
    case 4:
      irqn = EXTI4_15IRQn;
      ExtIrq4Callback = function;
      break;
    case 5:
      irqn = EXTI4_15IRQn;
      ExtIrq5Callback = function;
      break;
    case 6:
      irqn = EXTI4_15IRQn;
      ExtIrq6Callback = function;
      break;

    case 7:
      irqn = EXTI4_15IRQn;
      ExtIrq7Callback = function;
      break;
    case 8:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq8Callback = function;
      break;
    case 9:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq9Callback = function;
      break;
    case 10:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq10Callback = function;
      break;
    case 11:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq11Callback = function;
      break;
    case 12:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq12Callback = function;
      break;
    case 13:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq13Callback = function;
      break;
    case 14:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq14Callback = function;
      break;
    case 15:
      irqn = EXTI4_15IRQn;
      ;
      ExtIrq15Callback = function;
      break;

#endif
  }

  HAL_NVIC_SetPriority(irqn, priority, priority);
  HAL_NVIC_EnableIRQ(irqn);
}

ExternalInterrupt::ExternalInterrupt(PinName pin, void (*function)(),
                                     PullType pull, InterruptMode mode,
                                     uint32_t priority) {
  pin_ = pin;
  GPIO_InitTypeDef pin_structure = {};
  pin_structure.Pin = pin.pin;
  pin_structure.Mode = pull;
  pin_structure.Pull = mode;

  HAL_GPIO_Init(pin.port, &pin_structure);
  Config(pin.pin, function, priority);
}

ExternalInterrupt::~ExternalInterrupt() {
  HAL_GPIO_DeInit(pin_.port, pin_.pin);
}

int ExternalInterrupt::Read() { return HAL_GPIO_ReadPin(pin_.port, pin_.pin); }

bool Pending(uint32_t line) {
  uint32_t linepos = (line & EXTI_PIN_MASK);
  uint32_t maskline = (1uL << linepos);
  return ((EXTI->PR & maskline) >> linepos);
}