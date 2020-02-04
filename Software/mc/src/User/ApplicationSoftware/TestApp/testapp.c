/*
 * testapp.c
 *
 *  Created on: Feb 2, 2020
 *      Author: contity
 */

#include "testapp.h"
#include <stdio.h>
#include "BasicSoftware/SystemTime/systemtime.h"
#include "BasicSoftware/TouchKey/touchkey.h"
#include "BasicSoftware/PushButton/pushbutton.h"

uint32 cnt = 0u;

void tapp_init(void)
{
	cnt = 0u;
}

void tapp_task(void)
{
	cnt++;

#if 0
	/* test for push button */
	printf("%u: %u, %u, %u, %u\r\n", (uint)cnt,
			pbut_getButton(0), pbut_getButton(1), pbut_getButton(2), pbut_getButton(3));
#endif

#if 0
	/* test for touch key */
	printf("%u: %u, %u, %u, %u\r\n", (uint)cnt,
			tkey_getTouchLevel(0), tkey_getTouchLevel(1), tkey_getTouchLevel(2), tkey_getTouchLevel(3));
#endif

#if 0
	/* test for system time */
	printf("%u: [%u] <%u> %u:%u:%u.%u\r\n", (uint)cnt,
			(uint)syti_getBaseTime(),
			(uint)systime.day,
			(uint)systime.hour, (uint)systime.minute, (uint)systime.second, (uint)systime.miniSec);
#endif
}

