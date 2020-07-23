#pragma once

#include <stdint.h>

typedef struct PinName {
    GPIO_TypeDef* port;
    uint16_t pin;
} PinName;

typedef enum PullType {
    PullNone = GPIO_NOPULL,
    PullUp = GPIO_PULLUP,
    PullDown = GPIO_PULLDOWN
} PullType;

typedef enum {
    PushPull = GPIO_MODE_OUTPUT_PP,
    OpenDrain = GPIO_MODE_OUTPUT_OD
} PinMode;

typedef enum {
    Low = GPIO_SPEED_FREQ_LOW,
    Medium = GPIO_SPEED_FREQ_MEDIUM,
    High = GPIO_SPEED_FREQ_HIGH,
    VeryHigh = GPIO_SPEED_FREQ_VERY_HIGH
} PinSpeed;


/* Sample Pin Definition - Replace with the pin definition for your board!! */

const PinName p3  = { GPIOA, GPIO_PIN_8  };
const PinName p4  = { GPIOB, GPIO_PIN_15 };
const PinName p5  = { GPIOB, GPIO_PIN_14 };
const PinName p6  = { GPIOA, GPIO_PIN_12 };
const PinName p7  = { GPIOA, GPIO_PIN_11 };
const PinName p8  = { GPIOC, GPIO_PIN_6  };


const PinName LED1 = { GPIOE, GPIO_PIN_4 };
const PinName LED2 = { GPIOE, GPIO_PIN_3 };
const PinName LED3 = { GPIOE, GPIO_PIN_6 };
const PinName LED4 = { GPIOE, GPIO_PIN_5 };