/*
 * timer2.c
 *
 *  Created on: 30 lis 2014
 *      Author: Grzegorz £agocki
 */


#include "timer2.h"

#include <avr/interrupt.h>


//------------------------------------------------------------------------------
//	Variable definition:
//------------------------------------------------------------------------------

volatile uint8_t flag_TIMER2_tick = 0;
volatile uint8_t timer;

//------------------------------------------------------------------------------
//	Function definition:
//------------------------------------------------------------------------------

void TIMER2_10ms_Init(void)
{
	TCCR2A |= (1<<WGM21); // tryb CTC
	TCCR2B |= (1<<CS20) | (1<<CS21) | (1<<CS22); // prescaler 1024

	OCR2A = 77; // przerwanie co 10ms

	TIMSK2 |= (1<<OCIE2A); // zezwolenie na przerwanie timera2
}

ISR( TIMER2_COMPA_vect )
{
	flag_TIMER2_tick = 1;
}
