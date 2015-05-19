/*
 * adc.h
 *
 *  Created on: 19 maj 2015
 *      Author: Grzegorz £agocki
 */


#ifndef ADC_ADC_H_
#define ADC_ADC_H_


#include <avr/io.h>


//------------------------------------------------------------------------------
//	I/O pin-port configuration:
//------------------------------------------------------------------------------

#define ADC_COILV       PD6
#define ADC_COILV_DDR   DDRD
#define ADC_COILV_PORT  PORTD

#define ADC_COILA       0
#define ADC_COILA_DDR   DDRD
#define ADC_COILA_PORT  PORTD

#define ADC_BATT        0
#define ADC_BATT_DDR    DDRD
#define ADC_BATT_PORT   PORTD

//------------------------------------------------------------------------------
//	Macro definitions:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//	Variable declaration:
//------------------------------------------------------------------------------

enum adc
{
	coil_voltage = 5,
	coil_current,
	battery_voltage
};

//------------------------------------------------------------------------------
//	Function declaration:
//------------------------------------------------------------------------------

void ADC_Init();
uint16_t ADC_Read(uint8_t channel);
uint32_t GetVoltage(uint8_t channel);


#endif /* ADC_ADC_H_ */
