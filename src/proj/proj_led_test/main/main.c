

#include "module_led.h"

void Delay(volatile uint32_t nCount);

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
    MOD_LedInit();
    while (1) {
        MOD_LedOn(MOD_LED_TPYE_RED);
        Delay(0xFFFFFF);
        MOD_LedOff(MOD_LED_TPYE_RED);

        // MOD_LedOn(MOD_LED_TPYE_GREEN);
        // Delay(0xFFFFFF);
        // MOD_LedOff(MOD_LED_TPYE_GREEN);

        // MOD_LedOn(MOD_LED_TPYE_BLUE);
        // Delay(0xFFFFFF);
        // MOD_LedOff(MOD_LED_TPYE_BLUE);
        Delay(0xFFFFFF);
    }
}

void Delay(volatile uint32_t nCount)     //简单的延时函数
{
    for(; nCount != 0; nCount--);
}


