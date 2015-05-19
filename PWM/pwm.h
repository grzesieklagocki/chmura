/*
 * pwm.h
 *
 *  Created on: 19 maj 2015
 *      Author: Grzegorz �agocki
 */


#ifndef PWM_PWM_H_
#define PWM_PWM_H_


#include <avr/io.h>


//------------------------------------------------------------------------------
//	I/O pin-port configuration:
//------------------------------------------------------------------------------

#define PWM PD6
#define PWM_DDR DDRD

//------------------------------------------------------------------------------
//	Macro definitions:
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//	Variable declaration:
//------------------------------------------------------------------------------

extern uint8_t pwm;

//------------------------------------------------------------------------------
//	Function declaration:
//------------------------------------------------------------------------------

void PWM_Enable();
void PWM_Disable();

void PWM_Correct(uint8_t vv, uint16_t voltage);


#endif /* PWM_PWM_H_ */
