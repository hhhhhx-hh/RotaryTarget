#include "ti_msp_dl_config.h"
#include "delay.h"
#include "usart.h"
#include "usart.h"
#include "Motor.h"


int main(void)
{
    USART_Init();
    while (1)
	{
		Data_Analyse();//解析串口中断接收的数据	Parsing data received by serial port interrupt
		Car_Function(Car_state);//控制小车不同状态	Control the car in different states
    }
}
