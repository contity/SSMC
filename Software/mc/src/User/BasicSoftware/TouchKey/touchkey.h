/*
 * touchkey.h
 *
 *  Created on: Feb 1, 2020
 *      Author: contity
 */

#ifndef APPLICATIONSOFTWARE_TOUCHKEY_TOUCHKEY_H_
#define APPLICATIONSOFTWARE_TOUCHKEY_TOUCHKEY_H_

#include "FrameWork/Common/types.h"

extern void tkey_init(void);
extern void tkey_task4ms(void);

extern uint16 tkey_getTouchLevel(uint8 keyIndex);

#endif /* APPLICATIONSOFTWARE_TOUCHKEY_TOUCHKEY_H_ */
