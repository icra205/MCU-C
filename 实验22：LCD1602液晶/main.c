#include <reg52.h>
#include <lcd.h>


//u8 Disp[]=" Pechin Science " ;


void main(void)
{
	//u8 i;
	//u8 dat=1;
	//dat=dat+0x30;(ASCII码)
	//LcdWriteData('dat');
	LcdInit();
	//LcdWriteCom(0x18);解决重启时前移的问题
	LcdWriteword("Welcome to use!");
	LcdWriteCom(0x40+0x80);
	LcdWriteword("Welcome to use!");
	//for(i=0;i<16;i++)
	//{
	//	LcdWriteData(Disp[i]);
		
	//}
	//第二行显示时，LcdWriteCom(0x40+0x80);
	//for(i=0;i<16;i++)
	//{
	//	LcdWriteData(Disp[i]);
	//
	//}
	//
	while(1);
}


	
	