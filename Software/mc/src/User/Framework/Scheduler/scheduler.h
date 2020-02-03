/*
 * scheduler.h
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

extern void scheduler_init(void);
extern void scheduler_main(void);

extern void scheduler_ei_tickUp_ISR(void); /* Event Input from ISR */

extern void task_init(void);    // init all tasks
extern void task_1ms(void);
extern void task_2ms(void);
extern void task_4ms(void);
extern void task_8ms(void);
extern void task_16ms(void);
extern void task_32ms(void);
extern void task_64ms(void);
extern void task_128ms(void);
extern void task_256ms(void);

#endif /* SCHEDULER_H_ */
