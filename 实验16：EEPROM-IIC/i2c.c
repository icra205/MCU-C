#include <i2c.h>

void Delay10us(void)
{
	u8 a,b;
	for(b=1;b>0;b--)
	for(a=2;a>0;a--);
}

void I2cStart()
{
	SDA=1;
	Delay10us();
	SCL=1;
	Delay10us();
	SDA=0;
	Delay10us();
	SCL=0;
	Delay10us();
}

void I2cStop()
{
	SDA=0;
	Delay10us();
	SCL=1;
	Delay10us();
	SDA=1;
	Delay10us();
}

u8 I2cSendByte(u8 dat)
{
	u8 a=0,b;
	for(a=0;a<8;a++)
	{
		SDA=dat>>7;
		dat=dat<<1;
		Delay10us();
		SCL=1;
		Delay10us();
		SCL=0;
		Delay10us();
	}
	SDA=1;
	Delay10us();
	SCL=1;
	while(SDA)
	{
		b++;
		if(b>200)
		{
			SCL=0;
    	Delay10us();
	    return 0;
		}
	}
	SCL=0;
	Delay10us();
	return 1;
}

u8 I2cReadByte()
{
	u8 a=0,dat=0;
	for(a=0;a<8;a++)
	{
		SCL=1;
  	Delay10us();
		dat<<=1;
		dat|=SDA;
		Delay10us();
		SCL=0;
	  Delay10us();
	}
	return dat;
}

void At24c02Write(u8 addr,u8 dat)
{
	I2cStart();
	I2cSendByte(0xa0);
	I2cSendByte(addr);
	I2cSendByte(dat);
	I2cStop();
}

u8 At24c02Read(u8 addr)
{
	u8 num;
	I2cStart();
	I2cSendByte(0xa0);
	I2cSendByte(addr);
	I2cStart();
	I2cSendByte(0xa1);
	num=I2cReadByte();
	I2cStop();
	return num;
}