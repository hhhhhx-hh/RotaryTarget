#include "Motor.h"

/**************************************************************************
函数功能：电机的正反转
入口参数：
返回  值：无
**************************************************************************/

void Forward(int Speed)
{
		PWMA_IN1=Speed;PWMA_IN2=0;  //左前轮  Speed=6000
		PWMB_IN1=0;PWMB_IN2=Speed;  //右前轮
		PWMC_IN1=0;PWMC_IN2=Speed;  //右后轮
		PWMD_IN1=Speed;PWMD_IN2=0;  //左后轮
}
void Backward(int Speed)
{

	  PWMA_IN1=0;PWMA_IN2=Speed;
	  PWMB_IN1=Speed;PWMB_IN2=0;
		PWMC_IN1=Speed;PWMC_IN2=0;
	  PWMD_IN1=0;PWMD_IN2=Speed;		
		
	}
void Turnleft(int Speed)
{
		PWMA_IN1=0;PWMA_IN2=0;
		PWMB_IN1=0;PWMB_IN2=Speed; //Speed=6500   
		PWMC_IN1=0;PWMC_IN2=Speed;
		PWMD_IN1=0;PWMD_IN2=0;
}
void Turnright(int Speed)
{
		PWMA_IN1=Speed;PWMA_IN2=0;//Speed=6500
		PWMB_IN1=0;PWMB_IN2=0;
		PWMC_IN1=0;PWMC_IN2=0;
		PWMD_IN1=Speed;PWMD_IN2=0;
}
void Stop(void)
{
		PWMA_IN1=0;PWMA_IN2=0;
		PWMB_IN1=0;PWMB_IN2=0;
		PWMC_IN1=0;PWMC_IN2=0;
		PWMD_IN1=0;PWMD_IN2=0;
}
void SpinLeft(int Speed)   //左轮后退右轮前进     电池7.9V左右左旋90度左右   （满电8.43V）//Speed=7000
{
		PWMA_IN1=0;PWMA_IN2=Speed;
		PWMB_IN1=0;PWMB_IN2=Speed;
		PWMC_IN1=0;PWMC_IN2=Speed;
		PWMD_IN1=0;PWMD_IN2=Speed;
}
void SpinRight(int Speed)   //左轮前进右轮后退      电池7.9V左右左旋90度左右
{
		PWMA_IN1=Speed;PWMA_IN2=0;//Speed=7000
		PWMB_IN1=Speed;PWMB_IN2=0;
		PWMC_IN1=Speed;PWMC_IN2=0;
		PWMD_IN1=Speed;PWMD_IN2=0;
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
					Forward(6000);
					break;
			case 2:
					printf("Backward\n");
					Backward(6000);
					break;
			case 3:
					printf("Turnleft\n");
					Turnleft(6500);
					break;
			case 4:
					printf("Turnright\n");
					Turnright(6500);
					break;
			case 5:
					printf("SpinLeft\n");
					SpinLeft(7000);
					break;
			case 6:
					printf("SpinRight\n");
					SpinRight(7000);
					break;
    }
}
