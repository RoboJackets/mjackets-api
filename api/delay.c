#include "delay.h"


//TODO FIX INCLUDES
#if defined STM32F0
#include "stm32f0xx_hal.h"
#endif
#if defined STM32F1
#include "stm32f1xx_hal.h"
#endif
#if defined STM32F2
#include "stm32f2xx_hal.h"
#endif
#if defined STM32F3
#include "stm32f3xx_hal.h"
#endif
#if defined STM32F4
#include "stm32f4xx_hal.h"
#endif
#if defined STM32F7
#include "stm32f7xx_hal.h"
#endif


uint32_t DWT_GetTick() {
    volatile uint32_t curTick = DWT->CYCCNT;
    return curTick;
}

uint64_t DWT_SysTick_To_us() {
    volatile uint64_t ratio = SystemCoreClock/1000000L;
    return ratio;
}

void DWT_Delay_Sys(uint32_t ticks) {
    volatile uint32_t startTick = DWT->CYCCNT;
    do {} while (DWT->CYCCNT - startTick < ticks);
}

void DWT_Delay(uint32_t us) // microseconds
{
    volatile uint32_t delayTicks = us * (SystemCoreClock/1000000L);
    volatile uint32_t startTick = DWT->CYCCNT;

    do {} while (DWT->CYCCNT - startTick < delayTicks);
}
