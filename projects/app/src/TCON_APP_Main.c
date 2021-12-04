/*!
 * \file
 * \brief
 * \author
 * \date
 */
#include "TCON_HW_CLK.h"
#include "TCON_HW_LED.h"

int main(void) {

	HAL_Init();

	HW_CLK_Init();

	HW_LED_Init();
	HW_LED_Set(1, 1);
	HW_LED_Set(2, 1);
	HW_LED_Set(3, 1);
	HW_LED_Set(4, 1);

	while (1);

}

