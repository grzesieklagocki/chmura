/*
 * init.c
 *
 *  Created on: 19 maj 2015
 *      Author: Grzegorz £agocki
 */


#include "init.h"

//------------------------------------------------------------------------------
//	Init all components
//------------------------------------------------------------------------------

void InitAll()
{
	TIMER2_10ms_Init();

	ADC_Init();

	PWM_Enable();

	lcd_init();
	lcd_str("pwm: ");
	lcd_locate(1, 0);
	lcd_str("adc: ");
}


