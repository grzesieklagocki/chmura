/*
 * timer2.h
 *
 *  Created on: 30 lis 2014
 *      Author: Grzegorz £agocki
 */


#ifndef LCD_TEST_TIMER2_TIMER2_H_
#define LCD_TEST_TIMER2_TIMER2_H_


#include <avr/io.h>


//------------------------------------------------------------------------------
//	I/O pin-port configuration:
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//	Macro definitions:
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
//	Variable declaration:
//------------------------------------------------------------------------------

extern volatile uint8_t flag_TIMER2_tick;
extern volatile uint8_t timer;

//------------------------------------------------------------------------------
//	Function declaration:
//------------------------------------------------------------------------------

void TIMER2_10ms_Init(void);

inline void TIMER2_10ms_SysTick(void) __attribute__((always_inline));
inline void TIMER2_10ms_SysTick(void)
{
	if(flag_TIMER2_tick)
	{

		if(timer) --timer;

		flag_TIMER2_tick = 0;
	}

}


#endif /* LCD_TEST_TIMER2_TIMER2_H_ */
