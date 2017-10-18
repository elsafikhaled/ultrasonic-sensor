/*
 * ECU.c
 *
 *  Created on: ١٤‏/٠٦‏/٢٠١٧
 *      Author: El-safi
 */
#include "Timer0.h"
#include "Timer1.h"
#include "Timer2.h"
#include "TbUart.h"
#include "PLATFORM_TYPES.h"
#include <util/delay.h>

#define TRIGGER_ON_F  (PORTB |=(1<<PB1))
#define TRIGGER_OFF_F  (PORTB &=~(1<<PB1))

#define TRIGGER_ON_R  (PORTB |=(1<<PB2))
#define TRIGGER_OFF_R  (PORTB &=~(1<<PB2))

#define TRIGGER_ON_L  (PORTB |=(1<<PB4))
#define TRIGGER_OFF_L  (PORTB &=~(1<<PB4))

int main(void){
	//Ultrasonic flags
	DDRD=0xff;
	PORTD=0x00;
	//F Ultrasonic
    FP32_t distance=0;U16_t time_signal=0;
	DDRB|=(1<<PB1);// trigger
	DDRB&=~(1<<PB0);//echo
    TRIGGER_OFF_F;
    // R ultrasonic
    FP32_t distance1=0;U16_t time_signal_1=0;
	DDRB|=(1<<PB2); // trigger
	DDRB&=~(1<<PB3);//echo
    TRIGGER_OFF_R;
    // L ultrasonic
    FP32_t distance2=0;U16_t time_signal_2=0;
	DDRB|=(1<<PB4); // trigger
	DDRB&=~(1<<PB5);//echo
    TRIGGER_OFF_L;
    //system init
	timer0_watch_init();
	TIMER1_EKE_init();
	Timer2_EKE_init();
	TbUart_init();

	while(1){

		TRIGGER_OFF_F;
		_delay_us(15);
	    TRIGGER_ON_F;
	    _delay_us(10);
		TRIGGER_OFF_F;

		while((PINB&(1<<PB0))==0);// wait for echo to be sent
		timer0_watch_start();
		while((PINB&(1<<PB0)));
		timer0_watch_stop();
		time_signal=timer0_watch_time();
		distance=0.017*(float)time_signal;

		TbUart_Send_stri((U8_t*)"distance:");
		TB_intNumASCII(distance);
		TbUart_Send_char('\n');



	    //! ***************************************
		TRIGGER_OFF_R ;
		_delay_us(15);
		TRIGGER_ON_R ;
		_delay_us(10);
		TRIGGER_OFF_R ;

		while((PINB&(1<<PB3))==0);// wait for echo to be sent
		Timer1_EKE_start();
		while((PINB&(1<<PB3)));
		Timer1_EKE_stop();
		time_signal_1=timer1_watch_time();
		distance1=0.017*(float)time_signal_1;

		if(distance1<40){
		PORTD|=(1<<PD1);
		_delay_ms(400);
		PORTD&=~(1<<PD1);
		TbUart_Send_stri((U8_t*)"Right:");
		TB_intNumASCII(distance1);
		TbUart_Send_char('\n');
		}
		else{PORTD&=~(1<<PD1);}
        // ******************************************************
	    TRIGGER_OFF_L ;
	    _delay_us(15);
	    TRIGGER_ON_L ;
	    _delay_us(10);
	    TRIGGER_OFF_L ;

	    while((PINB&(1<<PB5))==0);// wait for echo to be sent
	    Timer2_EKE_start();
	    while((PINB&(1<<PB5)));
	    Timer2_EKE_stop();
	    time_signal_2=timer2_watch_time();
	    distance2=0.017*(float)time_signal_2;

	    if(distance2<40){
	    PORTD|=(1<<PD2);
	    _delay_ms(400);
	    PORTD&=~(1<<PD2);
	    TbUart_Send_stri((U8_t*)"Left:");
	    TB_intNumASCII(distance2);
	    TbUart_Send_char('\n');
	    }
	    else{PORTD&=~(1<<PD2);}




	}


	return 0;
}

