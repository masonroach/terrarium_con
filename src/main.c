/*!
 * \file
 * \brief
 * \author
 * \date
 */
#include "stm32wb.hpp"
#include "gpio.hpp"
#include "rcc.hpp"
#include "uart.hpp"
#include "stm32wb_nucleo_bsp.h"

int main(void) {

	// Enable GPIO clocks
	RCC_GPIOB_ENABLE();
	RCC_GPIOC_ENABLE();
	RCC_GPIOD_ENABLE();

	// Initialize LED pins
	GPIO_Pin_t LED_Blue = GPIO_Pin_t(LED1_PORT, LED1_PIN, MODE_OUTPUT, OUTTYPE_PUSHPULL, SPEED_LOW, PUPD_NOPULL);
	GPIO_Pin_t LED_Green = GPIO_Pin_t(LED2_PORT, LED2_PIN, MODE_OUTPUT, OUTTYPE_PUSHPULL, SPEED_LOW, PUPD_NOPULL);
	GPIO_Pin_t LED_Red = GPIO_Pin_t(LED3_PORT, LED3_PIN, MODE_INPUT, OUTTYPE_PUSHPULL, SPEED_LOW, PUPD_NOPULL);
	LED_Blue.set_pin(true);

	// Initialize UART
	GPIO_Pin_t(DEBUG_UART_RX_PORT, DEBUG_UART_RX_PIN, MODE_AF7_USART1, OUTTYPE_PUSHPULL, SPEED_VHIGH, PUPD_NOPULL);
	GPIO_Pin_t(DEBUG_UART_TX_PORT, DEBUG_UART_TX_PIN, MODE_AF7_USART1, OUTTYPE_PUSHPULL, SPEED_VHIGH, PUPD_NOPULL);
	USART_Handle_t UART_Debug = USART_Handle_t(DEBUG_UART_PERIPH);
	UART_Debug.port_init(
		9600,
		USART_COMM_MODE_TX_RX,
		USART_WORD_LEN_8,
		USART_STOP_BITS_1,
		USART_PARITY_NONE,
		USART_FLOW_CONTROL_NONE,
		1,
		USART_OVERSAMP_16
	);
	
	uint8_t temp_debug = 'T';
	UART_Debug.transmit_blocking(&temp_debug, sizeof(temp_debug));

	// Boot CPU2

	LED_Green.set_pin(true);

	while (1);

	return 0;

}

int cpu2_main(
	void
)
{

}

