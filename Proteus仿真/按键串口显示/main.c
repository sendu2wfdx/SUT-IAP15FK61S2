#include <REGX51.H>
#include <Keyscan.h>
#include <Smg.h>
#include <Delay.h>
#include <UART.h>

extern Dig[];

unsigned char k=16;		//��ֵ
unsigned char flag,flag1;		//����״̬,��ʾ״̬

//������
void main(void)
{
	UartInit(); //��ʼ������
	EA 	= 1;    //�����ж�
	ES	=	1;		//�򿪴����ж�
	P0	=	Dig[0];
	while(1)
	{
		if(flag)	//�а�������
		{
			switch(k)
			{
				case 0:	uart1_sendstring("Key '7' is pressed!\r\n"); P0=Dig[7];	flag=0;	delayms(200);	break;	//key	"7"
				case 1:	uart1_sendstring("Key '8' is pressed!\r\n"); P0=Dig[8];	flag=0;	delayms(200);	break;	//key	"8"
				case 2:	uart1_sendstring("Key '9' is pressed!\r\n"); P0=Dig[9];	flag=0;	delayms(200);	break;	//key	"9"
				case 3:	uart1_sendstring("Key '%' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"%"
				case 4:	uart1_sendstring("Key '4' is pressed!\r\n"); P0=Dig[4];	flag=0;	delayms(200);	break;	//key	"4"
				case 5:	uart1_sendstring("Key '5' is pressed!\r\n"); P0=Dig[5];	flag=0;	delayms(200);	break;	//key	"5"
				case 6:	uart1_sendstring("Key '6' is pressed!\r\n"); P0=Dig[6];	flag=0;	delayms(200);	break;	//key	"6"
				case 7:	uart1_sendstring("Key 'x' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"x"
				case 8:	uart1_sendstring("Key '1' is pressed!\r\n"); P0=Dig[1];	flag=0;	delayms(200);	break;	//key	"1"
				case 9:	uart1_sendstring("Key '2' is pressed!\r\n"); P0=Dig[2];	flag=0;	delayms(200);	break;	//key	"2"
				case 10:	uart1_sendstring("Key '3' is pressed!\r\n"); P0=Dig[3];	flag=0;	delayms(200);	break;	//key	"3"
				case 11:	uart1_sendstring("Key '-' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"-"
				case 12:	uart1_sendstring("Key 'CE' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"CE"
				case 13:	uart1_sendstring("Key '0' is pressed!\r\n"); P0=Dig[0]; flag=0;	delayms(200);	break;	//key	"0"
				case 14:	uart1_sendstring("Key '=' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"="
				case 15:	uart1_sendstring("Key '+' is pressed!\r\n"); flag=0;	delayms(200);	break;	//key	"+"
				default:	break;
			}
		}
		else	keyscan();
	}
}
