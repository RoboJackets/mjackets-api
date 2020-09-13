#pragma once

#include  <unistd.h>
#include "mJackets.hpp"

/**
 * @brief Current tick in sysclock ticks
 * 
 * @return uint32_t 
 */
uint32_t CurrentTick();

/**
 * @brief Delay routine in microseconds.
 *
 * No need to check an overflow. Let it just tick :)
 *
 * @param us  Number of microseconds to delay for
 */
void DelayUs(uint32_t us);

/**
 * @brief Delay routine in milliseconds.
 *
 * No need to check an overflow. Let it just tick :)
 *
 * @param us  Number of milliseconds to delay for
 */
void DelayMs(uint32_t us);
