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

// LIGHT_INT PA0
// SPI_SCK PA1
// AUX_CS PA2
// GAS_CS PA3
// MCU_DATA_CS PA4
// LCD_CS PA5
// SPI_MISO PA6
// SPI_MOSI PA7
// TEMP_ALERT PA8
// MCU_DEBUG_TX PA9
// MCU_DEBUG_RX PA10
// CAN_SPI_DRDY PA11
// SWD_SWDIO PA13
// SWD_SWCLK PA14
// SWD_JTDI PA15
// LCD_NBUSY PE4
// LCD_DAT_CMD PB0
// LCD_NRST PB1
// USER_LED_4 PB2
// SWD_SWO PB3
// SWD_NRST PB4
// USER_LED_1 PB5
// USER_LED_2 PB6
// USER_LED_3 PB7
// I2C_SCL PB8
// I2C_SDA PB9

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

