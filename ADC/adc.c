/*
 * adc.c
 *
 *  Created on: 19 maj 2015
 *      Author: Grzegorz £agocki
 */


#include "adc.h"

uint8_t samples = 4;
uint16_t average;

void ADC_Init()
{
	ADC_COILV_DDR &= ~(1 << ADC_COILV); // PWM pin
	ADC_COILV_PORT |= (1 << ADC_COILV); // to VCC

	ADC_COILA_DDR &= ~(1 << ADC_COILV); // PWM pin
	ADC_COILA_PORT |= (1 << ADC_COILV); // to VCC

	ADC_BATT_DDR &= ~(1 << ADC_BATT); // PWM pin
	ADC_BATT_PORT |= (1 << ADC_BATT); // to VCC


	ADMUX |= (1<<REFS0) | (1<<REFS1); // Select Vref = 1.1V
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //set prescaller to 128
	ADCSRA |= (1<<ADEN); //  enable ADC
}


uint16_t ADC_Read(uint8_t channel)
{
	 //select ADC channel with safety mask
	 ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	 //single conversion mode
	 ADCSRA |= (1<<ADSC);
	 // wait until ADC conversion is complete
	 while( ADCSRA & (1<<ADSC) );
	 return ADC;
}

uint32_t GetVoltage(uint8_t channel)
{
	average *= samples;
	average += ADC_Read(channel);
	average /= (samples + 1);

	return (average * 275UL)/600UL;
}


