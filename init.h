/*
 * init.h
 *
 *  Created on: 19 maj 2015
 *      Author: Grzegorz £agocki
 */


#ifndef INIT_H_
#define INIT_H_


#include <avr/io.h>

#include "HD44780/HD44780.h"
#include "TIMER2/timer2.h"
#include "PWM/pwm.h"
#include "ADC/adc.h"

//------------------------------------------------------------------------------
//	I/O pin-port configuration:
//------------------------------------------------------------------------------

	#define KEY_DOWN      (1<<PB6)
	#define KEY_DOWN_PIN  PINB

	#define KEY_UP        (1<<PB7)
	#define KEY_UP_PIN    PINB

	#define KEY_FIRE      PD5
	#define KEY_FIRE_PIN  PIND

//------------------------------------------------------------------------------
//	Macro definitions:
//------------------------------------------------------------------------------

#define KEY_FIRE_PRESSED  ( !( KEY_FIRE_PIN & (1 << KEY_FIRE) ) )

//------------------------------------------------------------------------------
//	Variable declaration:
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//	Function declaration:
//------------------------------------------------------------------------------

void InitAll();


#endif /* INIT_H_ */
