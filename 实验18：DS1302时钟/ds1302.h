#ifndef _ds1302_H
#define _ds1302_H

#include <reg52.h>
#include <intrins.h>

sbit DSIO=P3^4;
sbit RST=P3^5;
sbit SCLK=P3^6;


typedef  unsigned int u16;
typedef  unsigned char u8;


#ifndef uchar//
#define uchar unsigned char
#endif

#ifndef uint//
#define uint unsigned int
#endif

void Ds1302Write(u8 addr,u8 dat);
u8 Ds1302Read(u8 addr);
void Ds1302Init();
void Ds1302ReadTime();


extern u8  TIME[7];
//加入全局变量



#endif