/*
 * lcd.c
 *
 * Created: 16-04-2016 17:43:52
 *  Author: RISHABH JAIN
 */ 

#include <avr/io.h>
#include "lcd.h"
#include <util/delay.h>
#define lcd_data PORTD
#define rs PC0
#define rw PC1
#define en PC2
#define control PORTC

void cmd(unsigned char d)
{
	
	 lcd_data=d;
	 control=(0<<rs)|(0<<rw)|(1<<en);
	 _delay_ms(20);
	 control=(0<<rs)|(0<<rw)|(0<<en);
}

void data(unsigned char d)
{
	
	lcd_data=d;
	control=(1<<rs)|(0<<rw)|(1<<en);
	_delay_ms(20);
	control=(1<<rs)|(0<<rw)|(0<<en);
}

void lcd_init()
{
	cmd(0x38);
	_delay_ms(10);
	cmd(0x01);
	_delay_ms(10);
	cmd(0x0F);
	_delay_ms(10);
	cmd(0x80);
	_delay_ms(10);
}

void lcd_string(unsigned char *p)
{
	while(*p!='\0')
	{
		data(*p);
		_delay_ms(10);
		p++;
	}
}

void lcd_goto(unsigned int x,unsigned int y)
{
	int a[]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F};
	int b[]={0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0xC7,0xC8,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF};
    
	if(y==0)
	cmd(b[x]);
	if(x==0)
	cmd(a[x]);	
}
