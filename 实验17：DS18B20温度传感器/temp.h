#ifndef _temp_H
#define _temp_H

#include <reg52.h>

sbit DSPORT=P3^7;

typedef  unsigned int u16;
typedef  unsigned char u8;


#ifndef uchar//��������
#define uchar unsigned char
#endif

#ifndef uint//��������//δ�������в�Ȼ�ǲ���
#define uint unsigned int
#endif

int Ds18b20ReadTemp();


#endif