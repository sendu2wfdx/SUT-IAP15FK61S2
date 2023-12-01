#include <REGX51.H>
#include <UART.h>

bit uart1_busy=0;

void UartInit(void) //9600bps@12.000MHz
{
		TMOD = 0x20;
		PCON = 0x00;
		SCON = 0x60;
		TL1 = 0xFD;
		TH1 = 0xFD;
		ET1 = 0;
		TR1 = 1;
}

void uart1_sendByte(char byte)	//���ڷ���һ���ֽ�
{
    while (uart1_busy);
    uart1_busy = 1;
    SBUF = byte;
    TI = 0;
}

void uart1_sendstring(char* str)	//���ڷ����ַ���
{
    while(*str)
    {
        uart1_sendByte(*str++);
    }
}

void UART1_IRQ_Handle(void) interrupt 4 using 1
{
    if (TI)
    {
        TI = 0;
        uart1_busy = 0;
    }
    if (RI)
    {
        RI = 0;
    }
}

//void main()
//{
//    UartInit(); //��ʼ������
//    EA = 1;     //�����ж�
//    ES=1;		//�򿪴����ж�
//    while (1)
//    {
//        uart1_sendstring("Hellow World!\n");
//    }
//}
