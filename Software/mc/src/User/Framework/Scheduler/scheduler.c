/*
 * scheduler.c
 *
 *  Created on: Jan 31, 2020
 *      Author: uid40789
 */

#include "scheduler.h"
#include "Framework/Common/types.h"

typedef struct
{
	struct
	{
		uint8 tick;
	}
	input;
	struct
	{
		uint8 tick;
		uint8 count;
	}
	local;
}
scheduler_t;

static scheduler_t scheduler;

void scheduler_init(void)
{
	scheduler.input.tick = 0u;
	scheduler.local.tick = 0u;
	scheduler.local.count = 0u;
}

void scheduler_main(void)
{
	for(;;)
	{
		if( scheduler.local.tick != scheduler.input.tick )
		{
			/* sync */
			scheduler.local.tick = scheduler.input.tick;

			/* schedule tasks */
			task_x0();
			if( scheduler.local.count&0x01 ) task_x1();
			else if( scheduler.local.count&0x02 ) task_x2();
			else if( scheduler.local.count&0x04 ) task_x4();
			else if( scheduler.local.count&0x08 ) task_x8();
			else if( scheduler.local.count&0x10 ) task_x16();
			else if( scheduler.local.count&0x20 ) task_x32();
			else if( scheduler.local.count&0x40 ) task_x64();
			else if( scheduler.local.count&0x80 ) task_x128();
			else task_x256();

			/* count up */
			scheduler.local.count++;
		}
		else
		{
			/* idle */
		}
	}
}

void scheduler_ei_tickUp_ISR(void)
{
	scheduler.input.tick++;
}

