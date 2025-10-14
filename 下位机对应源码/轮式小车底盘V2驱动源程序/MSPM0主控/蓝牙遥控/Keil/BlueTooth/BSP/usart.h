#ifndef	__USART_H__
#define __USART_H__

#include "ti_msp_dl_config.h"

#define RE_0_BUFF_LEN_MAX	128

extern volatile uint8_t  recv0_buff[RE_0_BUFF_LEN_MAX];
extern volatile uint16_t recv0_length;
extern volatile uint8_t  recv0_flag;
extern uint8_t Car_state;

void USART_Init(void);

static void USART_SendData(unsigned char data);
void UART_Servo(unsigned char servonum,unsigned char angle);



#endif
