#ifndef _XPT2046_H
#define _XPT2046_H

#include <reg52.h>
#include <intrins.h>


typedef  unsigned int u16;
typedef  unsigned char u8;


#ifndef uchar//????
#define uchar unsigned char
#endif

#ifndef uint//????//???????????
#define uint unsigned int
#endif

#ifndef ulong//????//???????????
#define ulong unsigned long
#endif

sbit DOUT=P3^7;
sbit CLK=P3^6;
sbit DIN=P3^4;
sbit CS=P3^5;


u16 Read_AD_Data(u8 cmd);


#endif