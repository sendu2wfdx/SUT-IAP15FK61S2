#include <STC15F2K60S2.H>
#include <intrins.h>
#include <CH452CMD.H>

#pragma NOAREGS		// 如果MCS51使用键盘中断功能，那么建议加入此编译选项

/* 4线接口的连接,与实际电路有关 */
sbit  CH452_DCLK = P2^4;                     // 串行数据时钟上升延激活
sbit  CH452_DIN = P2^5;		                // 串行数据输出，接CH452的数据输入
sbit  CH452_LOAD = P2^6;                     // 串行命令加载，上升延激活
sbit  CH452_DOUT = P2^7;                     // INT1，键盘中断和键值数据输入，接CH452的数据输出

/* 4线接口的位操作,与单片机有关 */
#define		CH452_DCLK_SET		{CH452_DCLK=1;}
#define		CH452_DCLK_CLR		{CH452_DCLK=0;}
#define		CH452_DCLK_D_OUT	{}				// 设置DCLK为输出方向,对于双向I/O需切换为输出
#define		CH452_DIN_SET		{CH452_DIN=1;}
#define		CH452_DIN_CLR		{CH452_DIN=0;}
#define		CH452_DIN_D_OUT		{}				// 设置DIN为输出方向,对于双向I/O需切换为输出
#define		CH452_LOAD_SET		{CH452_LOAD=1;}
#define		CH452_LOAD_CLR		{CH452_LOAD=0;}
#define		CH452_LOAD_D_OUT	{}				// 设置LOAD为输出方向,对于双向I/O需切换为输出
#define		CH452_DOUT_D_IN		{CH452_DOUT=1;}	// 设置DOUT为输入方向,对于双向I/O需切换为输入

/* 与单片机有关,与中断连接方式有关 */
//#define		USE_CH452_KEY		1			// 使用了CH452的按键中断
#ifdef 		USE_CH452_KEY
#define		DISABLE_KEY_INTERRUPT	{EX1=0;}
#define		ENABLE_KEY_INTERRUPT	{EX1=1;}
#define		CLEAR_KEY_INTER_FLAG	{IE1=0;}
#else
#define		DISABLE_KEY_INTERRUPT	{}
#define		ENABLE_KEY_INTERRUPT	{}
#define		CLEAR_KEY_INTER_FLAG	{}
#endif
