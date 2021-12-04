/*!
 * \brief
 */
#include "TCON_HW_LED.h"

/*!
 * \brief Initializes LED pins
 * 
 * \param None
 * 
 * \retval ERR_NONE no error, success
 */
Sys_Err_t HW_LED_Init(void) {
    GPIO_InitTypeDef gpio = {0};

    // Initialize clocks
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // Configure LED pins
    gpio.Mode = GPIO_MODE_OUTPUT_PP;
    gpio.Pull = GPIO_NOPULL;
    gpio.Speed = GPIO_SPEED_FREQ_LOW;
    gpio.Pin = USER_LED_1_PIN;
    HAL_GPIO_WritePin(USER_LED_1_PORT, USER_LED_1_PIN, 0);
    HAL_GPIO_Init(USER_LED_1_PORT, &gpio);
    gpio.Pin = USER_LED_2_PIN;
    HAL_GPIO_WritePin(USER_LED_2_PORT, USER_LED_2_PIN, 0);
    HAL_GPIO_Init(USER_LED_2_PORT, &gpio);
    gpio.Pin = USER_LED_3_PIN;
    HAL_GPIO_WritePin(USER_LED_3_PORT, USER_LED_3_PIN, 0);
    HAL_GPIO_Init(USER_LED_3_PORT, &gpio);
    gpio.Pin = USER_LED_4_PIN;
    HAL_GPIO_WritePin(USER_LED_4_PORT, USER_LED_4_PIN, 0);
    HAL_GPIO_Init(USER_LED_4_PORT, &gpio);

    return ERR_NONE;

}

/*!
 * \brief
 *
 * \param
 * 
 * \retval
 */
Sys_Err_t HW_LED_Set(uint8_t led, uint8_t enable) {
    uint16_t pin;
    GPIO_TypeDef *port;

    switch (led) {
        // LED 1
        case (1):
            pin = USER_LED_1_PIN;
            port = USER_LED_1_PORT;
            break;

        // LED 2
        case (2):
            pin = USER_LED_2_PIN;
            port = USER_LED_2_PORT;
            break;

        // LED 3
        case (3):
            pin = USER_LED_3_PIN;
            port = USER_LED_3_PORT;
            break;

        // LED 4
        case (4):
            pin = USER_LED_4_PIN;
            port = USER_LED_4_PORT;
            break;

        default:
            return ERR_ARGUMENT;
    }

    HAL_GPIO_WritePin(port, pin, enable);

    return ERR_NONE;

}
