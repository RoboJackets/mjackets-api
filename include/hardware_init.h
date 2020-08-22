#ifndef _HARDWARE_INIT_H
#define _HARWARE_INIT_H

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct
{
    uint32_t ClockSource;
    uint32_t SystemFrequency;
    uint32_t HSEMultiplier;
    uint32_t HSEDivider1;
    uint32_t HSEDivider2;
    uint32_t HSE48CKDivider;
    uint32_t AHBClkDivider;
    uint32_t APB1ClkDivider;
    uint32_t APB2ClkDivider;
    uint32_t FlashLatency;
}ClockInitStruct;

/* Clock Sources */
#define CLOCK_SOURCE_HSE 0x1
#define CLOCK_SOURCE_LSE 0x2
#define CLOCK_SOURCE_HSI 0x3
#define CLOCK_SOURCE_LSI 0x4

/* Convenient System Frequency Values */
#define SYS_FREQ_100MHZ 0x5F5E100

void SystemClock_Config(ClockInitStruct);
void MPU_Config(void);
void CPU_CACHE_Enable(void);
void DWT_Config(void);
void assert_failed(uint8_t* file, uint32_t line);
void HAL_MspInit(void);

#ifdef __cplusplus
}
#endif

#endif // _HARWARE_INIT_H