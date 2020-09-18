#include "mJackets.hpp"
#include "InterruptIn.hpp"

static DigitalOut leds[] = {(LED1), (LED2), (LED3), (LED4)};
static DigitalOut setpin(p32);
/** interruptin and digitalout test
 *
 * Blinks LEDs back and forth, changing 4th LED as interrupt flag for all
 * interruptible pins
 */
void blink()
{
    leds[4].toggle();
}

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

    interruptin_init_ex(p31, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p35, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p16, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p30, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p18, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p20, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p11, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p34, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p13, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p36, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p5, &blink, PullType::PullDown, INTERRUPT_RISING);
    interruptin_init_ex(p4, &blink, PullType::PullDown, INTERRUPT_RISING);

    int id = 0;
    int forward = 1;

    while (1)
    {
        leds[id].toggle();
        setpin.toggle(); // trigger interrupt
        DWT_Delay(100000); // 1/10th second
        leds[id].toggle();
        setpin.toggle();

        if (id == 2)
        {
            forward = -1;
        }
        else if (id == 0)
        {
            forward = 1;
        }
        id += forward;
    }
}
