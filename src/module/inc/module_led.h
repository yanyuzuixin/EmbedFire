/**
 * @file module_led.h
 * @author hjr (yanyuzuixin@163.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-13
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#ifndef MODULE_LED_H
#define MODULE_LED_H

#include <stdint.h>

typedef enum {
    MOD_LED_TPYE_RED = 0,
    MOD_LED_TPYE_GREEN,
    MOD_LED_TPYE_BLUE,
    MOD_LED_TPYE_MAX
} ModuleLedType;

int32_t MOD_LedInit(void);
int32_t MOD_LedOn(ModuleLedType type);
int32_t MOD_LedOff(ModuleLedType type);

#endif