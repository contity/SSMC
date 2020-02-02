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

	task_init();
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
			                                      task_2pow0();
			if( scheduler.local.count&0x01 )      task_2pow1();
			else if( scheduler.local.count&0x02 ) task_2pow2();
			else if( scheduler.local.count&0x04 ) task_2pow3();
			else if( scheduler.local.count&0x08 ) task_2pow4();
			else if( scheduler.local.count&0x10 ) task_2pow5();
			else if( scheduler.local.count&0x20 ) task_2pow6();
			else if( scheduler.local.count&0x40 ) task_2pow7();
			else if( scheduler.local.count&0x80 ) task_2pow8();
			else ;

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

