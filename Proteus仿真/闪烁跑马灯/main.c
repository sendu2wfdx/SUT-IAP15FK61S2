#include <REGX51.H>
#include <Keyscan.h>
#include <Smg.h>
#include <Delay.h>
#include <UART.h>

extern Dig[];

unsigned char k=16;		//键值
unsigned char flag,flag1;		//按键状态,显示状态

unsigned int i=1234;		//显示数值

//主函数
void main(void)
{
	UartInit(); //初始化串口
	EA 	= 1;    //开总中断
	ES	=	1;		//打开串口中断
	while(1)
	{
		//Display(i);
		switch(flag1)
		{
			case 0:	Display(i);	break;
			case 1:	Pao(i);	break;
			case 2:	Shan(i);	break;
			default:	break;
		}
		if(flag)	//有按键按下
		{
			switch(k)
			{
				case 0:	uart1_sendstring("Key '7' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"7"
				case 1:	uart1_sendstring("Key '8' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"8"
				case 2:	uart1_sendstring("Key '9' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"9"
				case 3:	uart1_sendstring("Key '%' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"%"
				case 4:	uart1_sendstring("Key '4' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"4"
				case 5:	uart1_sendstring("Key '5' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"5"
				case 6:	uart1_sendstring("Key '6' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"6"
				case 7:	uart1_sendstring("Key 'x' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"x"
				case 8:	uart1_sendstring("Key '1' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"1"
				case 9:	uart1_sendstring("Key '2' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"2"
				case 10:	uart1_sendstring("Key '3' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"3"
				case 11:	uart1_sendstring("Key '-' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"-"
				case 12:	uart1_sendstring("Key 'CE' is pressed!\r\n"); flag=0;	flag1=0;	delayms(200);	break;	//key	"CE"
				case 13:	uart1_sendstring("Key '0' is pressed!\r\n"); flag=0;	flag1=1;	delayms(200);	break;	//key	"0"
				case 14:	uart1_sendstring("Key '=' is pressed!\r\n"); flag=0;	flag1=2;	delayms(200);	break;	//key	"="
				case 15:	uart1_sendstring("Key '+' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"+"
				default:	break;
			}
		}
		else	keyscan();
	}
}
