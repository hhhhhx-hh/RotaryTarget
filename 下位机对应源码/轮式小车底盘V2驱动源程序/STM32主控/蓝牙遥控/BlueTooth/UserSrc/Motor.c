#include "Motor.h"

void Forward(void)
{
    control_pwm(1500,1500,1500,1500);
}
void Backward(void)
{
    control_pwm(-1500,-1500,-1500,-1500);
}
void Turnleft(void)
{
    control_pwm(0,0,2000,2000);
}
void Turnright(void)
{
    control_pwm(2000,2000,0,0);
}
void Stop(void)
{
    control_pwm(0,0,0,0);
}
void SpinLeft(void)
{
    control_pwm(-1500,-1500,1500,1500);
}
void SpinRight(void)
{
    control_pwm(1500,1500,-1500,-1500);
}

void Data_Analyse(void)//解析串口中断串口接收的数据
{
		if(rxd_flag == 1)
		{
			switch(rxd_buf[0])
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
			switch(rxd_buf[2])
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
			rxd_flag = 0;
		}			
}

void Car_Function(unsigned int Car_state)//控制小车不同状态
{
    switch(Car_state)
    {
			case 0:
					printf("Stop\n");
					Stop();
					break;
			case 1:
					printf("Forward\n");
					Forward();
					break;
			case 2:
					printf("Backward\n");
					Backward();
					break;
			case 3:
					printf("Turnleft\n");
					Turnleft();
					break;
			case 4:
					printf("Turnright\n");
					Turnright();
					break;
			case 5:
					printf("SpinLeft\n");
					SpinLeft();
					break;
			case 6:
					printf("SpinRight\n");
					SpinRight();
					break;
    }
}
