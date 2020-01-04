/*
 * taskConfig.c
 *
 *  Created on: Jan 4, 2020
 *      Author: Administrator
 */

#include "taskConfig.h"

void task_Idle(void){}

void task_X1B(void){}

void task_X2E(void){}

void task_X2O(void){}

void task_X4(void){}

void task_X8(void){}

void task_X16(void){}

void task_X1E(void){}

const TASK_DESCRIPTOR taskDesc[TASK_COUNT] =
{
    { "IDLE", 0,  0,  task_Idle },
  	{ "X1B",  1,  0,  task_X1B  },
    { "X2E",  2,  0,  task_X2E  },
    { "X2O",  2,  1,  task_X2O  },
    { "X4",   4,  2,  task_X4   },
    { "X8",   8,  4,  task_X8   },
    { "X16",  16, 8,  task_X16  },
    { "X1E",  1,  0,  task_X1E  },
};

