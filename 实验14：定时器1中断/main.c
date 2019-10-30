#include<reg52.h>

typedef unsigned char u8;
typedef unsigned int  u16;

sbit led=P2^0;

void Timer1Init()
{
	TMOD|=0x10;
	TH1=0XFC;
	TL1=0x18;
	ET0=1;
	EA=1;
	TR1=1;
}


void main()
{
	Timer1Init();
	while(1);
}

void Time1() interrupt 3
{
	static u16 i;//静态变量也可以是全局变量
	TH1=0XFC;
	TL1=0x18;
	i++;
	if(i==1000)
	{
		i=0;
		led=~led;
	}
}
