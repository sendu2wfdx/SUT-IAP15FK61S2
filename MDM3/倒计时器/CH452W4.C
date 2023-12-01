#include <PIN.H>
#include <CH452W4.H>

//输出操作命令子程序
//定义一无符号整型变量存储12字节的命令字。
void CH452_Write(unsigned short cmd)
{
	unsigned char i;
	DISABLE_KEY_INTERRUPT;						//禁止键盘中断,防止传输过程中被CH452中断而进入中断服务程序中再次传输
	CH452_LOAD_CLR;                 	//命令开始,LOAD=0
	CH452_LOAD_D_OUT;									//设置LOAD为输出方向
	CH452_DOUT_D_IN;									//设置DOUT为输入方向
	CH452_DIN_D_OUT;									//设置DIN为输出方向
	CH452_DCLK_D_OUT;									//设置DCLK为输出方向
	
	for(i=0;i!=12;i++)								//送入12位数据，低位在前
	{
		if (cmd&1) {CH452_DIN_SET;}
		else {CH452_DIN_CLR;}  						// 输出位数据
//		CH452_DIN=cmd&1;
    	CH452_DCLK_CLR;
    	cmd>>=1;
    	CH452_DCLK_SET;             				//上升沿有效
	}
  	CH452_LOAD_SET;         						//加载数据,LOAD上升沿
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
		_nop_();_nop_();_nop_();_nop_();_nop_();_nop_();
  	ENABLE_KEY_INTERRUPT;
}

//*************************************************
//输入按键代码子程序，从CH452读取
unsigned char CH452_Read( void )
{
	unsigned char i;
  	unsigned char cmd,keycode;						//定义命令字，和数据存储器
  	DISABLE_KEY_INTERRUPT;			           		//禁止键盘中断,防止传输过程中被CH452中断而进入中断服务程序中再次传输	
  	cmd=0x07;			               				//读按键的命令字
  	CH452_LOAD_CLR;
  	for(i=0;i!=4;i++)  								//只需要发出高4位,多发也可以,但应该确保最后留下的4位是该命令码
	{
		if (cmd&1) {CH452_DIN_SET;}
		else {CH452_DIN_CLR;}  						//输出位数据
		CH452_DIN=cmd&1;		     				//送入最低位
    	CH452_DCLK_CLR;			 
    	cmd>>=1;			      					//往右移一位
    	CH452_DCLK_SET;			      				//产生时钟上升沿锁通知CH451输入位数据
 	}
  	CH452_LOAD_SET;				      				//产生加载上升沿通知CH451处理命令数据
  	keycode=0;				      					//清除keycode
  	for(i=0;i!=7;i++)
	{
		keycode<<=1;			      				//数据移入keycode,高位在前,低位在后
		if (CH452_DOUT) keycode++;     				//从高到低读入451的数据
    	keycode|=CH452_DOUT;
    	CH452_DCLK_CLR;			      				//产生时钟下升沿通知CH451输出下一位
    	CH452_DCLK_SET;
 	}
  	CLEAR_KEY_INTER_FLAG;	     					//清中断标志
  	ENABLE_KEY_INTERRUPT;
  	return(keycode);			     				//反回键值
}

unsigned char Keynumber(void)
{   
		unsigned char KEY;
		unsigned char KeyNumber=0;
		KEY=CH452_Read();
		switch(KEY)
		{
				case 0x44:KeyNumber=1;break;				//0x04
				//case 0x04:KeyNumber=16;break;				
				case 0x45:KeyNumber=2;break;				//0x05
				//case 0x05:KeyNumber=15;break;				
				case 0x46:KeyNumber=3;break;				//0x06
				//case 0x06:KeyNumber=14;break;
				case 0x47:KeyNumber=4;break;				//0x07
				//case 0x07:KeyNumber=13;break;
				case 0x4c:KeyNumber=5;break;				//0x0c
				//case 0x0c:KeyNumber=12;break;
				case 0x4d:KeyNumber=6;break;				//0x0d
				//case 0x0d:KeyNumber=11;break;
				case 0x4e:KeyNumber=7;break;				//0x0e
				//case 0x0e:KeyNumber=10;break;
				case 0x4f:KeyNumber=8;break;				//0x0f
				//case 0x0f:KeyNumber=9;break;
				default:KeyNumber=0;break;
		}
		return KeyNumber;
}
