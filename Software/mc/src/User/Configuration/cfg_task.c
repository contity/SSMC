/*
 * cfg_task.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#include "Framework/Scheduler/scheduler.h"
#include "ApplicationSoftware/RotateLamp/rotatelamp.h"
#include "usart.h"
#include <stdio.h>

unsigned int time_ms = 0u;

void task_2pow0(void)
{
	time_ms++;
	rola_task1ms();
}

void task_2pow1(void)
{
}

void task_2pow2(void)
{
}

void task_2pow3(void)
{
}

void task_2pow4(void)
{
}

void task_2pow5(void)
{
}

void task_2pow6(void)
{
	rola_task();
}

void task_2pow7(void)
{
}

void task_2pow8(void)
{
	printf("%u\r\n", time_ms);
}

