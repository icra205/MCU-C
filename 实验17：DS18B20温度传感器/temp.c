#include <temp.h>

void Delay1ms(u16 y)
{
	u16 x;
	for(;y>0;y--)
	{
		for(x=110;x>0;x--);
	}
}



u8 Ds18b20Init()
{
	u8 i=0;
	DSPORT=0;
	i=70;
	while(i--);//642us
	DSPORT=1;
	i=0;
	while(DSPORT)
	{
		Delay1ms(1);
		i++;
		if(i>5)
		{
			return 0; 
		}
	}
	return 1;
}



void Ds18b20WriteByte(u8 dat)
{
	u8 i,j;
	for(j=0;j<8;j++)
	{
		DSPORT=0;
		i++;
		DSPORT=dat&0x01;
		i=6;
		while(i--);//68us
		DSPORT=1;
		dat>>=1;
	}
	
}

u8 Ds18b20ReadByte()
{
	u16 i,j;
	u8 bi,byte;
	
	for(j=8;j>0;j--)
	{
		DSPORT=0;
		i++;
		DSPORT=1;
		i++;
		i++;
		bi=DSPORT;
		byte=(byte>>1)|(bi<<7);
		i=4;
		while(i--);
	}
	return byte;
}

void Ds18b20ChangeTemp()
{
	Ds18b20Init();
	Delay1ms(1);
	Ds18b20WriteByte(0xcc);
	Ds18b20WriteByte(0x44);
}


void Ds18b20ReadTempCom()
{
	Ds18b20Init();
	Delay1ms(1);
	Ds18b20WriteByte(0xcc);
	Ds18b20WriteByte(0xbe);
}


int Ds18b20ReadTemp()
{
	int temp=0;
	u8 tmh,tm1;
	Ds18b20ChangeTemp();
	Ds18b20ReadTempCom();
	tm1=Ds18b20ReadByte();
	tmh=Ds18b20ReadByte();
	temp=tmh;
	temp<<=8;
	temp|=tm1;
	return temp;
}