/*
 * cfg_task.c
 *
 *  Created on: Jan 31, 2020
 *      Author: contity
 */

#include "Framework/Scheduler/scheduler.h"
#include "ApplicationSoftware/RotateLamp/rotatelamp.h"
#include "usart.h"

const char text2p1[] = "1       \n";
const char text2p2[] = " 2      \n";
const char text2p3[] = "  3     \n";
const char text2p4[] = "   4    \n";
const char text2p5[] = "    5   \n";
const char text2p6[] = "     6  \n";
const char text2p7[] = "      7 \n";
const char text2p8[] = "       8\n";

void task_2pow0(void)
{
	rola_task1ms();
}

void task_2pow1(void)
{
//	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p1, sizeof(text2p1));
}

void task_2pow2(void)
{
//	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p2, sizeof(text2p1));
}

void task_2pow3(void)
{
//	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p3, sizeof(text2p1));
}

void task_2pow4(void)
{
//	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p4, sizeof(text2p1));
}

void task_2pow5(void)
{
	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p5, sizeof(text2p1));
}

void task_2pow6(void)
{
	rola_task();
	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p6, sizeof(text2p1));
}

void task_2pow7(void)
{
	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p7, sizeof(text2p1));
}

void task_2pow8(void)
{
	HAL_UART_Transmit_IT(&huart1, (uint8*)text2p8, sizeof(text2p1));
}

