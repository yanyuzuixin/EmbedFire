/**
 * @file port_isr.h
 * @author hjr (yanyuzuixin@163.com)
 * @brief 中断服务程序port层接口
 * @version 0.1
 * @date 2020-09-20
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#include <stdint.h>

typedef enum {
    PORT_ISR_NMI = 0,
    PORT_ISR_HARDFAULT,
    PORT_ISR_MEMMANAGE,
    PORT_ISR_BUSFAULT,
    PORT_ISR_USAGEFAULT,
    PORT_ISR_SVC,
    PORT_ISR_DEBUGMON,
    PORT_ISR_PENDSV,
    PORT_ISR_SYSTICK,
    PORT_ISR_WWDG,
    PORT_ISR_UART0,
    PORT_ISR_UART1,
    PORT_ISR_UART2,
    PORT_ISR_UART3,
    PORT_ISR_UART4,
    PORT_ISR_UART5,
    PORT_ISR_UART6,
    PORT_ISR_ID_NUM
} PortIsrId;

int32_t PORT_IsrRegistHandler(uint16_t isrId, void (*func)(void));