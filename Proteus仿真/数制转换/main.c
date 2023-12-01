#include <REGX51.H>
#include <Keyscan.h>
#include <Smg.h>
#include <Delay.h>
#include <UART.h>


unsigned char k=16;		//键值
unsigned char flag=0,flag1=1;		//按键状态,进制状态
int temp=0;

void Display(unsigned int i,j)
{
	switch(i)
	{
		case 0:	Display2(j);	break;
		case 1:	Display10(j);	break;
		case 2:	Display16(j);	break;
		default:	break;
	}
}

//主函数
void main(void)
{
	UartInit(); //初始化串口
	EA = 1;     //开总中断
	ES=1;		//打开串口中断
	while(1)
	{
		Display(flag1,temp);
		if(flag)	//有按键按下
		{
			if(k==12)	//key "CE"
			{
				uart1_sendstring("Key 'CE' is pressed!\r\n");
				temp=0;
				delayms(200);
				flag=0;
			}
			if(k==14)	//key	"="
			{
				uart1_sendstring("Key '=' is pressed!\r\n");
				flag1=1;
				delayms(200);
				flag=0;
			}
			if(k==3)	//key	"%"
			{
				uart1_sendstring("Key '%' is pressed!\r\n");
				flag1=0;
				delayms(200);
				flag=0;
			}			
			if(k==7)	//key	"x"
			{
				uart1_sendstring("Key 'x' is pressed!\r\n");
				flag1=2;
				delayms(200);
				flag=0;
			}			
			if(k==11)	//key	"-"
			{
				uart1_sendstring("Key '-' is pressed!\r\n");
				temp-=1;
				delayms(200);
				flag=0;
			}			
			if(k==15)	//key	"+"
			{
				uart1_sendstring("Key '+' is pressed!\r\n");
				temp+=1;
				delayms(200);
				flag=0;
			}
			switch(k)
			{
				case 0:	uart1_sendstring("Key '7' is pressed!\r\n");	temp=temp*10+7;	delayms(200); flag=0;	break;	//key	"7"
				case 1:	uart1_sendstring("Key '8' is pressed!\r\n");	temp=temp*10+8;	delayms(200); flag=0;	break;	//key	"8"
				case 2:	uart1_sendstring("Key '9' is pressed!\r\n");	temp=temp*10+9;	delayms(200); flag=0;	break;	//key	"9"
				case 4:	uart1_sendstring("Key '4' is pressed!\r\n");	temp=temp*10+4;	delayms(200); flag=0;	break;	//key	"4"
				case 5:	uart1_sendstring("Key '5' is pressed!\r\n");	temp=temp*10+5;	delayms(200); flag=0;	break;	//key	"5"
				case 6:	uart1_sendstring("Key '6' is pressed!\r\n");	temp=temp*10+6;	delayms(200); flag=0;	break;	//key	"6"
				case 8:	uart1_sendstring("Key '1' is pressed!\r\n");	temp=temp*10+1;	delayms(200); flag=0;	break;	//key	"1"
				case 9:	uart1_sendstring("Key '2' is pressed!\r\n");	temp=temp*10+2;	delayms(200); flag=0;	break;	//key	"2"
				case 10:	uart1_sendstring("Key '3' is pressed!\r\n");	temp=temp*10+3;	delayms(200); flag=0;	break;	//key	"3"
				case 13:	uart1_sendstring("Key '0' is pressed!\r\n");	temp=temp*10+0;	delayms(200); flag=0;	break;	//key	"0"
				default:	break;
			}
		}
		else	keyscan();
	}
}
