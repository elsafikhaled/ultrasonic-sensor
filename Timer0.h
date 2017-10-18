/*
 * Timer0.h
 *
 *  Created on: ٣١‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef TIMER0_H_
#define TIMER0_H_
#include <avr/io.h>
#include <util/delay.h>
#include "std_data_types_EKE.h"

void timer0_watch_init(void);

void timer0_watch_start(void);

void timer0_watch_stop(void);

U16_t timer0_watch_time(void);



#endif /* TIMER0_H_ */
