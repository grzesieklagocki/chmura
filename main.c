#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#include "init.h"


uint8_t key_lock[2];
uint16_t vv = 210;
char cz_d[3], cz_u[3];


void key_push_up(uint8_t * klock, volatile uint8_t * KPIN, uint8_t key_mask, void (*kfun)(void) );
void vv_dec();
void vv_inc();
void show_vv();
void fire();


int main(void)
{
	//init

	DDRD &= ~(1<<PD5);
	PORTD |= (1<<PD5);

	DDRB &= ~(1<<PB6);
	PORTB |= (1<<PB6);

	DDRB &= ~(1<<PB7);
	PORTB |= (1<<PB7);

	InitAll();

	sei();
	while(1)
	{
		TIMER2_10ms_SysTick();

		if (KEY_FIRE_PRESSED) fire();
		else
		{
			PWM_Disable();
			PORTD &= ~(1<<PD6);
			lcd_cls();
			show_vv();
			while(!KEY_FIRE_PRESSED)
			{
				key_push_up( key_lock, &KEY_DOWN_PIN, KEY_DOWN, vv_dec );
				key_push_up( &(key_lock[1]), &KEY_UP_PIN, KEY_UP, vv_inc );
				TIMER2_10ms_SysTick();
			}
			PWM_Enable();
			lcd_cls();
		}
	}
}

void fire()
{

	PWM_Correct(vv, GetVoltage(coil_voltage));

	if(!timer)
	{
		timer = 25;

		div_t divmod = div(GetVoltage(coil_voltage), 100);
		itoa(divmod.quot, cz_d, 10);
		itoa(divmod.rem, cz_u, 10);
		if(divmod.rem < 10) { cz_u[0] = '0'; cz_u[1] = divmod.rem + '0'; }

		lcd_locate(1, 5);
		lcd_int(ADC_Read(coil_voltage));
		lcd_str("   ");

		lcd_locate(1, 10);
		lcd_str(cz_d);
		lcd_char('.');
		lcd_str(cz_u);
		lcd_str("V  ");

		lcd_locate(0, 5);
		lcd_int(pwm);
		lcd_str("   ");
	}

}

void vv_dec()
{
	if (vv > 159) vv -= 10;
	show_vv();
}

void vv_inc()
{
	if (vv < 271) vv += 10;
	show_vv();
}

void key_push_up(uint8_t * klock, volatile uint8_t * KPIN, uint8_t key_mask, void (*kfun)(void))
{
	register uint8_t key_press = (*KPIN & key_mask);

	if( !*klock && !key_press ) *klock=1;
	else if( *klock && key_press )
		if( !++*klock )
			if(kfun) kfun();
}

void show_vv()
{
	div_t divmod = div(vv, 100);
	itoa(divmod.quot, cz_d, 10);
	itoa(divmod.rem, cz_u, 10);
	if(divmod.rem < 10) { cz_u[0] = '0'; cz_u[1] = divmod.rem + '0'; }

	lcd_cls();
	lcd_str("Voltage: ");
	lcd_str(cz_d);
	lcd_char('.');
	lcd_str(cz_u);
	lcd_str("V  ");
}
