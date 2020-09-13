/**
 * @file bsp_led.c
 * @author hjr (yanyuzuixin@163.com)
 * @brief 开发板Led接口
 * @version 0.1
 * @date 2020-09-13
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */
  
#include "bsp_led.h"
#include "bsp_led_cfg.h"

#include "error_check.h"


int32_t BSP_LedOn(uint16_t ledId)
{
    CHECK_FALSE_RET(ledId < BSP_MAX_LED_NUM, -ERR_CODE_INVALID_PARAM);
    int32_t ret = PORT_GpioSetLevel(g_bspLedGpioId[ledId], PORT_GPIO_LEVEL_LOW);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);
    return ERR_CODE_NONE;
}

int32_t BSP_LedOff(uint16_t ledId)
{
    CHECK_FALSE_RET(ledId <BSP_MAX_LED_NUM, -ERR_CODE_INVALID_PARAM);
    int32_t ret = PORT_GpioSetLevel(g_bspLedGpioId[ledId], PORT_GPIO_LEVEL_HIGH);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);
    return ERR_CODE_NONE;
}

int32_t BSP_LedIint(void)
{
    for (uint32_t i = 0; i < BSP_MAX_LED_NUM; i++) {
        int32_t ret = PORT_GpioInit(g_bspLedGpioId[i], PORT_GPIO_DIR_OUTPUT);
        CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);
        BSP_LedOff(i);
    }
    return ERR_CODE_NONE;
}
