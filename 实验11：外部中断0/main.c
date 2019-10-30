#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int  u16;

sbit led=P2^0;
sbit k3 =P3^2;

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

void Int0() interrupt 0
{
	delay(1000);
	if(k3==0)
	{
		led=~led;
	}
}