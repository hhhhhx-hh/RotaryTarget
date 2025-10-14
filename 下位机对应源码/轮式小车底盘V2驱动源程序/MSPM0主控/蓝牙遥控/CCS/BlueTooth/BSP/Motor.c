#include "Motor.h"
#include "app_motor_usart.h"

/**************************************************************************
函数功能：电机的正反转	Function: forward and reverse rotation of the motor
入口参数：速度值		Entry parameters: speed value
返回  值：无			Return value: None
**************************************************************************/

void Forward(int Speed)
{
	Contrl_Pwm(1000,1000,1000,1000);
}
void Backward(int Speed)
{
	Contrl_Pwm(-1000,-1000,-1000,-1000);
}
void Turnleft(int Speed)
{
    Contrl_Pwm(0,0,1200,1200);
}
void Turnright(int Speed)
{
    Contrl_Pwm(1200,1200,0,0);
}
void Stop(void)
{
    Contrl_Pwm(0,0,0,0);
}
void SpinLeft(int Speed)
{
    Contrl_Pwm(-700,-700,700,700);
}
void SpinRight(int Speed)
{
    Contrl_Pwm(700,700,-700,-700);
}

void Data_Analyse(void)//解析串口中断串口接收的数据	Parse the data received by the serial port interrupt
{
		if(recv0_flag == 1)
		{
			switch(recv0_buff[0])
			{
				case '1':
					printf("Forward!\n");
					Car_state = 1;
					break;
				case '2':
					printf("Backward!\n");
					Car_state = 2;
					break;
				case '3':
					printf("Left!\n");
					Car_state = 3;
					break;
				case '4':
					printf("Right!\n");
					Car_state = 4;
					break;
				case '0':
					printf("Stop!\n");
					Car_state = 0;
					break;
			}
			switch(recv0_buff[2])
			{
				case '1':
					printf("SpinLeft!\n");
					Car_state = 5;
					break;
				case '2':
					printf("SpinRight!\n");
					Car_state = 6;
					break;
			}
			recv0_flag = 0;
		}			
}

void Car_Function(unsigned int Car_state)//控制小车不同状态	Control the car in different states
{
    switch(Car_state)
    {
			case 0:
					printf("Stop\n");
					Stop();
					break;
			case 1:
					printf("Forward\n");
					Forward(2300);
					break;
			case 2:
					printf("Backward\n");
					Backward(2300);
					break;
			case 3:
					printf("Turnleft\n");
					Turnleft(2500);
					break;
			case 4:
					printf("Turnright\n");
					Turnright(2500);
					break;
			case 5:
					printf("SpinLeft\n");
					SpinLeft(2500);
					break;
			case 6:
					printf("SpinRight\n");
					SpinRight(2500);
					break;
    }
}
