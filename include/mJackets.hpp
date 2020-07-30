#pragma once

#if defined STM32F0
    #include "stm32f0xx_hal_conf.h"
    #include "stm32f0xx.h"
#endif
#if defined STM32F1
    #include "stm32f1xx_hal_conf.h"
    #include "stm32f1xx.h"
#endif
#if defined STM32F2
    #include "stm32f2xx_hal_conf.h"
    #include "stm32f2xx.h"
#endif
#if defined STM32F3
    #include "stm32f3xx_hal_conf.h"
    #include "stm32f3xx.h"
#endif
#if defined STM32F4
    #include "stm32f4xx_hal_conf.h"
    #include "stm32f4xx.h"
#endif
#if defined STM32F7
    #include "stm32f7xx_hal_conf.h"
    #include "stm32f7xx.h"
#endif

#include "PinDefs.hpp"
#include "bsp.h"
#include "DigitalIn.hpp"
#include "DigitalOut.hpp"
#include "AnalogIn.hpp"


