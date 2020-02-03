/*
 * cfg_task.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#include "Framework/Scheduler/scheduler.h"
#include "BasicSoftware/SystemTime/systemtime.h"
#include "BasicSoftware/TouchKey/touchkey.h"
#include "ApplicationSoftware/RotateLamp/rotatelamp.h"
#include "ApplicationSoftware/TestApp/testapp.h"

void task_init(void)
{
	syti_init();
	rola_init();
//	tkey_init();
	// app
	tapp_init();
}

void task_2pow0(void)
{
	syti_task();
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
//	tkey_task();
}

void task_2pow8(void)
{
	tapp_task();
}

