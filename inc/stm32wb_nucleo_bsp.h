/*!
 * \file stm32wb_nucleo_bsp.hpp
 * \brief Board specific definitions for the STM32WB NUCLEO
 * \author Mason Roach
 * \date May 16, 2021
 */

#ifndef __STM32WB_NUCLEO_BSP_H
#define __STM32WB_NUCLEO_BSP_H
// =============================================================================
// Defines
// =============================================================================
#include "stm32wb.hpp"
#include "gpio.hpp"

#define LED1_PIN (5)
#define LED1_PORT (GPIOB)

#define LED2_PIN (0)
#define LED2_PORT (GPIOB)

#define LED3_PIN (1)
#define LED3_PORT (GPIOB)

#define SW1_PIN (0)
#define SW1_PORT (GPIOB)

#define SW2_PIN (0)
#define SW2_PORT (GPIOD)

#define SW3_PIN (1)
#define SW3_PORT (GPIOD)

#define USB_N_PIN (11)
#define USB_N_PORT (GPIOA)
#define USB_P_PIN (12)
#define USB_P_PORT (GPIOA)

#define DEBUG_UART_PERIPH (USART1)
#define DEBUG_UART_RX_PIN (3)
#define DEBUG_UART_RX_PORT (GPIOA)
#define DEBUG_UART_TX_PIN (2)
#define DEBUG_UART_TX_PORT (GPIOA)

#endif

