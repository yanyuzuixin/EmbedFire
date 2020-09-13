/**
 * @file port_gpio.c
 * @author hjr (yanyuzuixin@163.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-12
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#include "port_gpio.h"
#include "port_gpio_cfg.h"

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#include "error_check.h"
#include "common_def.h"

static int32_t GpioGetTypeDef(uint16_t pinId, GPIO_TypeDef** gpioType)
{
    CHECK_FALSE_RET(pinId < MAX_GPIO_NUM, -ERR_CODE_INVALID_PARAM);
    GPIO_TypeDef* gpioTypeList[11] = {
        GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF, GPIOG, GPIOH, GPIOI, GPIOJ, GPIOK
    };

    *gpioType = gpioTypeList[pinId / 16];
    return ERR_CODE_NONE;
}

static int32_t GpioGetPinMask(uint16_t pinId, uint16_t* pinMask)
{
    CHECK_FALSE_RET(pinId < MAX_GPIO_NUM, -ERR_CODE_INVALID_PARAM);
    *pinMask = (uint16_t)1 << (pinId % 16);
    return ERR_CODE_NONE;
}

static int32_t GpioEnableClock(uint16_t pinId)
{
    CHECK_FALSE_RET(pinId < MAX_GPIO_NUM, -ERR_CODE_INVALID_PARAM);
    uint32_t clockMask = (uint32_t)1 << (pinId / 16);
    RCC_AHB1PeriphClockCmd(clockMask, ENABLE);
    return ERR_CODE_NONE;
}

int32_t PORT_GpioInit(uint16_t pinId, PortGpioDir dir)
{
    CHECK_FALSE_RET(pinId >= 0, -ERR_CODE_INVALID_PARAM);
    CHECK_FALSE_RET(pinId < MAX_GPIO_NUM, -ERR_CODE_INVALID_PARAM);
    CHECK_FALSE_RET(dir == PORT_GPIO_DIR_INPUT || dir == PORT_GPIO_DIR_OUTPUT, -ERR_CODE_INVALID_PARAM);

    int32_t ret;
    GPIO_TypeDef* gpioType = NULL;
    uint16_t pinMask;
    GPIO_InitTypeDef gpioInitStru;

    ret = GpioGetTypeDef(pinId, &gpioType);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);
    ret = GpioGetPinMask(pinId, &pinMask);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);

    (void)GpioEnableClock(pinId);    
    
    gpioInitStru.GPIO_Pin = pinMask;
    gpioInitStru.GPIO_Mode = (GPIOMode_TypeDef)dir;
    gpioInitStru.GPIO_Speed = GPIO_Speed_50MHz;
    gpioInitStru.GPIO_OType = GPIO_OType_PP;
    gpioInitStru.GPIO_PuPd = GPIO_PuPd_NOPULL;

    GPIO_Init(gpioType, &gpioInitStru);
    return ERR_CODE_NONE;
}

int32_t PORT_GpioGetLevel(uint16_t pinId)
{
    CHECK_FALSE_RET(pinId >= 0, -ERR_CODE_INVALID_PARAM);
    CHECK_FALSE_RET(pinId < MAX_GPIO_NUM, -ERR_CODE_INVALID_PARAM);
    int32_t ret;
    GPIO_TypeDef* gpioType = NULL;
    uint16_t pinMask;

    ret = GpioGetTypeDef(pinId, &gpioType);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);
    ret = GpioGetPinMask(pinId, &pinMask);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);
    
    uint32_t pinMode = (gpioType->MODER >> (pinMask * 2)) & GPIO_MODER_MODER0;
    if (pinMode == PORT_GPIO_DIR_INPUT) {
        return GPIO_ReadInputDataBit(gpioType, pinMask);
    } else if (pinMode == PORT_GPIO_DIR_OUTPUT){
        return GPIO_ReadOutputDataBit(gpioType, pinMask);
    } else {
        return -ERR_CODE_INVALID_RESULT;
    }
}

int32_t PORT_GpioSetLevel(uint16_t pinId, uint8_t level)
{
    CHECK_FALSE_RET(pinId >= 0, -ERR_CODE_INVALID_PARAM);
    CHECK_FALSE_RET(pinId < MAX_GPIO_NUM, -ERR_CODE_INVALID_PARAM);
    int32_t ret;
    GPIO_TypeDef* gpioType = NULL;
    uint16_t pinMask;

    ret = GpioGetTypeDef(pinId, &gpioType);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);
    ret = GpioGetPinMask(pinId, &pinMask);
    CHECK_FALSE_RET(ret == ERR_CODE_NONE, ret);

    if (level == PORT_GPIO_LEVEL_LOW) {
        GPIO_ResetBits(gpioType, pinMask);
    } else {
        GPIO_SetBits(gpioType, pinMask);
    }
    return ERR_CODE_NONE;
}