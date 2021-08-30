sbit BEEP=P5^5;	 

void init()											//初始化函数
{
	CH452_Write(CH452_SYSOFF);						//关显示按键
	CH452_Write(CH452_SYSON2);						//开显示按键
	CH452_Write(CH452_NO_BCD);						//不译码模式
	IE=0; 											//中断寄存器清零,防止有初始值
	EA=1; 											//将总中断控制打开
	EX1=1;											//打开外部中断0
	IT1=0;											//电平触发
	BEEP=1;											//关蜂鸣器
}