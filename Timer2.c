/*
 * Timer2.c
 *
 *  Created on: ١٤‏/٠٦‏/٢٠١٧
 *      Author: El-safi
 */
#include "Timer2.h"

void Timer2_EKE_init(void){
	TCCR2=(1<<FOC2)|(1<<CS20)|(1<<CS21)|(1<<CS22); // prescaler 1024
	TCNT2=0;

// turn off all interrupt
    SREG &=~(1<<7);
	TIFR|=(1<<TOV0);

}

void Timer2_EKE_start(void){
	TCCR2=(1<<FOC2)|(1<<CS20)|(1<<CS21)|(1<<CS22); // prescaler 1024
	TCNT2=0;
}



void Timer2_EKE_stop(void){

	TCCR2=0;
}

U16_t timer2_watch_time(void){
	U16_t time=0,counts=0;
	counts=TCNT2;
	time=(U16_t)(128*counts);

	return time;

}
