/*
 * Timer0.c
 *
 *  Created on: ٣١‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */
#include "Timer0.h"

void timer0_watch_init(void){

	TCCR0|=(1<<FOC0)|(1<<CS00)|(1<<CS02); //1024 prescaler / normal mode
	TCNT0=0;
	SREG &=~(1<<7);
	TIFR|=(1<<TOV0);

}
void timer0_watch_start(void){
	TCCR0|=(1<<FOC0)|(1<<CS00)|(1<<CS02); //1024 prescaler / normal mode
	TCNT0=0;
}

void timer0_watch_stop(void){

	TCCR0&=0b10000000;
}


U16_t timer0_watch_time(void){
	U16_t time=0,counts=0;
	counts=TCNT0;
	time=(U16_t)(128*counts);

	return time;
}


