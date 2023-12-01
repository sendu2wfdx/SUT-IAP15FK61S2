#include <REGX51.H>
#include <Delay.h>
#include <TLC5628.H>
#include <Keyscan.h>
#include <Smg.h>

void main(void)
{
	Init_TLC5628();		//DA初始化
	P0=0xc0;		//0000
	while(1)
	{
			key_service();		//按键服务
	}
}
