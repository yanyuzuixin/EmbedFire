/**
 * @file bsp_led_cfg.h
 * @author hjr (yanyuzuixin@163.com)
 * @brief BSP层led配置，主要配置用在LED点灯的管脚
 * @version 0.1
 * @date 2020-09-13
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#ifndef BSP_LED_CFG_H
#define BSP_LED_CFG_H

#include "port_gpio.h"

#define BSP_MAX_LED_NUM 3

const PortGpioId g_bspLedGpioId[BSP_MAX_LED_NUM] = {
    PORT_GPIO86,
    PORT_GPIO87,
    PORT_GPIO88
};

#endif