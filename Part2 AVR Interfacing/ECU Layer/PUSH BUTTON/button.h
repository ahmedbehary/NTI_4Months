/*
 * button.h
 *
 * Created: 20/10/2023 08:39:02 م
 *  Author: Dell
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL Layer/DIO/dio.h"
#include "../../MCAL Layer/std_types.h"

typedef enum{
	BUTTON_PRESSED = 0,
	BUTTON_RELEASED	
}button_status_t;

typedef enum{
	BUTTON_LOW = 0,
	BUTTON_HIGH	
}button_active_t;

typedef enum
{
	BUTTON1,
	BUTTON2,
	BUTTON3,
	BUTTON4
}button_id_t;

void button_init();
button_status_t button_getStatus(button_id_t buttonId);


#endif /* BUTTON_H_ */