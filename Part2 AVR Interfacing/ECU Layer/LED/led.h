/*
 * led.h
 *
 * Created: 20/10/2023 03:04:29 م
 *  Author: Dell
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL Layer/DIO/dio.h"
#include "../../MCAL Layer/std_types.h"

typedef enum{
	LED_OFF = 0,
	LED_ON
}led_status_t;

typedef enum{
	ACTIVE_LOW = 0,
	ACTIVE_HIGH	
}led_logic_t;

void led_on(dio_portId_t port,dio_channelId_t pin,led_logic_t led_logic);
void led_off(dio_portId_t port,dio_channelId_t pin,led_logic_t led_logic);
void led_flip(dio_portId_t port,dio_channelId_t pin, led_logic_t led_logic);



#endif /* LED_H_ */