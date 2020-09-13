/**
 * @file module_led.c
 * @author hjr (yanyuzuixin@163.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-13
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#include "module_led.h"

#include "error_check.h"

#include "bsp_led.h"

int32_t MOD_LedInit(void)
{
    return BSP_LedIint();
}

int32_t MOD_LedOn(ModuleLedType type)
{
    CHECK_FALSE_RET(type < MOD_LED_TPYE_MAX, ERR_CODE_INVALID_PARAM);
    return BSP_LedOn(type);
}

int32_t MOD_LedOff(ModuleLedType type)
{
    CHECK_FALSE_RET(type < MOD_LED_TPYE_MAX, ERR_CODE_INVALID_PARAM);
    return BSP_LedOff(type);
}