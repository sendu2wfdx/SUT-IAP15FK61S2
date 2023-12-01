#include <REGX51.H>
#include <Keyscan.h>
#include <Delay.h>

extern unsigned char k;		//键值
extern unsigned char flag;		//按键状态

//按键扫描函数
void keyscan(void)
{
	unsigned char a;	//键值暂存
	P1=0Xf0;
	if(P1!=0xf0)	//有按键按下
	{
		delayms(50);
		if(P1!=0xf0)	//延时消抖
		{
			P1=0xfe;	//P14低电平
//			delayms(50);

			//开始行列扫描
			a=P1;		//缓存
			switch(a)
			{
				case 0xee:	k=15;flag=1; break;
				case 0xde:	k=11;flag=1; break;
				case 0xbe:	k=7;flag=1; break;
				case 0x7e:	k=3;flag=1; break;
				default:	P1=0xfd;	//P15低电平
	
				a=P1;
				switch(a)
				{
					case 0xed:	k=14;flag=1; break;
					case 0xdd:	k=10;flag=1; break;
					case 0xbd:	k=6;flag=1; break;
					case 0x7d:	k=2;flag=1; break;
					default:	P1=0xfb;	//P16低电平
	
					a=P1;
					switch(a)
					{
						case 0xeb:	k=13;flag=1; break;
						case 0xdb:	k=9;flag=1; break;
						case 0xbb:	k=5;flag=1; break;
						case 0x7b:	k=1;flag=1; break;
						default:	P1=0xf7;	//P17低电平
		
						a=P1;
						switch(a)
						{
							case 0xe7:	k=12;flag=1; break;
							case 0xd7:	k=8;flag=1; break;
							case 0xb7:	k=4;flag=1; break;
							case 0x77:	k=0;flag=1; break;
							default:	break;

						}
					}	
				}
				break;
			}
		}
	}
}
