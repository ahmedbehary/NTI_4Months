/* 
 * File:   app.c
 * Author: Dell
 *
 * Created on 24 Nov, 2023, 04:11 ?
 */
#include "app.h"
#include "C:\Program Files\Microchip\MPLABX\v6.10\packs\Microchip\PIC18Fxxxx_DFP\1.4.151\xc8\pic\include\builtins.h"
void application_initaialize(void);
void timer0_isr(void);
void create_task(unsigned int priority, unsigned int periodicity, void (*Handler)(void),unsigned int first_delay, Task_status_t status );
void suspend_task(Task_t task);
void delete_task(Task_t task);
void resume_task(Task_t task);
void start_os(void);

led_t led1 = {
    .pin = PIN0_INDEX, .port = PORTD_INDEX, .status = LED_OFF
};

timer0_t timer0 = {
    .callback_fun = timer0_isr,
    .clock_source = TIMER0_TIMER_MODE,
    .preload_value = 15536,
    .prescale_value = TIMER0_PRESCALE_4,
    .prescaler_enable = PRESCALER_ENABLE,
    .source_edge = TIMER0_RISING_EDGE,
    .timer0_reg_size = TIMER0_8_REGISTER
};

Task_t task[3];

void task1(void){
    led_off(&led1);
}

void task2(void){
    led_on(&led1);
}

void task3(void){
    led_off(&led1);
}

int main(){
    Std_ReturnType ret = E_NOT_OK;
    application_initaialize();
    create_task(0,20,task1,0,READY_STATE);
    create_task(1,30,task2,1,READY_STATE);
    create_task(2,50,task3,2,READY_STATE);
    start_os();  
    while(1){
        
    }
    return (EXIT_SUCCESS);    
}

void application_initaialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ret = led_initialize(&led1);
}

void timer0_isr(void){
    static unsigned int tick = 0;
    unsigned int i = 0;
    tick++;
    for(i = 0; i < 3; i++){
        if((tick % task[i].periodicity) - task[i].first_delay == 0){
            task[i].Handler();
        }
    }
}

void create_task(unsigned int priority, unsigned int periodicity, void (*Handler)(void),
                        unsigned int first_delay, Task_status_t status){
    task[priority].Handler = Handler;
    task[priority].periodicity = periodicity;
    task[priority].first_delay = first_delay;
    task[priority].status = status;
}

void start_os(void){
    Std_ReturnType ret = E_NOT_OK;
    timer0_init(&timer0);
}

void suspend_task(Task_t task){
    task.status = WAITING_STATE;
}

void delete_task(Task_t task){
    task.status = DORMENT_STATE;
}

void resume_task(Task_t task){
    task.status = READY_STATE;
}