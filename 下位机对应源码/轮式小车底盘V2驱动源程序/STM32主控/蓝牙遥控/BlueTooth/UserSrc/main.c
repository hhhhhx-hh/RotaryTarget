#include "stm32f10x.h" 
#include "SysTick.h"
#include "Uart.h"
#include "bsp_motor_iic.h"
#include "Motor.h"

#define MOTOR_TYPE 2   //1:520电机 2:310电机 3:测速码盘TT电机 4:TT直流减速电机 5:L型520电机
                       //1:520 motor 2:310 motor 3:speed code disc TT motor 4:TT DC reduction motor 5:L type 520 motor

int main(void)
{    
    delay_init();		//配置定时器	Configure the timer
    Uart1_Configuration();			//配置UART1串口	Configure UART1 serial port
    Uart1_NVIC_Configuration();	//配置UART1串口中断	Configure UART1 serial port interrupt

    IIC_Motor_Init();
    
    #if MOTOR_TYPE == 1
	Set_motor_type(1);//配置电机类型	Configure motor type
	delay_ms(100);
	Set_Pluse_Phase(30);//配置减速比 查电机手册得出	Configure the reduction ratio. Check the motor manual to find out
	delay_ms(100);
	Set_Pluse_line(11);//配置磁环线 查电机手册得出	Configure the magnetic ring wire. Check the motor manual to get the result.
	delay_ms(100);
	Set_Wheel_dis(67.00);//配置轮子直径,测量得出		Configure the wheel diameter and measure it
	delay_ms(100);
	Set_motor_deadzone(1600);//配置电机死区,实验得出	Configure the motor dead zone, and the experiment shows
	delay_ms(100);
    
    #elif MOTOR_TYPE == 2
    Set_motor_type(2);
	delay_ms(100);
	Set_Pluse_Phase(20);
	delay_ms(100);
	Set_Pluse_line(13);
	delay_ms(100);
	Set_Wheel_dis(48.00);
	delay_ms(100);
	Set_motor_deadzone(1300);
	delay_ms(100);
    
    #elif MOTOR_TYPE == 3
    Set_motor_type(3);
	delay_ms(100);
	Set_Pluse_Phase(45);
	delay_ms(100);
	Set_Pluse_line(13);
	delay_ms(100);
	Set_Wheel_dis(68.00);
	delay_ms(100);
	Set_motor_deadzone(1250);
	delay_ms(100);
    
    #elif MOTOR_TYPE == 4
    Set_motor_type(4);
	delay_ms(100);
	Set_Pluse_Phase(48);
	delay_ms(100);
	Set_motor_deadzone(1000);
	delay_ms(100);
    
    #elif MOTOR_TYPE == 5
    Set_motor_type(1);
	delay_ms(100);
	Set_Pluse_Phase(40);
	delay_ms(100);
	Set_Pluse_line(11);
	delay_ms(100);
	Set_Wheel_dis(67.00);
	delay_ms(100);
	Set_motor_deadzone(1600);
	delay_ms(100);
    #endif
        
    while(1)
    { 
			Data_Analyse();//解析串口中断接收的数据	Analyze data received by the serial port interrupt
			Car_Function(Car_state);//控制小车不同状态	Control different states of the car
    }  
}
