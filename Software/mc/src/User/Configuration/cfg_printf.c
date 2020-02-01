/*
 * cfg_printf.c
 *
 *  Created on: Feb 1, 2020
 *      Author: contity
 */

#include <stdio.h>
#include "usart.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
	uint8 txdata = ch;
	HAL_UART_Transmit(&huart1, &txdata, 1, 72000);
	return ch;
}

