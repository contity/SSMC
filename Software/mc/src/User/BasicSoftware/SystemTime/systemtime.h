/*
 * systemtime.h
 *
 *  Created on: Feb 1, 2020
 *      Author: contity
 */

#ifndef BASICSOFTWARE_SYSTEMTIME_SYSTEMTIME_H_
#define BASICSOFTWARE_SYSTEMTIME_SYSTEMTIME_H_

#include "FrameWork/Common/types.h"

typedef struct
{
	uint16 day;
	uint8 hour;
	uint8 minute;
	uint8 second;
	uint16 miniSec;
}
systime_t;

extern systime_t systime;

extern void syti_init(void);
extern void syti_task(void);

extern uint32 syti_getBaseTime(void);

#endif /* BASICSOFTWARE_SYSTEMTIME_SYSTEMTIME_H_ */
