/*
 * rotatelamp.h
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#ifndef APPLICATIONSOFTWARE_ROTATELAMP_ROTATELAMP_H_
#define APPLICATIONSOFTWARE_ROTATELAMP_ROTATELAMP_H_

typedef enum
{
	ROLA_DIR_CW = 0,
	ROLA_DIR_CCW
}
ROLA_DIR;

extern void rola_init(void);
extern void rola_task(void);
extern void rola_task1ms(void);

extern void rola_start(ROLA_DIR dir);
extern void rola_stop(void);

#endif /* APPLICATIONSOFTWARE_ROTATELAMP_ROTATELAMP_H_ */
