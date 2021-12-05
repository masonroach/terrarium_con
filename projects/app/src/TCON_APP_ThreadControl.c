/**
 * @brief
 */
#include "TCON_APP_ThreadControl.h"
#include "FreeRTOS.h"
#include "task.h"

/**
 * @brief
 */
Sys_Err_t SYS_ThreadControl_StartScheduler(void) {

    vTaskStartScheduler();

    return ERR_NONE;

}