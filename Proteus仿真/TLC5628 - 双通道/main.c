#include <REGX51.H>
#include <intrins.h>
#include <Delay.h>
#include <TLC5628.H>
#include <Keyscan.h>
#include <Smg.h>

void main(void)
{
	Init_TLC5628();		//DA��ʼ��
	P0=0x82;					//6666
	while(1)
	{
			SinWave();		//DA���
	}
}
