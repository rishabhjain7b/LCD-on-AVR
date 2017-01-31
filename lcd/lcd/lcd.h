/*
 * lcd.h
 *
 * Created: 20-04-2016 15:05:31
 *  Author: RISHABH JAIN
 */ 


#ifndef LCD_H_
#define LCD_H_
#include<avr/io.h>
#include<util/delay.h>
void cmd(unsigned char d);
void data(unsigned char d);
void lcd_init();
void lcd_string(unsigned char *p);
void lcd_goto(unsigned int x,unsigned int y);
#endif /* LCD_H_ */