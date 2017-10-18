/*
 * Timer2.h
 *
 *  Created on: ١٤‏/٠٦‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef TIMER2_H_
#define TIMER2_H_
#include <avr/io.h>
#include "std_data_types_EKE.h"

void Timer2_EKE_init(void);

void Timer2_EKE_start(void);

void Timer2_EKE_stop(void);

U16_t timer2_watch_time(void);


#endif /* TIMER2_H_ */
