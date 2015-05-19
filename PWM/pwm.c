/*
 * pwm.c
 *
 *  Created on: 19 maj 2015
 *      Author: Grzegorz £agocki
 */


#include "pwm.h"

#include <avr/io.h>

//------------------------------------------------------------------------------
//	Variable definition:
//------------------------------------------------------------------------------

uint8_t pwm;

//------------------------------------------------------------------------------
//	Function definition:
//------------------------------------------------------------------------------

void PWM_Enable()
{
	PWM_DDR |= (1 << PWM);

	TCCR0A |= (1<<WGM01) | (1<<WGM00); // Fast PWM
	TCCR0A |= (1<<COM0A1) | (1<<COM0A0); // Fast PWM Mode
	TCCR0B |= (1<<CS00); // Preskaler = 1
	OCR0A=200; // ustawienie diody na ok 50%

}

void PWM_Disable()
{
	TCCR0A &= ~(1<<WGM01) & ~(1<<WGM00); // Fast PWM
	TCCR0A &= ~(1<<COM0A1) & ~(1<<COM0A0); // Fast PWM Mode
	TCCR0B &= ~(1<<CS00); // Presklarer = 1
	OCR0A=0;
}

void PWM_Correct(uint8_t vv, uint16_t voltage)
{
	if (voltage > vv && pwm < 255) pwm++;
	if (voltage < vv && pwm > 0) pwm--;

	OCR0A = pwm;
}
