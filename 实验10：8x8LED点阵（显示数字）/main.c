#include<reg51.h>
#include<intrins.h>

typedef unsigned char u8;
typedef unsigned int  u16;

sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;//可能是4位

u8 led_duan[]={0x00,0x00,0x3e,0x41,0x41,0x41,0x3e,0x00};
u8 led_wei []={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};


void delay(u16 i)
{
	while(i--);
}



void Hc595SendByte(u8 dat)
{
	u8 a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;
		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;
	}
	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}

void main ()
{
	u8 i;
	
	while(1)
	{
		P0=0x7f;
		for(i=0;i<8;i++)
		{
			P0=led_wei [i];
			Hc595SendByte(led_duan[i]);
			delay(100);
			Hc595SendByte(0x00);
		}
	}

}
	
