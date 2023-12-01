#include <STC15F2K60S2.H>
#include <PIN.H>
#include "delay.h"
#include <CH452W4.H>
#include <Display.H>

#define FOSC 24000000L  	// 晶振频率为24MHz

sbit	BEEP = P4^5;				//蜂鸣器

unsigned char Key;
bit flag = 0;										//计时标志位
unsigned char i=0;							//蜂鸣次数
unsigned int Temp = 5000;				//默认计时5s

void Init_Timer0() 	//定时时间1ms
{
    AUXR |= 0x80;		// 定时器0为1T模式
    TMOD &= 0xF0;		// 设定定时器0为模式1
    TL0 = (65536 - (FOSC / 1000)) % 256;		// 初始化定时器初值
    TH0 = (65536 - (FOSC / 1000)) / 256;		// 初始化定时器重装值
    ET0 = 1;		// 允许定时器0中断
    EA 	= 1;		// 打开总中断开关
    TR0 = 1;		// 启动定时器0
}

void Init_CH452()
{
		CH452_Write(CH452_SYSOFF);		//关显示按键
		CH452_Write(CH452_SYSON2);		//开显示按键
		CH452_Write(CH452_NO_BCD);		//不译码模式
}

void Init_All()			//初始化函数
{
		BEEP=1;					// 关蜂鸣器
	  Init_Timer0();	// 初始化定时器0
		Init_CH452();		// 初始化CH452
}

void main()
{	
		Init_All();
		while(1)
		{
				Key = Keynumber();						//获取键值
				switch(Key)
				{
						case 1: 	
								Temp = Temp + 10000;	//	目标计时时间加 10s
								break;
						case 2:
								Temp = Temp + 1000;		//	目标计时时间加 1s
								break;
						case 3:
								Temp = Temp + 100;		//	目标计时时间加 0.1s
								break;
						case 4:
								Temp = Temp + 10;			//	目标计时时间加 10ms
								break;
						case 5:
								flag = ~flag;					//	开始/结束倒计时
								break;
						case 6:
								if(Temp>1000)
										Temp = Temp - 1000;	//	目标计时时间减 10s
								break;
						case 7:
								if(Temp>100)
										Temp = Temp - 100;	//	目标计时时间减 0.1s
								break;
						case 8:
								if(Temp>10)
										Temp = Temp - 10;		//	目标计时时间减 10ms
								break;
						default:
								break;	
				}
				if(Temp == 0 && flag == 1)
				{
						ET0 	= 0;				//	关闭定时器0中断开关
						flag = 0;					//	清计时标志
						for(i=0;i<3;i++)	//	蜂鸣器间歇鸣响，数码管间歇点亮，持续 3s
						{
								BEEP = 0;
								delay_ms(1000);
								BEEP = 1;
								delay_ms(1000);
						}
						Temp = 5000;		//	恢复默认计时时间
						ET0 = 1;				//	打开定时器0中断开关
				}
				if(Temp >= 32000)		//向上溢出判断
						Temp = 32000;
				if(Temp <= 10)			//向下溢出判断
						Temp = 0;
				delay_ms(100);			//	按键延时，避免连击
		}
}

void Timer0_ISR() interrupt 1	// 定时器0中断服务函数
{	
		if(flag == 1)							//倒计时
				if(Temp>0)
						Temp = Temp -1;
		Display(Temp);						//数码管例行刷新
}
