/*
 * cfg_task.c
 *
 *  Created on: Jan 31, 2020
 *      Author: uid40789
 */

#include "Framework/Scheduler/scheduler.h"
#include "gpio.h"

void task_2pow0(void)
{

}

void task_2pow1(void)
{

}

void task_2pow2(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
}

void task_2pow3(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
}

void task_2pow4(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
}

void task_2pow5(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_6);
}

void task_2pow6(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_5);
}

void task_2pow7(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
}

void task_2pow8(void)
{
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
}

void task_2pow9(void)
{
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_15);
}

