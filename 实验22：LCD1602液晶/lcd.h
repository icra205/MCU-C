#ifndef _lcd_H
#define _lcd_H

#include <reg52.h>

#define LCD1602_4PINS

typedef  unsigned int u16;
typedef  unsigned char u8;


#ifndef uchar//????
#define uchar unsigned char
#endif

#ifndef uint//????//???????????
#define uint unsigned int
#endif


#define LCD1602_DATAPINS P0

sbit LCD1602_E=P2^7;
sbit LCD1602_RS=P2^6;
sbit LCD1602_RW=P2^5;

void LCD1602_Delay1ms(u16 c);
void LcdWriteCom (u8 com);
void LcdWriteData(u8 dat);
void LcdInit();
void LcdWriteword(unsigned char *s);

#endif