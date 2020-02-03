/*
 * pushbutton.h
 *
 *  Created on: Feb 3, 2020
 *      Author: contity
 */

#ifndef BASICSOFTWARE_PUSHBUTTON_PUSHBUTTON_H_
#define BASICSOFTWARE_PUSHBUTTON_PUSHBUTTON_H_

#include "FrameWork/Common/types.h"

typedef enum
{
	PBUT_STATE_UNKNOWN,
	PBUT_STATE_IDLE,
	PBUT_STATE_ACTIVE
}
PBUT_STATE;

extern void pbut_init(void);

extern void pbut_task4ms(void);

extern PBUT_STATE pbut_getButton(uint8 index);

#endif /* BASICSOFTWARE_PUSHBUTTON_PUSHBUTTON_H_ */
