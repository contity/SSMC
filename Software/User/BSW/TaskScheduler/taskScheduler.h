/*
 * taskScheduler.h
 *
 *  Created on: Jan 4, 2020
 *      Author: Administrator
 */

#ifndef USER_BSW_TASKSCHEDULER_TASKSCHEDULER_H_
#define USER_BSW_TASKSCHEDULER_TASKSCHEDULER_H_

extern void taskScheduler_init(void);
extern void taskScheduler_main(void);

extern void taskScheduler_tickUp_ISR(void);

#endif /* USER_BSW_TASKSCHEDULER_TASKSCHEDULER_H_ */
