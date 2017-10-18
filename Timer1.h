/*
 * PWM1_EKE.h
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */

#ifndef PWM1_EKE_H_
#define PWM1_EKE_H_


#include <avr/io.h>
#include"std_data_types_EKE.h"



void TIMER1_EKE_init(void);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM1_EKE_init(void);
 *
 * Parameters  :: void
 *
 * Description :: Timer1 initialization for FAST PWM AND non  INVERTING MODE, 16 Bits, 1024 prescaler
 *
 * Return      :: void
 *
 * *******************************************************************************************************/




void Timer1_EKE_start(void);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM1_EKE_start(void);
 *
 * Parameters  :: void
 *
 * Description :: Timer1 start
 *
 * Return      :: void
 *
 * *******************************************************************************************************/
void Timer1_EKE_stop(void);
/* ************************************** system initialization *******************************************
 *
 * FUNCTION    :: void PWM1_EKE_stop(void);
 *
 * Parameters  :: void
 *
 * Description :: Timer1  stop
 *
 * Return      :: void
 *
 * *******************************************************************************************************/
U16_t timer1_watch_time(void);




#endif /* PWM1_EKE_H_ */
