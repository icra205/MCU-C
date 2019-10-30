#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int  u16;

sbit led=P2^0;

void Timer0Init()
{
	TMOD|=0x10;
	TH0=0XFC;
	TL0=0x18;
	ET0=1;
	EA=1;
	TR0=1;
}


void main()
{
	Timer0Init();
	while(1);
}

void Time0() interrupt 1
{
	static u16 i;//静态变量也可以是全局变量
	TH0=0XFC;
	TL0=0x18;
	i++;
	if(i==1000)
	{
		i=0;
		led=~led;
	}
}
