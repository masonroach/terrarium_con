/*!
 * \brief
 */
#ifndef TCON_HW_LED_H
#define TCON_HW_LED_H

#include "TCON_HW_BSP.h"
#include "TCON_SYS_Error.h"

Sys_Err_t HW_LED_Init(void);
Sys_Err_t HW_LED_Set(uint8_t led, uint8_t enable);

#endif
