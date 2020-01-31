/*
 * scheduler.h
 *
 *  Created on: Jan 31, 2020
 *      Author: uid40789
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

extern void scheduler_init(void);
extern void scheduler_main(void);

extern void scheduler_ei_tickUp_ISR(void); /* Event Input from ISR */

extern void task_x0(void);
extern void task_x1(void);
extern void task_x2(void);
extern void task_x4(void);
extern void task_x8(void);
extern void task_x16(void);
extern void task_x32(void);
extern void task_x64(void);
extern void task_x128(void);
extern void task_x256(void);

#endif /* SCHEDULER_H_ */
