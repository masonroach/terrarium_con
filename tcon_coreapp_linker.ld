/*!
 * \brief Linker script for the STM32WB30.
 */

INCLUDE "tcon_memorymap.ld"

ENTRY(__reset_handler)

STACK_SIZE = 0x2000; /* 8kB */

_estack = (ORIGIN (RAM) + STACK_SIZE);

SECTIONS
{
/*
	.bootloader (NOLOAD) :
	{
		. = ALIGN(4);
	} > BOOTLOADER
*/
	.interrupt_vector :
	{
		. = ALIGN(4);
		KEEP(*(.interrupt_vector))
		. = ALIGN(4);
	} > APP_FLASH

	.text :
	{
		. = ALIGN(4);
		*(.text)
		*(.text*)
		*(.glue_7)
		*(.glue_7t)
		*(.eh_fram)
		KEEP(*(.init))
		KEEP(*(.fini))
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
		_etext = . ;
	} > APP_FLASH

	.data :
	{
		. = ALIGN(4);
		_sdata = . ;
		*(.data)
		*(.data*)
		_edata = . ;
	} > RAM AT > APP_FLASH

	.bss :
	{
		_sbss = . ;
		*(.bss)
		*(.bss*)
		*(COMMON)
		_ebss = . ;
	} > RAM

	.stack :
	{
		. = ALIGN(8);
		. = . + STACK_SIZE;
		. = ALIGN(8);
	} > RAM

	_end = . ;

}

