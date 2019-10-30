#ifndef _temp_H
#define _temp_H

#include <reg52.h>

sbit DSPORT=P3^7;

typedef  unsigned int u16;
typedef  unsigned char u8;


#ifndef uchar//条件编译
#define uchar unsigned char
#endif

#ifndef uint//条件编译//未定义会进行不然是不会
#define uint unsigned int
#endif

int Ds18b20ReadTemp();


#endif