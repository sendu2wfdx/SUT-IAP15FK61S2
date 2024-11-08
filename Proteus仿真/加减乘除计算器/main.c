#include <REGX51.H>
#include <Keyscan.h>
#include <Smg.h>
#include <Delay.h>

unsigned char k=16;		//键值
unsigned char flag=0;		//按键状态
int temp=0,num1=0,num2=0,op=0;

//主函数
void main(void)
{
	while(1)
	{
		if(temp>999)
		{
			flag=0;
			Alert();
			temp=0;
		}
		else
		if(k==14)	//key	"="
		{
			switch(op)
			{
				case 1:		num2=num1/temp;	temp=num2; op=0;	break;
				case 2:		num2=num1*temp;	temp=num2; op=0;	break;
				case 3:		num2=num1-temp;	temp=num2; op=0;	break;
				case 4:		num2=num1+temp;	temp=num2; op=0;	break;
				default:	op=0;	break;
			}			
			delayms(200);
			k=16;
			flag=0;
		}
		else
		Display(temp);
		if(flag)	//有按键按下
		{
			if(k==12)	//key "CE"
			{
				temp=0;num1=0;num2=0;
				delayms(200);
				flag=0;
			}
			if(k==3)	//key	"%"
			{
				op=1;
				num1=temp;
				temp=0;
				delayms(200);
				flag=0;
			}			
			if(k==7)	//key	"x"
			{
				op=2;
				num1=temp;
				temp=0;
				delayms(200);
				flag=0;
			}			
			if(k==11)	//key	"-"
			{
				op=3;
				num1=temp;
				temp=0;
				delayms(200);
				flag=0;
			}			
			if(k==15)	//key	"+"
			{
				op=4;
				num1=temp;
				temp=0;
				delayms(200);
				flag=0;
			}
			switch(k)
			{
				case 0:	temp=temp*10+7;	delayms(200); flag=0;	break;	//key	"7"
				case 1:	temp=temp*10+8;	delayms(200); flag=0;	break;	//key	"8"
				case 2:	temp=temp*10+9;	delayms(200); flag=0;	break;	//key	"9"
				case 4:	temp=temp*10+4;	delayms(200); flag=0;	break;	//key	"4"
				case 5:	temp=temp*10+5;	delayms(200); flag=0;	break;	//key	"5"
				case 6:	temp=temp*10+6;	delayms(200); flag=0;	break;	//key	"6"
				case 8:	temp=temp*10+1;	delayms(200); flag=0;	break;	//key	"1"
				case 9:	temp=temp*10+2;	delayms(200); flag=0;	break;	//key	"2"
				case 10:	temp=temp*10+3;	delayms(200); flag=0;	break;	//key	"3"
				case 13:	temp=temp*10+0;	delayms(200); flag=0;	break;	//key	"0"
				default:	break;
			}
		}
		else	keyscan();
	}
}
