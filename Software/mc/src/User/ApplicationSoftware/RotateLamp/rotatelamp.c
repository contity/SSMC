/*
 * rotatelamp.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#include "rotatelamp.h"
#include "Framework/Common/types.h"
#include "gpio.h"
#include <stdio.h>

/* =============================================================================== */
/* simulated rotator ======================================================= begin */

#define U256 256

typedef struct
{
	/* U256 i.e. need div 256 */

	/* input */
	sint32 powerPlus;
	sint32 powerMinus;
	sint32 extResist;
	sint32 intResist;
	/* process */
	sint32 exAcc_U256;
	sint32 deAcc_U256;
	sint32 acc_U256;
	sint32 speed_U256;
	sint32 pos_U256;
	/* output */
	uint16 pos;		// 0-65536 i.e. 0-360 degree
}
siro_t;

siro_t siro;

static void siro_init(void)
{
	siro.powerPlus = 0;
	siro.powerMinus = 0;
	siro.extResist = 0;
	siro.intResist = 1;
}

static void siro_task1ms(void)
{
	/* process, all in unit of 256 */
	siro.exAcc_U256 = U256 * (siro.powerPlus-siro.powerMinus);
	siro.deAcc_U256 = siro.speed_U256 * (siro.extResist+siro.intResist) / U256;
	siro.acc_U256 = siro.exAcc_U256 - siro.deAcc_U256;
	siro.speed_U256 += siro.acc_U256;
	if( siro.speed_U256<U256 && siro.speed_U256>-U256) siro.speed_U256 = 0;
	siro.pos_U256 += siro.speed_U256;
	/* output */
	siro.pos = (uint16)(siro.pos_U256/U256);
}

/* simulated rotator ========================================================= end */
/* =============================================================================== */

#include "BasicSoftware/PushButton/pushbutton.h"

typedef struct
{
	uint8 step;
	/* output */
	uint8 phase;	// 0-8 i.e. 0-360 degree
	uint8 ledMask;
}
rola_t;

rola_t rola;

const uint8 phase2ledMask[8] = { 0x01u, 0x02u, 0x04u, 0x08u, 0x10u, 0x20u, 0x40u, 0x80u };

void rola_init(void)
{
	rola.step = 0;
	siro_init();
}

void rola_task1ms(void)
{
	/* rotator input */
	siro.powerPlus = pbut_getButton(0);
	siro.powerMinus = pbut_getButton(1);
	siro.extResist = (pbut_getButton(2)-1)*2+(pbut_getButton(3)-1)*4;
	siro.intResist = 1;

	/* simulated rotator */
	siro_task1ms();

	/* rotator - output */
	rola.phase = siro.pos>>13u;
	rola.ledMask = phase2ledMask[rola.phase];

	/* output to hardware */
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (rola.ledMask&0x01u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,  (rola.ledMask&0x02u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,  (rola.ledMask&0x04u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,  (rola.ledMask&0x08u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,  (rola.ledMask&0x10u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,  (rola.ledMask&0x20u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,  (rola.ledMask&0x40u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9,  (rola.ledMask&0x80u)?GPIO_PIN_SET:GPIO_PIN_RESET);
}

void rola_task(void)
{
	rola.step++;

	printf("%d: (%ld)-(%ld)=(%ld) -> %ld -> %d, %d\r\n",
			rola.step,
			siro.exAcc_U256, siro.deAcc_U256, siro.acc_U256,
			siro.speed_U256, siro.pos, rola.phase
			);
}

void rola_start(ROLA_DIR dir)
{
	(void)dir;
}

void rola_stop(void)
{
}

