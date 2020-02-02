/*
 * systemtime.c
 *
 *  Created on: Feb 1, 2020
 *      Author: contity
 */

#include "systemtime.h"

systime_t systime = {0};
uint32 syti_baseTime = 0u;

void syti_init(void)
{
	syti_baseTime = 0u;
	systime.miniSec = 0u;
	systime.second = 0u;
	systime.minute = 0u;
	systime.hour = 0u;
	systime.day = 0u;
}

void syti_task(void)
{
	syti_baseTime++;
	systime.miniSec++;
	if(systime.miniSec>=1000u)
	{
		systime.miniSec = 0u;
		systime.second++;
		if(systime.second>=60u)
		{
			systime.second = 0u;
			systime.minute++;
			if(systime.minute>=60u)
			{
				systime.minute = 0u;
				systime.hour++;
				if(systime.hour>=24u)
				{
					systime.hour = 0u;
					if(systime.day<0xFFFF)
					{
						systime.day++;
					}
				}
			}
		}
	}
}

uint32 syti_getBaseTime(void)
{
	return syti_baseTime;
}

