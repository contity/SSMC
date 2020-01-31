/*
 * cfg_task.c
 *
 *  Created on: Jan 31, 2020
 *      Author: uid40789
 */

#include "Framework/Scheduler/scheduler.h"
#include "gpio.h"

void task_x0(void)
{

}

void task_x1(void)
{

}

void task_x2(void)
{
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_9);
}

void task_x4(void)
{
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_8);
}

void task_x8(void)
{
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_7);
}

void task_x16(void)
{
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_6);
}

void task_x32(void)
{
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_5);
}

void task_x64(void)
{
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_4);
}

void task_x128(void)
{
	LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_3);
}

void task_x256(void)
{
	LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_15);
}

