/*!
 * \file TCON_HW_Init.c
 * \brief Initializes registers of the STM32WB30.
 * \author Mason Roach
 * \date November 7, 2021
 */
#include <stdint.h>
#if defined __GNUC__
#include "cmsis_gcc.h"
#endif

// External variables from linker script
extern uint32_t _sdata;
extern uint32_t _etext;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;

// External functions
extern int main(void);
extern void SystemInit(void);

/*!
 * \brief Initializes the RAM memory of the device before jumping to main.
 * \details
 *
 * \param None
 *
 * \returns None
 */
void __reset_handler(void) {
	uint32_t *dest, *src;

	// Set stack pointer
	__set_MSP(_estack);

	// Initialize base system
	SystemInit();

	// Copy data from flash to RAM
	dest = &_sdata;
	src = &_etext;
	while (dest < &_edata) {
	
		*dest++ = *src++;

	}

	// 0 initialize bss data
	dest = &_sbss;
	while (dest < &_ebss) {
		
		*dest++ = 0;

	}

	// 0 initialize MEM2 area
	
	// Set stack again before jumping to main code
	__set_MSP(_estack);

	// Jump to main code
	main();

}

//==============================================================================
// Interrupt handlers
//==============================================================================
void Default_Handler(void) {

	while (1);

}

void __attribute__((weak)) NMI_Handler(void) {

	while (1);

}

void __attribute((weak)) HardFault_Handler(void) {
	
	while (1);

}

void __attribute__((weak)) MemManage_Handler(void) {

	while (1);

}

void __attribute__((weak)) BusFault_Handler(void) {

	while (1);

}

void __attribute__((weak)) UsageFault_Handler(void) {

	while (1);

}

void __attribute__((weak)) SVCall_Handler(void) {

}

void __attribute__((weak)) Debug_Handler(void) {

}

void __attribute__((weak)) PendSV_Handler(void) {

}

void __attribute__((weak)) SysTick_Handler(void) {

}

void __attribute__((weak)) WWDG_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) PVD_PVM_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RTC_TAMP_STAMP_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RTC_WKUP_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) Flash_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RCC_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI0_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI3_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI4_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH3_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH4_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH5_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH6_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMA1_CH7_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) ADC1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) C2SEV_PWRC2H_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI9_5_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_BRK_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_UP_TIM16_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_TRG_COM_TIM17_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM1_CC_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TIM2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) PKA_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) I2C1_EV_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) I2C1_ER_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) SPI1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) USART1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) EXTI15_10_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) RTC_ALARM_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) PWR_SOTF_BLEACT_802ACT_RFPHASE_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) IPPC_C1_RX_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) IPCC_C1_TX_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) HSEM_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) LPTIM1_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) LPTIM2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) AES2_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) TRNG_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) FPU_ISR_Handler(void) { Default_Handler(); }
void __attribute__((weak)) DMAMUX1_OVR_ISR_Handler(void) { Default_Handler(); }

#define __ISR_IDX(addr) (addr/4)
__attribute__((section(".interrupt_vector")))
void (* const _interrupt_vector[])(void) = {

	[__ISR_IDX(0x0000)] = (void (*)())&_estack,	// Stack
	[__ISR_IDX(0x0004)] = __reset_handler,
	[__ISR_IDX(0x0008)] = NMI_Handler,
	[__ISR_IDX(0x000C)] = HardFault_Handler,
	[__ISR_IDX(0x0010)] = MemManage_Handler,
	[__ISR_IDX(0x0014)] = BusFault_Handler,
	[__ISR_IDX(0x0018)] = UsageFault_Handler,
	[__ISR_IDX(0x001C)] = 0,
	[__ISR_IDX(0x0020)] = 0,
	[__ISR_IDX(0x0024)] = 0,
	[__ISR_IDX(0x0028)] = 0,
	[__ISR_IDX(0x002C)] = SVCall_Handler,
	[__ISR_IDX(0x0030)] = Debug_Handler,
	[__ISR_IDX(0x0034)] = 0,
	[__ISR_IDX(0x0038)] = PendSV_Handler,
	[__ISR_IDX(0x003C)] = SysTick_Handler,
	[__ISR_IDX(0x0040)] = WWDG_ISR_Handler,
	[__ISR_IDX(0x0044)] = PVD_PVM_ISR_Handler,
	[__ISR_IDX(0x0048)] = RTC_TAMP_STAMP_ISR_Handler,
	[__ISR_IDX(0x004C)] = RTC_WKUP_ISR_Handler,
	[__ISR_IDX(0x0050)] = Flash_ISR_Handler,
	[__ISR_IDX(0x0054)] = RCC_ISR_Handler,
	[__ISR_IDX(0x0058)] = EXTI0_ISR_Handler,
	[__ISR_IDX(0x005C)] = EXTI1_ISR_Handler,
	[__ISR_IDX(0x0060)] = EXTI2_ISR_Handler,
	[__ISR_IDX(0x0064)] = EXTI3_ISR_Handler,
	[__ISR_IDX(0x0068)] = EXTI4_ISR_Handler,
	[__ISR_IDX(0x006C)] = DMA1_CH1_ISR_Handler,
	[__ISR_IDX(0x0070)] = DMA1_CH2_ISR_Handler,
	[__ISR_IDX(0x0074)] = DMA1_CH3_ISR_Handler,
	[__ISR_IDX(0x0078)] = DMA1_CH4_ISR_Handler,
	[__ISR_IDX(0x007C)] = DMA1_CH5_ISR_Handler,
	[__ISR_IDX(0x0080)] = DMA1_CH6_ISR_Handler,
	[__ISR_IDX(0x0084)] = DMA1_CH7_ISR_Handler,
	[__ISR_IDX(0x0088)] = ADC1_ISR_Handler,
	[__ISR_IDX(0x008C)] = 0,
	[__ISR_IDX(0x0090)] = 0,
	[__ISR_IDX(0x0094)] = C2SEV_PWRC2H_ISR_Handler,
	[__ISR_IDX(0x0098)] = 0,
	[__ISR_IDX(0x009C)] = EXTI9_5_ISR_Handler,
	[__ISR_IDX(0x00A0)] = TIM1_BRK_ISR_Handler,
	[__ISR_IDX(0x00A4)] = TIM1_UP_TIM16_ISR_Handler,
	[__ISR_IDX(0x00A8)] = TIM1_TRG_COM_TIM17_ISR_Handler,
	[__ISR_IDX(0x00AC)] = TIM1_CC_ISR_Handler,
	[__ISR_IDX(0x00B0)] = TIM2_ISR_Handler,
	[__ISR_IDX(0x00B4)] = PKA_ISR_Handler,
	[__ISR_IDX(0x00B8)] = I2C1_EV_ISR_Handler,
	[__ISR_IDX(0x00BC)] = I2C1_ER_ISR_Handler,
	[__ISR_IDX(0x00C0)] = 0,
	[__ISR_IDX(0x00C4)] = 0,
	[__ISR_IDX(0x00C8)] = SPI1_ISR_Handler,
	[__ISR_IDX(0x00CC)] = 0,
	[__ISR_IDX(0x00D0)] = USART1_ISR_Handler,
	[__ISR_IDX(0x00D4)] = 0,
	[__ISR_IDX(0x00D8)] = 0,
	[__ISR_IDX(0x00DC)] = 0,
	[__ISR_IDX(0x00E0)] = EXTI15_10_ISR_Handler,
	[__ISR_IDX(0x00E4)] = RTC_ALARM_ISR_Handler,
	[__ISR_IDX(0x00E8)] = 0,
	[__ISR_IDX(0x00EC)] = PWR_SOTF_BLEACT_802ACT_RFPHASE_ISR_Handler,
	[__ISR_IDX(0x00F0)] = IPPC_C1_RX_ISR_Handler,
	[__ISR_IDX(0x00F4)] = IPCC_C1_TX_ISR_Handler,
	[__ISR_IDX(0x00F8)] = HSEM_ISR_Handler,
	[__ISR_IDX(0x00FC)] = LPTIM1_ISR_Handler,
	[__ISR_IDX(0x0100)] = LPTIM2_ISR_Handler,
	[__ISR_IDX(0x0104)] = 0,
	[__ISR_IDX(0x0108)] = 0,
	[__ISR_IDX(0x010C)] = 0,
	[__ISR_IDX(0x0110)] = AES2_ISR_Handler,
	[__ISR_IDX(0x0114)] = TRNG_ISR_Handler,
	[__ISR_IDX(0x0118)] = FPU_ISR_Handler,
	[__ISR_IDX(0x011C)] = 0,
	[__ISR_IDX(0x0120)] = 0,
	[__ISR_IDX(0x0124)] = 0,
	[__ISR_IDX(0x0128)] = 0,
	[__ISR_IDX(0x012C)] = 0,
	[__ISR_IDX(0x0130)] = 0,
	[__ISR_IDX(0x0134)] = 0,
	[__ISR_IDX(0x0138)] = DMAMUX1_OVR_ISR_Handler,

};
