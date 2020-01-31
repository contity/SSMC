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

extern void task_2pow0(void);	// 1ms
extern void task_2pow1(void);	// 2ms
extern void task_2pow2(void);	// 4ms
extern void task_2pow3(void);	// 8ms
extern void task_2pow4(void);	// 16ms
extern void task_2pow5(void);	// 32ms
extern void task_2pow6(void);	// 64ms
extern void task_2pow7(void);	// 128ms
extern void task_2pow8(void);	// 256ms

#endif /* SCHEDULER_H_ */
