#include <REGX51.H>
#include <Keyscan.h>
#include <Delay.h>
#include <Smg.h>

extern unsigned char flag;
Dig[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};//¶ÎÂë

//void Wei(unsigned char i)
//{
//		switch(i)
//		{
//				case 1:	P2=0X01;	break;
//				case 2:	P2=0X02;	break;
//				case 3:	P2=0X04;	break;
//				case 4:	P2=0X08;	break;
//		}
//		delayms(2);
//		P2=0X00;
//}

//void Display(unsigned int i)
//{
//		int s1,s2,s3,s4;

//		s1=i/1000%10;
//		s2=i/100%10;
//		s3=i/10%10;
//		s4=i%10;

//		P0=Dig[s1];	Wei(1);	delayms(2);
//		P0=Dig[s2];	Wei(2);	delayms(2);
//		P0=Dig[s3];	Wei(3);	delayms(2);
//		P0=Dig[s4];	Wei(4);	delayms(2);
//}
