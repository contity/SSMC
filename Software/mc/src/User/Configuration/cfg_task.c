/*
 * cfg_task.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#include "Framework/Scheduler/scheduler.h"
#include "BasicSoftware/SystemTime/systemtime.h"
#include "BasicSoftware/TouchKey/touchkey.h"
#include "BasicSoftware/PushButton/pushbutton.h"
#include "ApplicationSoftware/RotateLamp/rotatelamp.h"
#include "ApplicationSoftware/TestApp/testapp.h"

void task_init(void)
{
	syti_init();
	rola_init();
	tkey_init();
	// app
	tapp_init();
}

void task_1ms(void)
{
	syti_task();
	rola_task1ms();
}

void task_2ms(void)
{
}

void task_4ms(void)
{
	tkey_task4ms();
}

void task_8ms(void)
{
}

void task_16ms(void)
{
}

void task_32ms(void)
{
}

void task_64ms(void)
{
	rola_task();
}

void task_128ms(void)
{
}

void task_256ms(void)
{
	tapp_task();
}

