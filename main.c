/*
 * main.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Abdulnaser
 */
#include"LIB/std_types.h"
#include"LIB/util.h"
#include"DIO_interface.h"
#include<util/delay.h>
#include"UART_interface.h"
#include <avr/io.h>

#define FORWARD 0x0A
#define BACKWARD 0x05
#define LEFT 0x06
#define RIGHT 0x09
void main(void)
{
	u8 flag = 0;
	UART_vidInit();
	DIO_VidSetPortDirection(DIO_u8PORTA,0xff);


	while(1)
	{
		flag = UART_RecieveChar();


		switch(flag)
		{
		case 'F':
			DIO_VidSetPortValue(DIO_u8PORTA,FORWARD);
			break;
		case 'B':
			DIO_VidSetPortValue(DIO_u8PORTA,BACKWARD);
			break;
		case 'L':
			DIO_VidSetPortValue(DIO_u8PORTA,LEFT);
			break;
		case 'R':
			DIO_VidSetPortValue(DIO_u8PORTA,RIGHT);
			break;
		case 'S':
			DIO_VidSetPortValue(DIO_u8PORTA,0x00);
			break;
		}


	}
}
