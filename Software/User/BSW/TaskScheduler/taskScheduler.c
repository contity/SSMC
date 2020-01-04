/*
 * taskScheduler.c
 *
 *  Created on: Jan 4, 2020
 *      Author: Administrator
 */

#include "../Common/myTypes.h"
#include "taskScheduler.h"
#include "taskConfig.h"

typedef struct
{
	uint8 inTick;
	uint8 tick;
	uint8 taskTimer[TASK_COUNT];
	uint8 taskIndex;
}
TASK_RUNTIME;

TASK_RUNTIME taskRuntime;

void taskScheduler_init(void)
{
	uint8 i;
	taskRuntime.inTick = 0;
	taskRuntime.tick = 0;
	for(i=0;i<TASK_COUNT;i++)
	{
		taskRuntime.taskTimer[i] = taskDesc[i].offset;
	}
	taskRuntime.taskIndex = 0;
}

void taskScheduler_main(void)
{
	uint8 i;

	if(taskRuntime.tick!=taskRuntime.inTick)  /* schedule on time */
	{
		// scan all tasks
		for(i=0;i<TASK_COUNT;i++)
		{
			// cycle is not 0
			if(taskDesc[i].cycle)
			{
				// count down
				if(taskRuntime.taskTimer[i])
				{
					taskRuntime.taskTimer[i]--;
					// run task
					if(!taskRuntime.taskTimer[i])
					{
						// execute task
						if(taskDesc[i].pTask)
						{
							taskDesc[i].pTask();
						}
						// start next cycle
						taskRuntime.taskTimer[i] = taskDesc[i].cycle;
					}
				}
			}
		}
		/* sync the tick */
		taskRuntime.tick = taskRuntime.inTick;
	}
	else	/* idle always run */
	{
		/* check range */
		if(taskRuntime.taskIndex>=TASK_COUNT)
		{
			taskRuntime.taskIndex = 0;
		}
		/* cycle is 0 */
		if(!taskDesc[taskRuntime.taskIndex].cycle)
		{
			// execute task
			if(taskDesc[taskRuntime.taskIndex].pTask)
			{
				taskDesc[taskRuntime.taskIndex].pTask();
			}
		}
		/* next cycle */
		taskRuntime.taskIndex++;
	}
}

void taskScheduler_tickUp_ISR(void)
{
	taskRuntime.inTick++;
}
