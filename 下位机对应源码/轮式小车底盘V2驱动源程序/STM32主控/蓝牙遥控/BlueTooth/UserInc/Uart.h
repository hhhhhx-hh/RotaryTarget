#ifndef __UART_H__
#define __UART_H__

#include "stm32f10x.h"
#include "stdio.h"

extern uint8_t rxd_flag;
extern uint8_t rxd_index;
extern uint8_t rxd_buf[60];
extern uint8_t Car_state;

void Uart1_Configuration(void);
void Uart1_NVIC_Configuration(void);
 
int fputc (int c, FILE *pt);
int fgetc(FILE *pt);

#endif
