/*
 * pushbutton.c
 *
 *  Created on: Feb 3, 2020
 *      Author: contity
 */

#include "pushbutton.h"
#include "gpio.h"

typedef struct
{
	GPIO_TypeDef * GPIOx;
	uint16 Pin;
}
pushButtonDesc_t;

const pushButtonDesc_t pbutDesc[4] =
{
	{ GPIOA, GPIO_PIN_2 },
	{ GPIOA, GPIO_PIN_3 },
	{ GPIOB, GPIO_PIN_0 },
	{ GPIOB, GPIO_PIN_1 },
};

typedef struct
{
	uint8 initCnt;
	PBUT_STATE state[4];
	uint16 debounce[4];
}
pushButton_t;

pushButton_t pbut;

void pbut_init(void)
{
	/* init data */
	pbut.initCnt = 25u;
	pbut.state[0] = PBUT_STATE_UNKNOWN;
	pbut.state[1] = PBUT_STATE_UNKNOWN;
	pbut.state[2] = PBUT_STATE_UNKNOWN;
	pbut.state[3] = PBUT_STATE_UNKNOWN;

	/* input with pull up */
	{
		GPIO_InitTypeDef GPIO_InitStruct = {0};
		/* PA2, PA3 */
	    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
	    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	    GPIO_InitStruct.Pull = GPIO_PULLUP;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	    /* PB0, PB1 */
	    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
	    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	    GPIO_InitStruct.Pull = GPIO_PULLUP;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	}
}

void pbut_task4ms(void)
{
	uint8 i;
	for(i=0;i<4;i++)
	{
		/* debounce */
		uint16 input;
		input = (pbutDesc[i].GPIOx->IDR) & (pbutDesc[i].Pin);
		pbut.debounce[i] <<= 1u;
		if(input) pbut.debounce[i] |= 1u;

		/* state */
		if(PBUT_STATE_UNKNOWN==pbut.state[i])
		{
			if(pbut.initCnt)
			{
				pbut.initCnt--;
			}
			else
			{
				pbut.state[i] = input? PBUT_STATE_IDLE: PBUT_STATE_ACTIVE;
			}
		}
		else
		{
			/* debounce is 4ms x 7 = 28ms */
			if( (pbut.debounce[i] & 0xFF)==0x80 ) pbut.state[i] = PBUT_STATE_ACTIVE;
			if( (pbut.debounce[i] & 0xFF)==0x7F ) pbut.state[i] = PBUT_STATE_IDLE;
		}
	}
}

PBUT_STATE pbut_getButton(uint8 index)
{
	if(index<4) return pbut.state[index];
	return PBUT_STATE_UNKNOWN;
}
