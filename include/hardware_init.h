#ifndef _HARDWARE_INIT_H
#define _HARWARE_INIT_H

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @brief System clock initialization struct
 * 
 */
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

/**
 * @brief System clock configuration and initialization
 * 
 * @param clock_init 
 */
void SystemClock_Config(ClockInitStruct clock_init);

#ifdef __MPU_PRESENT
/**
  * @brief  Configure the MPU attributes as Write Through for Internal SRAM1/2.
  * @note   The Base Address is 0x20020000 since this memory interface is the AXI.
  *         The Configured Region Size is 512KB because the internal SRAM1/2 
  *         memory size is 384KB.
  * @param  None
  * @retval None
  */
void MPU_Config(void);
#endif

#if defined(__ICACHE_PRESENT) && defined (__DCACHE_PRESENT)
/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
void CPU_CACHE_Enable(void);
#endif

/**
 * @brief 
 * 
 */
void DWT_Config(void);

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line);
#endif 

/**
 * @brief MCU Support Package (MSP) Initialization
 * 
 */
void HAL_MspInit(void);

#ifdef __cplusplus
}
#endif

#endif // _HARWARE_INIT_H