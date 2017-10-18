/*
 * PWM1_EKE.c
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */
#include "Timer1.h"

void TIMER1_EKE_init(void)
{
  TCCR1A=(1<<FOC1A); // normal mode as counter only
  TCCR1B=(1<<CS10)|(1<<CS12); // 1024 prescaler
  TCNT1=0;
  ICR1=255;
  // turn off all interrupt
  SREG &=~(1<<7);
  TIFR|=(1<<TOV0);


}

void Timer1_EKE_start(void){
	  TCCR1A=(1<<FOC1A); // normal mode as counter only
	  TCCR1B=(1<<CS10)|(1<<CS12); // 1024 prescaler
	  TCNT1=0;
	  ICR1=255;
}

void Timer1_EKE_stop(void){
	TCCR1A=0;
	TCCR1B=0;
}

U16_t timer1_watch_time(void){
	U16_t time=0,counts=0;
	counts=TCNT1;
	time=(U16_t)(128*counts);

	return time;
}
