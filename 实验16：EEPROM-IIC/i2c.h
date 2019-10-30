#ifndef _I2C_H
#define _I2C_H

#include <reg52.h>

sbit SCL=P2^1;
sbit SDA=P2^0;

typedef  unsigned int u16;
typedef  unsigned char u8;


void At24c02Write(u8 addr,u8 dat);
u8 At24c02Read(u8 addr);


#endif