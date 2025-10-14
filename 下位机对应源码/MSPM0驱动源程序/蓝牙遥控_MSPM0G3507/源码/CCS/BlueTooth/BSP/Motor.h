#ifndef __MOTOR_H
#define	__MOTOR_H

#include "ti_msp_dl_config.h"
#include "usart.h"
#include "stdio.h"

#define   PWMA_IN1(value)  DL_TimerG_setCaptureCompareValue(PWM_0_INST,value,GPIO_PWM_0_C0_IDX);
#define   PWMA_IN2(value)  DL_TimerG_setCaptureCompareValue(PWM_0_INST,value,GPIO_PWM_0_C1_IDX);
#define   PWMB_IN1(value)  DL_TimerG_setCaptureCompareValue(PWM_0_INST,value,GPIO_PWM_0_C2_IDX);
#define   PWMB_IN2(value)  DL_TimerG_setCaptureCompareValue(PWM_0_INST,value,GPIO_PWM_0_C3_IDX);

#define   PWMC_IN1(value)  DL_TimerG_setCaptureCompareValue(PWM_1_INST,value,GPIO_PWM_1_C0_IDX);
#define   PWMC_IN2(value)  DL_TimerG_setCaptureCompareValue(PWM_1_INST,value,GPIO_PWM_1_C1_IDX);
#define   PWMD_IN1(value)  DL_TimerG_setCaptureCompareValue(PWM_2_INST,value,GPIO_PWM_2_C0_IDX);
#define   PWMD_IN2(value)  DL_TimerG_setCaptureCompareValue(PWM_2_INST,value,GPIO_PWM_2_C1_IDX);


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
