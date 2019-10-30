/***************************************************
        DS1302实验
				
		数码管显示时钟数据

****************************************************/

#include<reg52.h>
#include<ds1302.h>



sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;



char num=0;
u8 DisplayData[8];
u8 code smgduan[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};



void delay(u16 i)
{
 while(i--);
}


void datapros()//数据处理函数
{
	Ds1302ReadTime();
	DisplayData[0]=smgduan[TIME[2]/16];
	DisplayData[1]=smgduan[TIME[2]&0x0f];
  DisplayData[2]=0x40;//显示“-”
  DisplayData[3]=smgduan[TIME[1]/16];
  DisplayData[4]=smgduan[TIME[1]&0x0f];
  DisplayData[5]=0x40;
	DisplayData[6]=smgduan[TIME[0]/16];
  DisplayData[7]=smgduan[TIME[0]&0x0f];
	  

}


  

void DigDisplay()
{
 u8 i;
 for(i=0;i<8;i++)
 {
 switch(i)
 {
   case(0):
	 LSA=0;LSB=0;LSC=0;break;
	 case(1):
	 LSA=1;LSB=0;LSC=0;break;
	 case(2):
	 LSA=0;LSB=1;LSC=0;break;
	 case(3):
	 LSA=1;LSB=1;LSC=0;break;
	 case(4):
	 LSA=0;LSB=0;LSC=1;break;
	 case(5):
	 LSA=1;LSB=0;LSC=1;break;
	 case(6):
	 LSA=0;LSB=1;LSC=1;break;
	 case(7):
	 LSA=1;LSB=1;LSC=1;break;
 }
 P0=DisplayData[7-i];
 delay(100);
 P0=0x00;
 }
}


void main()
{
	Ds1302Init(); //Ds1302初始化函数 
	while(1)
	{
		datapros();//数据处理函数
		DigDisplay();//数码管显示函数
	}
}
	