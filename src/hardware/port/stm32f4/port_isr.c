/**
 * @file port_isr.c
 * @author hjr (yanyuzuixin@163.com)
 * @brief 
 * @version 0.1
 * @date 2020-09-20
 * 
 * @copyright Copyright (c) 2020 yanyuzuixin@163.com All Rights Reserved.
 * 
 */

#include "port_isr.h"

#include "common_def.h"
#include "error_check.h"

typedef void (*IsrHandler)(void);

IsrHandler g_isrHandlerList[PORT_ISR_ID_NUM] = {NULL};

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_NMI] != NULL) {
        (*g_isrHandlerList[PORT_ISR_NMI])();
    }
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_HARDFAULT] != NULL) {
        (*g_isrHandlerList[PORT_ISR_HARDFAULT])();
    }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_MEMMANAGE] != NULL) {
        (*g_isrHandlerList[PORT_ISR_MEMMANAGE])();
    }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_BUSFAULT] != NULL) {
        (*g_isrHandlerList[PORT_ISR_BUSFAULT])();
    }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_USAGEFAULT] != NULL) {
        (*g_isrHandlerList[PORT_ISR_USAGEFAULT])();
    }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_SVC] != NULL) {
        (*g_isrHandlerList[PORT_ISR_SVC])();
    }
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_DEBUGMON] != NULL) {
        (*g_isrHandlerList[PORT_ISR_DEBUGMON])();
    }
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_PENDSV] != NULL) {
        (*g_isrHandlerList[PORT_ISR_PENDSV])();
    }
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    if (g_isrHandlerList[PORT_ISR_SYSTICK] != NULL) {
        (*g_isrHandlerList[PORT_ISR_SYSTICK])();
    }
}

void USART1_IRQHandler(void)
{
    if (g_isrHandlerList[PORT_ISR_UART1] != NULL) {
        (*g_isrHandlerList[PORT_ISR_UART1])();
    }
}
void USART2_IRQHandler(void)
{
    if (g_isrHandlerList[PORT_ISR_UART2] != NULL) {
        (*g_isrHandlerList[PORT_ISR_UART2])();
    }
}
void USART3_IRQHandler(void)
{
    if (g_isrHandlerList[PORT_ISR_UART3] != NULL) {
        g_isrHandlerList[PORT_ISR_UART3]();
    }
}
void UART4_IRQHandler(void)
{
    if (g_isrHandlerList[PORT_ISR_UART4] != NULL) {
        (*g_isrHandlerList[PORT_ISR_UART4])();
    }
}
void UART5_IRQHandler(void)
{
    if (g_isrHandlerList[PORT_ISR_UART5] != NULL) {
        (*g_isrHandlerList[PORT_ISR_UART5])();
    }
}
void USART6_IRQHandler(void)
{
    if (g_isrHandlerList[PORT_ISR_UART6] != NULL) {
        (*g_isrHandlerList[PORT_ISR_UART6])();
    }
}

/**
 * @brief 注册中断服务函数
 * 
 * @param isrId 中断ID，可取值参考 PortIsrId
 * @param func 中断服务函数
 * @return int32_t 
 */
int32_t PORT_IsrRegistHandler(uint16_t isrId, void (*func)(void))
{
    CHECK_FALSE_RET(isrId < PORT_ISR_ID_NUM, -ERR_CODE_INVALID_PARAM);
    CHECK_FALSE_RET(func != NULL, -ERR_CODE_INVALID_PARAM);
    g_isrHandlerList[isrId] = (IsrHandler)func;
    return ERR_CODE_NONE;
}
