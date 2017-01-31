/*
 * LCD_keypad.c
 *
 * Created: 08-04-2016 21:10:21
 *  Author: RISHABH JAIN
 */ 


#include <avr/io.h>
#include<util/delay.h>

void cmd(unsigned int i)
{
	PORTC=0x00;
	PORTD=i;
	PORTC=0x04;
	_delay_ms(20);
	PORTC=0x00;
}

void data(unsigned char i)
{
	PORTC=0x01;
	PORTD=i;
	PORTC=0x05;
	_delay_ms(20);
	PORTC=0x01;
}

void main()
{
	DDRC=0xFF;
	DDRD=0xFF;
	DDRB=0x0F;
	PORTB=0xF0;
	cmd(0x38);
	_delay_ms(20);
	cmd(0x01);
	_delay_ms(20);
	cmd(0x80);
	_delay_ms(20);
	cmd(0x0E);
	_delay_ms(20);
	int c=0;
    while(1)
    {
        PORTB=0b11111110;
		if(bit_is_clear(PINB,PB4) )
		{
			data('7');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB5) )
		{
			data('8');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB6) )
		{
			data('9');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB7) )
		{
			data('/');
			_delay_ms(500);
			c++;
		}
		
		PORTB=0b11111101;
		if(bit_is_clear(PINB,PB4) )
		{
			data('4');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB5) )
		{
			data('5');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB6) )
		{
			data('6');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB7) )
		{
			data('*');
			_delay_ms(500);
			c++;
		}
		
		PORTB=0b11111011;
		if(bit_is_clear(PINB,PB4) )
		{
			data('1');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB5) )
		{
			data('2');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB6) )
		{
			data('3');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB7) )
		{
			data('-');
			_delay_ms(500);
			c++;
		}
		
		PORTB=0b11110111;
		if(bit_is_clear(PINB,PB4) )
		{
			data('C');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB5) )
		{
			data('0');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB6) )
		{
			data('=');
			_delay_ms(500);
			c++;
		}
		if(bit_is_clear(PINB,PB7) )
		{
			data('+');
			_delay_ms(500);
			c++;
		}
		if(c==16)
		{
			cmd(0xC0);
			_delay_ms(20);
		}
		
		
    }
}