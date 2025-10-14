#ifndef __MOTOR_H
#define	__MOTOR_H

#include "stm32f10x.h"
#include "Pwm.h"
#include "Uart.h"

void Forward(int Speed);
void Backward(int Speed);
void Turnleft(int Speed);
void Turnright(int Speed);
void Stop(void);
void SpinLeft(int Speed) ;
void SpinRight(int Speed);
void Data_Analyse(void);
void Car_Function(unsigned int Car_state);

#endif
