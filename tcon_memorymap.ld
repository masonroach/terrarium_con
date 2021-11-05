/*!
 * \brief Memory definitions for TCON
 */

MEMORY
{
/*	BOOTLOADER_1 (rx)      : ORIGIN = 0x08000000, LENGTH = 32K */
/*	BOOTLOADER_2_A (rx)      : ORIGIN = 0x08000000, LENGTH = 32K */
/*	BOOTLOADER_2_B (rx)      : ORIGIN = 0x08000000, LENGTH = 32K */
	USER_FLASH      (rx) : ORIGIN = 0x08000000, LENGTH = 512K
	
	RAM       (xrw) : ORIGIN = 0x20000000, LENGTH = 40K
}
