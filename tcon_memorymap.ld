/*!
 * \brief Memory definitions for STM32WB55RG
 */

MEMORY
{
/*	BOOTLOADER (rx)      : ORIGIN = 0x08000000, LENGTH = 32K */
	USER_FLASH      (rx) : ORIGIN = 0x08000000, LENGTH = 1M
	
	RAM       (xrw) : ORIGIN = 0x20000000, LENGTH = 192K
}
