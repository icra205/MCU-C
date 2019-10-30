#include <reg52.h>

typedef  unsigned int u16;
typedef  unsigned char u8;

sbit PWN=P2^1;
bit DIR;

u16 count,value,timer1;

void Time1Init()
{
	TMOD|=0X10;
	
	TH1=0XFF;
	TL1=0XFF;//1us
	
	ET1=1;
	EA=1;
	TR1=1;
}

void main()
{
	Time1Init();
	while(1)
	{
		if(count>100)//����ռ�ձ�
		{
			count=0;
			if(DIR==1)//
			{
				value++;
			}
			if(DIR==0)
			{
				value--;
			}
			
			if(value==1000)
			{
				DIR=0;
			}
			if(value==0)
			{
				DIR=1;
			}
			
			if(timer1>1000)//PWN������1000*1us
			{
				timer1=0;
			}
			if(timer1<value)
			{
				PWN=1;
			}
			else
			{
				PWN=0;
			}
		}
	}
}


void Time1(void) interrupt 3
{
	TH1=0XFF;
	TL1=0XFF;//1us
	timer1++;
	count++;
}