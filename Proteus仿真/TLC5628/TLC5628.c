#include <REGX51.H>
#include <Delay.h>
#include <TLC5628.H>
#include <Keyscan.h>


sbit CLK 	= P3^0; //����ʱ��,�½�����Ч
sbit DAT 	= P3^1; //��������
sbit LOAD = P3^2; //�������ݼ���,�½�����Ч
sbit LDAC = P3^3; //DAC�����������,�½�����Ч

extern unsigned char flag;

//���ұ�128��
code unsigned char SinTab[] =
{
		128,134,140,147,153,159,165,171,177,182,188,193,199,204,209,213,
		218,222,226,230,234,237,240,243,245,248,250,251,253,254,254,255,
		255,255,254,254,253,251,250,248,245,243,240,237,234,230,226,222,
		218,213,209,204,199,193,188,182,177,171,165,159,153,147,140,134,
		128,122,116,109,103, 97, 91, 85, 79, 74, 68, 63, 57, 52, 47, 43,
		 38, 34, 30, 26, 22, 19, 16, 13, 11,  8,  6,  5,  3,  2,  2,  1,
			1,  1,  2,  2,  3,  5,  6,  8, 11, 13, 16, 19, 22, 26, 30, 34,
		 38, 43, 47, 52, 57, 63, 68, 74, 79, 85, 91, 97,103,109,116,122
};

/*TCL5628 ��������*/
void TCL5628_Write(unsigned char addr, bit rng, unsigned char dat)
{
		unsigned char n;

		// ����ͨ����ַ
		n = 3;
		do
		{
				DAT = (bit)(addr & 0x04);
				addr <<= 1;
				CLK = 0;
				CLK = 1;
		}while(--n != 0);

		//����RNGλ
		DAT = rng;
		CLK = 0;
		CLK = 1;

		//����8λDAC����
		n = 8;
		do
		{
				DAT = (bit)(dat & 0x80);
				dat <<= 1;
				CLK = 0;
				CLK = 1;
		}while(--n != 0);
		
		//��������
		LOAD = 0;
		LOAD = 1;
		LDAC = 0;
		LDAC = 1;
}

/*��ʼ��TLC5628*/
void Init_TLC5628()
{
        DAT = 1;
        CLK = 1;
        LDAC = 1;
        LOAD = 1;
}

/*DA�������*/
void SinWave(unsigned char ch)
{
		/*�������߹⻬��ѡȡ������*/
		unsigned char n;
		while(1)
		{
				for(n = 0; n < 128; n++)
				{
						TCL5628_Write(ch,0,SinTab[n]);
				}
		}
}
