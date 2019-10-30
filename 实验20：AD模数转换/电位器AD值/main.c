#include <reg52.h>
#include <XPT2046.h>



sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 disp[4];
u8 code smgduan[]={0x3f,0x06,0x5b, 0x4f , 0x66 , 0x6d ,0x7d , 0x07 , 0x7f  , 0x6f , 0x77 , 0x7c ,0x39 , 0x5e , 0x79 , 0x71 , 0x00};
//0~9 A~D ???

void delay(u16 i)
{
	while(i--);
}


void datapros()
{
	u16 temp;
	static u8 i;
	if(i==50)
	{
		i=0;
		temp = Read_AD_Data(0x94);
	}
	i++;
	disp[0]=smgduan[temp/1000];
	disp[1]=smgduan[temp%1000/100];
	disp[2]=smgduan[temp%1000%100/10];
	disp[3]=smgduan[temp%1000%100%10];
	
}


void DigDisplay()
{
	u8 i;
	for(i=0;i<4;i++)
	{
		switch(i)
		{
			case 0:
				    LSA=0;LSB=0;LSC=0;break;//?????
			case 1:
				    LSA=1;LSB=0;LSC=0;break;//?????
			case 2:
				    LSA=0;LSB=1;LSC=0;break;//???
			case 3:
				    LSA=1;LSB=1;LSC=0;break;//???
			
		}	
		P0=disp[3-i];
		delay(100);//?????50???
		P0=0x00;//??
		
	}
}



void main()
{
	while(1)
	{
		datapros();
		DigDisplay();
	}
}