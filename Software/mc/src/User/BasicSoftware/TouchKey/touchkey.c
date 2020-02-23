/*
 * touchkey.c
 *
 *  Created on: Feb 1, 2020
 *      Author: contity
 */

#include "touchkey.h"
#include <stdio.h>
#include "BasicSoftware/SystemTime/systemtime.h"
#include "gpio.h"
#include "tim.h"

typedef struct
{
	uint8 cycle;
	uint16 result[4];
}
touchkey_t;

touchkey_t tkey;

void tkey_init(void)
{
	tkey.cycle = 0u;

	/* output low at beginning */
	{
		GPIO_InitTypeDef GPIO_InitStruct = {0};
		/* PA2, PA3 */
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
	    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_3;
	    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	    /* PB0, PB1 */
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);
	    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
	    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
	    GPIO_InitStruct.Pull = GPIO_NOPULL;
	    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	}

	/* start timers */
	HAL_TIM_Base_Start(&htim2);
	HAL_TIM_Base_Start(&htim3);
}

void tkey_task4ms(void)
{
	switch(tkey.cycle)
	{
		case	0:	// start new
			/* T23, PA2 */
			/* T24, PA3 */
			__HAL_TIM_SET_COUNTER(&htim2, 0);
			HAL_TIM_IC_Start(&htim2,TIM_CHANNEL_3);
			HAL_TIM_IC_Start(&htim2,TIM_CHANNEL_4);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);
			/* T33, PB0 */
			/* T34, PB1 */
			__HAL_TIM_SET_COUNTER(&htim3, 0);
			HAL_TIM_IC_Start(&htim3,TIM_CHANNEL_3);
			HAL_TIM_IC_Start(&htim3,TIM_CHANNEL_4);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_SET);
			/* next */
			tkey.cycle = 1;
			break;
		case	1:	// get result & next
			/* store result */
			tkey.result[0] = __HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_3);
			tkey.result[1] = __HAL_TIM_GET_COMPARE(&htim2,TIM_CHANNEL_4);
			tkey.result[2] = __HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_3);
			tkey.result[3] = __HAL_TIM_GET_COMPARE(&htim3,TIM_CHANNEL_4);
			/* reset capacitor */
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1, GPIO_PIN_RESET);
			/* next */
			tkey.cycle = 0;
			break;
		default:
			/* next */
			tkey.cycle = 0;
			break;
	}
}

uint16 tkey_getTouchLevel(uint8 keyIndex)
{
	return tkey.result[keyIndex];
}
