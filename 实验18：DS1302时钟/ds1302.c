#include<ds1302.h>


//ds1302写入与读取时秒分的地址命令
//时秒分日月周年 最低位读写位
u8 code READ_RTC_ADDR[7]={0x81,0x83,0x85,0x87,0x89,0x8b,0x8d};
u8 code WRITE_RTC_ADDR[7]={0x80,0x82,0x84,0x86,0x88,0x8a,0x8c};

//时钟初始化2016年5月7日星期六12点00分00秒
//存储顺序是   秒分时日月周年   格式是BCD码

u8 TIME[7]={0,0,0x12,0x07,0x05,0x06,0x16};



/************************************
函数名：Ds1302Write
功能：向DA1302命令（地址+数据）
输入：ADDR,DAT

*************************************/
void Ds1302Write(u8 addr,u8 dat)
{
	u8 n;
	RST=0;
	_nop_();
	
	SCLK=0;//将SCLK置低
	_nop_();
	RST=1;//将RST（CE）置高
	_nop_();
	
	for(n=0;n<8;n++)//开始传送8位地址命令
	{
		DSIO=addr&0x01;//从低位开始传送
		addr>>=1;
		SCLK=1;//上升沿，读取数据
		_nop_();
	  SCLK=0;
	  _nop_();
	}
	
	for(n=0;n<8;n++)//写入8位数据
	{
		DSIO=dat&0x01;//从低位开始传送
		dat>>=1;
		SCLK=1;//上升沿，读取数据
		_nop_();
	  SCLK=0;
	  _nop_();
	}
	
	RST=0;//传送数据结束
  _nop_();
	
}


/************************************
函数名：Ds1302Read
功能：读取一个地址的数据
输入：ADDR
输出：dat

*************************************/
u8 Ds1302Read(u8 addr)
{
	u8 n,dat,dat1;
	RST=0;
	_nop_();
	
	SCLK=0;//将SCLK置低
	_nop_();
	RST=1;//将RST（CE）置高
	_nop_();
	
		for(n=0;n<8;n++)//开始传送8位地址命令
	{
		DSIO=addr&0x01;//从低位开始传送
		addr>>=1;
		SCLK=1;//数据在上升沿时，ds1302读取数据
		_nop_();
	  SCLK=0;//Ds1302下降沿时，放置数据
	  _nop_();
	}
	_nop_();
	for(n=0;n<8;n++)//读取8位数据
	{
		dat1=DSIO;//从低位开始接收
		dat=(dat>>1)|(dat1<<7);
		SCLK=1;//上升沿，读取数据
		_nop_();
	  SCLK=0;//Ds1302下降沿时，放置数据
	  _nop_();
	}
	
	RST=0;
  _nop_();//以下为DS1302复位的稳定时间，必须的
	SCLK=1;
	_nop_();
	DSIO=0;
	_nop_();
	DSIO=1;
	_nop_();
	
	return dat;
}





/***********************************
函数名：Ds1302Init
功能：初始化

************************************/
void Ds1302Init()
{
	u8 n;
	Ds1302Write(0x8e,0x00);//禁止写保护，默认是开的
	for(n=0;n<7;n++)//写入7个字节的时钟信号，分秒时日月周年
	{
		Ds1302Write(WRITE_RTC_ADDR[n],TIME[n]);
	}
	Ds1302Write(0x8e,0x80);//打开写保护功能
}



/************************************
函数名：Ds1302ReadTime
功能：读取时钟信息
输入：无
输出：无

*************************************/
void Ds1302ReadTime()
{
	u8 n;
	for(n=0;n<7;n++)//读取7个字节
	{
		TIME[n]=Ds1302Read(READ_RTC_ADDR[n]);
	}
}