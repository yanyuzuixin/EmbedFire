/**
 * @file port_gpio.h
 * @author hjr (yanyuzuixin@163.com)
 * @brief 统一封装GPIO接口
 * @version 0.1
 * @date 2020-09-10
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#ifndef PORT_GPIO_H
#define PORT_GPIO_H

#include <stdint.h>

typedef enum {
    PORT_GPIO0,
    PORT_GPIO1,
    PORT_GPIO2,
    PORT_GPIO3,
    PORT_GPIO4,
    PORT_GPIO5,
    PORT_GPIO6,
    PORT_GPIO7,
    PORT_GPIO8,
    PORT_GPIO9,
    PORT_GPIO10,
    PORT_GPIO11,
    PORT_GPIO12,
    PORT_GPIO13,
    PORT_GPIO14,
    PORT_GPIO15,
    PORT_GPIO16,
    PORT_GPIO17,
    PORT_GPIO18,
    PORT_GPIO19,
    PORT_GPIO20,
    PORT_GPIO21,
    PORT_GPIO22,
    PORT_GPIO23,
    PORT_GPIO24,
    PORT_GPIO25,
    PORT_GPIO26,
    PORT_GPIO27,
    PORT_GPIO28,
    PORT_GPIO29,
    PORT_GPIO30,
    PORT_GPIO31,
    PORT_GPIO32,
    PORT_GPIO33,
    PORT_GPIO34,
    PORT_GPIO35,
    PORT_GPIO36,
    PORT_GPIO37,
    PORT_GPIO38,
    PORT_GPIO39,
    PORT_GPIO40,
    PORT_GPIO41,
    PORT_GPIO42,
    PORT_GPIO43,
    PORT_GPIO44,
    PORT_GPIO45,
    PORT_GPIO46,
    PORT_GPIO47,
    PORT_GPIO48,
    PORT_GPIO49,
    PORT_GPIO50,
    PORT_GPIO51,
    PORT_GPIO52,
    PORT_GPIO53,
    PORT_GPIO54,
    PORT_GPIO55,
    PORT_GPIO56,
    PORT_GPIO57,
    PORT_GPIO58,
    PORT_GPIO59,
    PORT_GPIO60,
    PORT_GPIO61,
    PORT_GPIO62,
    PORT_GPIO63,
    PORT_GPIO64,
    PORT_GPIO65,
    PORT_GPIO66,
    PORT_GPIO67,
    PORT_GPIO68,
    PORT_GPIO69,
    PORT_GPIO70,
    PORT_GPIO71,
    PORT_GPIO72,
    PORT_GPIO73,
    PORT_GPIO74,
    PORT_GPIO75,
    PORT_GPIO76,
    PORT_GPIO77,
    PORT_GPIO78,
    PORT_GPIO79,
    PORT_GPIO80,
    PORT_GPIO81,
    PORT_GPIO82,
    PORT_GPIO83,
    PORT_GPIO84,
    PORT_GPIO85,
    PORT_GPIO86,
    PORT_GPIO87,
    PORT_GPIO88,
    PORT_GPIO89,
    PORT_GPIO90,
    PORT_GPIO91,
    PORT_GPIO92,
    PORT_GPIO93,
    PORT_GPIO94,
    PORT_GPIO95,
    PORT_GPIO96,
    PORT_GPIO97,
    PORT_GPIO98,
    PORT_GPIO99,
    PORT_GPIO100,
    PORT_GPIO101,
    PORT_GPIO102,
    PORT_GPIO103,
    PORT_GPIO104,
    PORT_GPIO105,
    PORT_GPIO106,
    PORT_GPIO107,
    PORT_GPIO108,
    PORT_GPIO109,
    PORT_GPIO110,
    PORT_GPIO111,
    PORT_GPIO112,
    PORT_GPIO113,
    PORT_GPIO114,
    PORT_GPIO115,
    PORT_GPIO116,
    PORT_GPIO117,
    PORT_GPIO118,
    PORT_GPIO119,
    PORT_GPIO120,
    PORT_GPIO121,
    PORT_GPIO122,
    PORT_GPIO123,
    PORT_GPIO124,
    PORT_GPIO125,
    PORT_GPIO126,
    PORT_GPIO127,
    PORT_GPIO128,
    PORT_GPIO129,
    PORT_GPIO130,
    PORT_GPIO131,
    PORT_GPIO132,
    PORT_GPIO133,
    PORT_GPIO134,
    PORT_GPIO135,
    PORT_GPIO136,
    PORT_GPIO137,
    PORT_GPIO138,
    PORT_GPIO139,
    PORT_GPIO140,
    PORT_GPIO141,
    PORT_GPIO142,
    PORT_GPIO143,
    PORT_GPIO144,
} PortGpioId;

typedef enum {
    PORT_GPIO_DIR_INPUT = 0,
    PORT_GPIO_DIR_OUTPUT
} PortGpioDir;

typedef enum {
    PORT_GPIO_LEVEL_LOW = 0,
    PORT_GPIO_LEVEL_HIGH
} PortGpioLevel;

int32_t PORT_GpioInit(uint16_t pinId, PortGpioDir dir);
int32_t PORT_GpioGetLevel(uint16_t pinId);
int32_t PORT_GpioSetLevel(uint16_t pinId, uint8_t level);

#endif