/**
 * @brief LED thread
 */
#include "TCON_APP_LED.h"
#include "TCON_HW_LED.h"
#include "FreeRTOS.h"
#include "task.h"

#include <stdbool.h>

//==============================================================================
// Globals
//==============================================================================
#define LED_TASK_STACK_SIZE (1024/sizeof(StackType_t))
StaticTask_t g_led_task_buffer;
TaskHandle_t eh_led_task = NULL;
StackType_t g_led_stack_buffer[LED_TASK_STACK_SIZE];
static void THD_LED_Task(void *params);

//==============================================================================
// Functions
//==============================================================================
/**
 * @brief Initializes the LED task.
 * 
 * @retval ERR_NONE Success
 */
Sys_Err_t THD_LED_Init(void) {

    eh_led_task = xTaskCreateStatic(THD_LED_Task, "LED_Task",
        LED_TASK_STACK_SIZE, NULL, 5, g_led_stack_buffer, &g_led_task_buffer);

    return ERR_NONE;

}

/**
 * @brief
 */
static void THD_LED_Task(void *params) {
    bool led_state = false;

    while (1) {

        HW_LED_Set(1, led_state);
        led_state = !led_state;
        vTaskDelay(1000);

    }

}