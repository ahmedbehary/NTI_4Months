/*
 * led.c
 *
 * Created: 20/10/2023 03:04:43 م
 *  Author: Dell
 */ 
#include "led.h"

void led_on(dio_portId_t port,dio_channelId_t pin,led_logic_t led_logic){
	dio_vidConfigChannel(port,pin,OUTPUT);
	if(led_logic == ACTIVE_LOW){
		switch (port)
		{
			case DIO_PORTA:
				dio_vidWriteChannel(DIO_PORTA,pin,STD_LOW);
				break;
			case DIO_PORTB:
				dio_vidWriteChannel(DIO_PORTB,pin,STD_LOW);
				break;
			case DIO_PORTC:
				dio_vidWriteChannel(DIO_PORTC,pin,STD_LOW);
				break;
			case DIO_PORTD:
				dio_vidWriteChannel(DIO_PORTD,pin,STD_LOW);
				break;			
		}
	}
	else if(led_logic == ACTIVE_HIGH){
		switch (port)
		{
			case DIO_PORTA:
			dio_vidWriteChannel(DIO_PORTA,pin,STD_HIGH);
			break;
			case DIO_PORTB:
			dio_vidWriteChannel(DIO_PORTB,pin,STD_HIGH);
			break;
			case DIO_PORTC:
			dio_vidWriteChannel(DIO_PORTC,pin,STD_HIGH);
			break;
			case DIO_PORTD:
			dio_vidWriteChannel(DIO_PORTD,pin,STD_HIGH);
			break;
		}
	}
	else{/* Nothing */}
}

void led_off(dio_portId_t port,dio_channelId_t pin, led_logic_t led_logic){
	dio_vidConfigChannel(port,pin,OUTPUT);
	if(led_logic == ACTIVE_LOW){
		switch (port)
		{
			case DIO_PORTA:
			dio_vidWriteChannel(DIO_PORTA,pin,STD_HIGH);
			break;
			case DIO_PORTB:
			dio_vidWriteChannel(DIO_PORTB,pin,STD_HIGH);
			break;
			case DIO_PORTC:
			dio_vidWriteChannel(DIO_PORTC,pin,STD_HIGH);
			break;
			case DIO_PORTD:
			dio_vidWriteChannel(DIO_PORTD,pin,STD_HIGH);
			break;
		}
	}
	else if(led_logic == ACTIVE_HIGH){
		switch (port)
		{
			case DIO_PORTA:
			dio_vidWriteChannel(DIO_PORTA,pin,STD_LOW);
			break;
			case DIO_PORTB:
			dio_vidWriteChannel(DIO_PORTB,pin,STD_LOW);
			break;
			case DIO_PORTC:
			dio_vidWriteChannel(DIO_PORTC,pin,STD_LOW);
			break;
			case DIO_PORTD:
			dio_vidWriteChannel(DIO_PORTD,pin,STD_LOW);
			break;
		}
	}
	else{/* Nothing */}
}

void led_flip(dio_portId_t port,dio_channelId_t pin, led_logic_t led_logic){
	dio_vidConfigChannel(port,pin,OUTPUT);
	switch (port)
	{
		case DIO_PORTA:
		dio_vidFlipChannel(DIO_PORTA,pin);
		break;
		case DIO_PORTB:
		dio_vidFlipChannel(DIO_PORTB,pin);
		break;
		case DIO_PORTC:
		dio_vidFlipChannel(DIO_PORTC,pin);
		break;
		case DIO_PORTD:
		dio_vidFlipChannel(DIO_PORTD,pin);
		break;
	}
}
