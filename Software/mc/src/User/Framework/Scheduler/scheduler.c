/*
 * scheduler.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
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
			                                      task_1ms();
			     if( scheduler.local.count&0x01 ) task_2ms();
			else if( scheduler.local.count&0x02 ) task_4ms();
			else if( scheduler.local.count&0x04 ) task_8ms();
			else if( scheduler.local.count&0x08 ) task_16ms();
			else if( scheduler.local.count&0x10 ) task_32ms();
			else if( scheduler.local.count&0x20 ) task_64ms();
			else if( scheduler.local.count&0x40 ) task_128ms();
			else if( scheduler.local.count&0x80 ) task_256ms();
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

