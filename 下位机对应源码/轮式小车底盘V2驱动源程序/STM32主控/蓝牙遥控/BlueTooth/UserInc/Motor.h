#ifndef __MOTOR_H
#define	__MOTOR_H

#include "stm32f10x.h"
#include "Uart.h"
#include "bsp_motor_iic.h"

void Forward(void);
void Backward(void);
void Turnleft(void);
void Turnright(void);
void Stop(void);
void SpinLeft(void) ;
void SpinRight(void);
void Data_Analyse(void);
void Car_Function(unsigned int Car_state);

#endif
