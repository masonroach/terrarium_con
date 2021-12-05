/*!
 * \file
 * \brief
 * \author
 * \date
 */
#include "TCON_HW_CLK.h"
#include "TCON_HW_LED.h"

#include "TCON_APP_LED.h"
#include "TCON_APP_ThreadControl.h"

#include "FreeRTOS.h"
#include "task.h"

int main(void) {

    HAL_Init();

    HW_CLK_Init();
    HW_LED_Init();

    THD_LED_Init();

    HW_LED_Set(4, 1);

    SYS_ThreadControl_StartScheduler();

    HW_LED_Set(3, 1);
    while (1);

}

