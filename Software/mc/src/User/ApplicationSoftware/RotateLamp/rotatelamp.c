/*
 * rotatelamp.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#include "Framework/Common/types.h"
#include "gpio.h"

typedef struct
{
	uint8 out;
	uint8 step;
}
rola_t;

rola_t rola;

void rola_init(void)
{
	rola.out = 0u;
	rola.step = 0u;
}

void rola_task1ms(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (rola.out&0x01u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,  (rola.out&0x02u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,  (rola.out&0x04u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,  (rola.out&0x08u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,  (rola.out&0x10u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,  (rola.out&0x20u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,  (rola.out&0x40u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9,  (rola.out&0x80u)?GPIO_PIN_SET:GPIO_PIN_RESET);
}

void rola_task(void)
{
	rola.step++;
	rola.step &= 0x07;
	rola.out = (0x01u << rola.step);
}
