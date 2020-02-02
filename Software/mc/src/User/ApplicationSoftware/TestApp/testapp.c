/*
 * testapp.c
 *
 *  Created on: Feb 2, 2020
 *      Author: contity
 */

#include "testapp.h"
#include <stdio.h>
#include "BasicSoftware/SystemTime/systemtime.h"

uint32 cnt = 0u;

void tapp_init(void)
{
	cnt = 0u;
}

void tapp_task(void)
{
	cnt++;

	/* test for system time */
	printf("%u: [%u] <%u> %u:%u:%u.%u\r\n", (uint)cnt,
			(uint)syti_getBaseTime(),
			(uint)systime.day,
			(uint)systime.hour, (uint)systime.minute, (uint)systime.second, (uint)systime.miniSec);
}

