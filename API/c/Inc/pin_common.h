typedef struct pin_name {
    GPIO_TypeDef* port;
    uint16_t pin;
} pin_name;

typedef enum {
              PULL_NONE = GPIO_NOPULL,
              PULL_UP = GPIO_PULLUP,
              PULL_DOWN = GPIO_PULLDOWN
} pull_type;

typedef enum {
              PUSH_PULL = GPIO_MODE_OUTPUT_PP,
              OPEN_DRAIN = GPIO_MODE_OUTPUT_OD
} pin_mode;

typedef enum {
              LOW = GPIO_SPEED_FREQ_LOW,
              MEDIUM = GPIO_SPEED_FREQ_MEDIUM,
              HIGH = GPIO_SPEED_FREQ_HIGH,
              VERY_HIGH = GPIO_SPEED_FREQ_VERY_HIGH
} pin_speed;
