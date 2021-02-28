/*
 * UART_prog.c
 *
 *  Created on: Sep 28, 2018
 *  Author: Abdulnaser
 */
#include "LIB/std_types.h"
#include "LIB/util.h"
#include "UART_interface.h"
#include "DIO_interface.h"
#include "avr/io.h"



void UART_vidInit(void)
{
	UBRRL = 77;
	UCSRC = (1<<7)|0x06;
	UCSRB = 0x18;

}
void UART_SendChar(u8 Data)
{
	while(GET_BIT(UCSRA,UDRE)!=1 );
	UDR = Data;
}
u8   UART_RecieveChar(void)
{
	while(GET_BIT(UCSRA,RXC) == 0);
	return UDR;
	SET_BIT(UCSRA,7);
}

