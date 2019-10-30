#include <lcd.h>



void LCD1602_Delay1ms(u16 c)
{
	u16 a,b;
	for(;c>0;c--)
	{
		for(b=199;b>0;b--)
		{
			for(a=1;a>0;a--);
		}
	}
}




#ifndef  LCD1602_4PINS
void LcdWriteCom (u8 com)
{
	LCD1602_E=0;
	LCD1602_RS=0;
	LCD1602_RW=0;
	
	LCD1602_DATAPINS =com;
	LCD1602_Delay1ms(1);
	
	LCD1602_E=1;
	LCD1602_Delay1ms(5);
	LCD1602_E=0;
}
#else
void LcdWriteCom (u8 com)
{
	LCD1602_E=0;
	LCD1602_RS=0;
	LCD1602_RW=0;
	
	LCD1602_DATAPINS = com;
	LCD1602_Delay1ms(1);
	
	LCD1602_E=1;
	LCD1602_Delay1ms(5);
	LCD1602_E=0;
	
	LCD1602_DATAPINS=com<<4;
	LCD1602_Delay1ms(1);
	
	LCD1602_E=1;
	LCD1602_Delay1ms(5);
	LCD1602_E=0;
}

#endif


#ifndef  LCD1602_4PINS
void LcdWriteData(u8 dat)
{
	LCD1602_E=0;
	LCD1602_RS=1;
	LCD1602_RW=0;
	
	LCD1602_DATAPINS = dat;
	LCD1602_Delay1ms(1);
	
	LCD1602_E=1;
	LCD1602_Delay1ms(5);
	LCD1602_E=0;
}
#else
void LcdWriteData(u8 dat)
{
	LCD1602_E=0;
	LCD1602_RS=1;
	LCD1602_RW=0;
	
	LCD1602_DATAPINS = dat;
	LCD1602_Delay1ms(1);
	
	LCD1602_E=1;
	LCD1602_Delay1ms(5);
	LCD1602_E=0;
	
	LCD1602_DATAPINS=dat<<4;
	LCD1602_Delay1ms(1);
	
	LCD1602_E=1;
	LCD1602_Delay1ms(5);
	LCD1602_E=0;
}

#endif


#ifndef  LCD1602_4PINS
void LcdInit()
{
	LcdWriteCom(0x38);
	LcdWriteCom(0x0c);
	LcdWriteCom(0x06);
	LcdWriteCom(0x01);
	LcdWriteCom(0x80);
}
#else
void LcdInit()
{
	LcdWriteCom(0x32);
	LcdWriteCom(0x28);
	LcdWriteCom(0x0c);
	LcdWriteCom(0x06);
	LcdWriteCom(0x01);
	LcdWriteCom(0x80);
}
#endif


void  LcdWriteword(unsigned char *s)
{
	while(*s>0)
	{
		LcdWriteData(*s);
		s++;
	}
	
}
