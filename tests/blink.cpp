#include "mJackets.hpp"

/**
 * Blink LEDs back and forth
 */
int main(void)
{
    /* Standard Hal Initialization */
    MPU_Config();
    CPU_CACHE_Enable();
    HAL_Init();

    /* Clock Setup */
    ClockInitStruct init;
    init.ClockSource = CLOCK_SOURCE_HSE;
    init.SystemFrequency = SYS_FREQ_100MHZ;
    init.HSEMultiplier = 432;
    init.HSEDivider1 =  25;
    init.HSEDivider2 = RCC_PLLP_DIV2;
    init.HSE48CKDivider = 2;
    init.AHBClkDivider = RCC_SYSCLK_DIV1;
    init.APB1ClkDivider = RCC_HCLK_DIV4;
    init.APB2ClkDivider = RCC_HCLK_DIV2;
    init.FlashLatency = 7;
    SystemClock_Config(init);


    /* GPIO Configuration */
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOI_CLK_ENABLE();



  DigitalOut leds[] = {(LED1), (LED2), (LED3), (LED4)};

  int id = 0;
  bool forward = true;

  while (true) {
    leds[id].toggle();
    DWT_Delay(100000); // 1/10th second
    leds[id].toggle();

    if (id == 3) {
        forward = false;
    } else if (id == 0) {
        forward = true;
    }
    id += forward ? 1 : -1;
  }
}
