/*!
 * \brief
 */
#include "TCON_HW_CLK.h"

Sys_Err_t HW_CLK_Init(void) {
	RCC_OscInitTypeDef rcc_osc = {0};
	RCC_ClkInitTypeDef rcc_clk = {0};
	RCC_PeriphCLKInitTypeDef per_clk = {0};

    HAL_PWR_EnableBkUpAccess();
    __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

    rcc_osc.OscillatorType = RCC_OSCILLATORTYPE_HSI |
                             RCC_OSCILLATORTYPE_MSI |
//                             RCC_OSCILLATORTYPE_LSE |
                             RCC_OSCILLATORTYPE_LSI1;
    rcc_osc.MSIState = RCC_MSI_ON;
    rcc_osc.HSIState = RCC_HSI_ON;
//    rcc_osc.LSEState = RCC_LSE_ON;
    rcc_osc.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    rcc_osc.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
    rcc_osc.MSIClockRange = RCC_MSIRANGE_6;
    rcc_osc.LSIState = RCC_LSI_ON;
    rcc_osc.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&rcc_osc) != HAL_OK) {
        return ERR_INIT;
    }

    rcc_clk.ClockType = RCC_CLOCKTYPE_HCLK4  |
                        RCC_CLOCKTYPE_HCLK2  |
                        RCC_CLOCKTYPE_HCLK   |
                        RCC_CLOCKTYPE_SYSCLK |
                        RCC_CLOCKTYPE_PCLK1  |
                        RCC_CLOCKTYPE_PCLK2;
    rcc_clk.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
    rcc_clk.AHBCLKDivider = RCC_SYSCLK_DIV1;
    rcc_clk.APB1CLKDivider = RCC_HCLK_DIV1;
    rcc_clk.APB2CLKDivider = RCC_HCLK_DIV1;
    rcc_clk.AHBCLK2Divider = RCC_SYSCLK_DIV1;
    rcc_clk.AHBCLK4Divider = RCC_SYSCLK_DIV1;
    if (HAL_RCC_ClockConfig(&rcc_clk, FLASH_LATENCY_0) != HAL_OK) {
        return ERR_INIT;
    }

    per_clk.PeriphClockSelection = RCC_PERIPHCLK_RTC    |
                                   RCC_PERIPHCLK_USART1 |
                                   RCC_PERIPHCLK_I2C1;
    per_clk.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
    per_clk.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
    per_clk.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
    if (HAL_RCCEx_PeriphCLKConfig(&per_clk) != HAL_OK) {
        return ERR_INIT;
    }

    return ERR_NONE;

}