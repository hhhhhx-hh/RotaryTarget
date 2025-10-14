#ifndef __SYSTICK_H__
#define __SYSTICK_H__

#include "stm32f10x.h"

void SysTick_Configuration(void);
void Delay_us(unsigned int NCount);

#endif
