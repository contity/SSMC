/*
 * taskConfig.h
 *
 *  Created on: Jan 4, 2020
 *      Author: Administrator
 */

#ifndef BSW_TASKSCHEDULER_TASKCONFIG_H_
#define BSW_TASKSCHEDULER_TASKCONFIG_H_

#include "BSW/Common/myTypes.h"

#ifndef TASK_COUNT
#define TASK_COUNT 8
#endif

typedef void (*P_TASK)(void);

typedef struct
{
	uint8 name[8];
	uint8 cycle;    // based on scheduler tick
	uint8 offset;   // start delay
	P_TASK pTask;	// task function
}
TASK_DESCRIPTOR;

extern const TASK_DESCRIPTOR taskDesc[TASK_COUNT];

#endif /* BSW_TASKSCHEDULER_TASKCONFIG_H_ */
