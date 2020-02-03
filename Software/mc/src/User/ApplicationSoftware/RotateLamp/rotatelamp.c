/*
 * rotatelamp.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#include "rotatelamp.h"
#include "Framework/Common/types.h"
#include "gpio.h"

/* =============================================================================== */
/* simulated rotator ======================================================= begin */

typedef enum
{
	SIRO_DIR_STOP,
	SIRO_DIR_CW,
	SIRO_DIR_CCW,
}
SIRO_DIR;

typedef struct
{
	/* input */
	uint8 powerPlus;
	uint8 powerMinus;
	/* process */
	sint16 acc;       // 1 pos/ms /ms
	sint16 speed;     // 1 pos/ms
	sint16 position;  // 256 pos/cyce

	SIRO_DIR dir;
	uint8 position; // 256 position / cycle
	uint8 speed;    // 1 position / ms
	/* output */
	uint8 out;
}
siro_t;

siro_t siro;

static void siro_init(void)
{
	siro.powerMinus = 0u;
	siro.powerPlus = 0u;
	siro.dir = SIRO_DIR_STOP;
	siro.out = 0u;
}

static void siro_task1ms(void)
{
	/* input */

	/* process - dir */
	if(        siro.powerPlus && !siro.powerMinus ) siro.dir = SIRO_DIR_CW;
	else if ( !siro.powerPlus &&  siro.powerMinus ) siro.dir = SIRO_DIR_CCW;
	else                                            siro.dir = SIRO_DIR_STOP;

	/* process - rotate */

	/* output */
}

/* simulated rotator ========================================================= end */
/* =============================================================================== */

typedef struct
{
	uint8 out;
	uint8 step;
}
rola_t;

rola_t rola;

void rola_init(void)
{
	rola.out = 0u;
	rola.step = 0u;
}

void rola_task1ms(void)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, (rola.out&0x01u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3,  (rola.out&0x02u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4,  (rola.out&0x04u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5,  (rola.out&0x08u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6,  (rola.out&0x10u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7,  (rola.out&0x20u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_8,  (rola.out&0x40u)?GPIO_PIN_SET:GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9,  (rola.out&0x80u)?GPIO_PIN_SET:GPIO_PIN_RESET);
}

void rola_task(void)
{
	rola.step++;
	rola.step &= 0x07;
	rola.out = (0x01u << rola.step);
}

void rola_start(ROLA_DIR dir)
{
	(void)dir;
}

void rola_stop(void)
{
}

