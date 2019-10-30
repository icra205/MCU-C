#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int  u16;

sbit led=P2^0;
sbit k4 =P3^3;

void delay(u16 i)
{
	while(i--);
}

void Int0Init() 
{
	IT0=1;
	EX0=1;
	EA=1;
}


void main()
{
	Int0Init();//÷–∂œ≥ı ºªØ
	while(1);
}

void Int0() interrupt 2
{
	delay(1000);
	if(k4==0)
	{
		led=~led;
	}
}