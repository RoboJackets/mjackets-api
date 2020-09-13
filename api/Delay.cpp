#include "Delay.hpp"

uint32_t CurrentTick() {
    volatile uint32_t cur_tick = DWT->CYCCNT;
    return cur_tick;
}

void DelayTick(uint32_t ticks) {
    volatile uint32_t start_tick = DWT->CYCCNT;
    do {} while (DWT->CYCCNT - start_tick < ticks);
}

void DelayUs(uint32_t us) // microseconds
{
    volatile uint32_t delay_ticks = us * (SystemCoreClock/1000000L);
    volatile uint32_t start_tick = DWT->CYCCNT;

    do {} while (DWT->CYCCNT - start_tick < delay_ticks);
}

void DelayMs(uint32_t ms) // milliseconds
{
    volatile uint32_t delay_ticks = ms * (SystemCoreClock/1000L);
    volatile uint32_t start_tick = DWT->CYCCNT;

    do {} while (DWT->CYCCNT - start_tick < delay_ticks);
}
