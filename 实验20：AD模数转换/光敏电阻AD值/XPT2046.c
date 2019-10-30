#include <XPT2046.h>




void SPI_Write(u8 dat)
{
	u8 i;
	CLK=0;
	for(i=0;i<8;i++)
	{
		DIN=dat>>7;
		dat<<=1;
		
		CLK=0;
		CLK=1; 
	}
}

u16 SPI_Read()
{
	u16 i,dat=0;
	CLK=0;
	for(i=0;i<12;i++)
	{
		dat<<=1;
		
		CLK=1;
		CLK=0;
		 
		dat|=DOUT;
		
	}
	return dat;
}


u16 Read_AD_Data(u8 cmd)
{
	u8 i;
	u16 AD_Value;
	CLK=0;
	CS=0;
	SPI_Write(cmd);
	for(i=6;i>0;i--);
	CLK=1;
	_nop_();
	_nop_();
	CLK=0;
	_nop_();
	_nop_();
	AD_Value=SPI_Read();
	CS=1;
	return AD_Value;
}
