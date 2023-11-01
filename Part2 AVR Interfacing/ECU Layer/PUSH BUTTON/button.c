/*
 * button.c
 *
 * Created: 20/10/2023 08:39:32 م
 *  Author: Dell
 */ 
#include "button.h"

void button_init(){
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN7,INPUT);
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN6,INPUT);
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN5,INPUT);
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN3,INPUT);
	dio_vidConfigChannel(DIO_PORTD,DIO_PIN2,INPUT);
}

button_status_t button_getStatus(button_id_t buttonId){
	button_status_t button_stat = BUTTON_RELEASED;
	switch(buttonId){
		case BUTTON1:
			if(dio_dioLevelReadChannel(DIO_PORTD,DIO_PIN7) == STD_LOW){
				button_stat = BUTTON_PRESSED;
			}
			else{
				button_stat = BUTTON_RELEASED;
			}
			break;
		case BUTTON2:
			if(dio_dioLevelReadChannel(DIO_PORTD,DIO_PIN6) == STD_LOW){
				button_stat = BUTTON_PRESSED;
			}
			else{
				button_stat = BUTTON_RELEASED;
			}
			break;
		case BUTTON3:
			if(dio_dioLevelReadChannel(DIO_PORTD,DIO_PIN5) == STD_LOW){
				button_stat = BUTTON_PRESSED;
			}
			else{
				button_stat = BUTTON_RELEASED;
			}
			break;	
		case BUTTON4:
			if(dio_dioLevelReadChannel(DIO_PORTD,DIO_PIN3) == STD_LOW){
				button_stat = BUTTON_PRESSED;
			}
			else{
				button_stat = BUTTON_RELEASED;
			}
			break;
		default: /* Nothing */
			break; 				
	}
	return button_stat;
}
