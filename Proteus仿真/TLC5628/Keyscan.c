#include <REGX51.H>
#include <TLC5628.H>
#include <Keyscan.h>
#include <Delay.h>

unsigned char k=16;		//��ֵ
unsigned char flag;		//����״̬

extern Dig[];

//����ɨ�躯��
void keyscan(void)
{
	unsigned char a;	//��ֵ�ݴ�
	P1=0Xf0;
	if(P1!=0xf0)	//�а�������
	{
		delayms(50);
		if(P1!=0xf0)	//��ʱ����
		{
			P1=0xfe;	//P14�͵�ƽ

			//��ʼ����ɨ��
			a=P1;		//����
			switch(a)
			{
				case 0xee:	k=15;flag=1; break;
				case 0xde:	k=11;flag=1; break;
				case 0xbe:	k=7;flag=1; break;
				case 0x7e:	k=3;flag=1; break;
				default:	P1=0xfd;	//P15�͵�ƽ
	
				a=P1;
				switch(a)
				{
					case 0xed:	k=14;flag=1; break;
					case 0xdd:	k=10;flag=1; break;
					case 0xbd:	k=6;flag=1; break;
					case 0x7d:	k=2;flag=1; break;
					default:	P1=0xfb;	//P16�͵�ƽ
	
					a=P1;
					switch(a)
					{
						case 0xeb:	k=13;flag=1; break;
						case 0xdb:	k=9;flag=1; break;
						case 0xbb:	k=5;flag=1; break;
						case 0x7b:	k=1;flag=1; break;
						default:	P1=0xf7;	//P17�͵�ƽ
		
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

//����������
void key_service()
{
		if(flag)	//�а�������
		{
			switch(k)
			{
//				case 0:			P0=Dig[1];	SinWave(0);		
//										flag=0;	delayms(20);	break;	//key	"7"
//				case 1:			P0=Dig[2];	SinWave(1);	
//										flag=0;	delayms(20);	break;	//key	"8"
//				case 2:			P0=Dig[3];	SinWave(2);	
//										flag=0;	delayms(20);	break;	//key	"9"
//				case 3:			P0=Dig[4];	SinWave(3);	
//										flag=0;	delayms(20);	break;	//key	"%"
				case 4:			P0=Dig[4];	SinWave(3);	
										flag=0;	delayms(20);	break;	//key	"4"
//				case 5:			//
//										flag=0;	delayms(20);	break;	//key	"5"
//				case 6:			//
//										flag=0;	delayms(20);	break;	//key	"6"
//				case 7:			//
//										flag=0;	delayms(20);	break;	//key	"x"
				case 8:			P0=Dig[1];	SinWave(0);	
										flag=0;	delayms(20);	break;	//key	"1"
				case 9:			P0=Dig[2];	SinWave(1);	
										flag=0;	delayms(20);	break;	//key	"2"
				case 10:		P0=Dig[3];	SinWave(2);	
										flag=0;	delayms(20);	break;	//key	"3"
//				case 11:		//
//										flag=0;	delayms(20);	break;	//key	"-"
//				case 12:		//
//										flag=0;	delayms(20);	break;	//key	"CE"
//				case 13:		//
//										flag=0;	delayms(20);	break;	//key	"0"
//				case 14:		//
//										flag=0;	delayms(20);	break;	//key	"="
//				case 15:		//
//										flag=0;	delayms(20);	break;	//key	"+"
				default:		break;
			}
		}
		else	keyscan();
}
