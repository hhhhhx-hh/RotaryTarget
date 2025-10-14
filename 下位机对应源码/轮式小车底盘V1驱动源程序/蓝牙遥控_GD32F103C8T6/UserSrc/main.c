#include "stm32f10x.h" 
#include "SysTick.h"
#include "Uart.h"
#include "Pwm.h"
#include "Motor.h"

int main(void)
{    
    SysTick_Configuration();		//配置定时器
    Uart1_Configuration();			//配置UART1串口
    Uart1_NVIC_Configuration();	//配置UART1串口中断
		PWM_Int(7199,0, 7199,0);		//PWM初始化
	
    while(1)
    { 
			Data_Analyse();//解析串口中断接收的数据
			Car_Function(Car_state);//控制小车不同状态
    }  
}
