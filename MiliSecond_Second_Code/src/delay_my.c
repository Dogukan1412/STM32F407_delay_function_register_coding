/*
 * delay_my.c
 *
 *  Created on: 9 May 2023
 *      Author: Dogukan AKCA
 */

#include "delay_my.h"

uint32_t SysTick_Counter;



void SysTick_Handler()
{
		SysTick_Counter++;
}

void delay_my_ms(uint32_t delay)
{
	while(delay != SysTick_Counter);
	if(delay == SysTick_Counter)
	{
		SysTick_Counter = 0;
	}
}

void delay_my_s(uint8_t delay)
{
	while(1000*delay != SysTick_Counter);
	if(1000*delay == SysTick_Counter)
	{
		SysTick_Counter = 0;
	}
}


