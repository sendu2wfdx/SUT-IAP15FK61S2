#include <REGX51.H>
#include <Keyscan.h>
#include <Smg.h>

unsigned char k;		//��ֵ

//������
void main(void)
{
	while(1)
	{
		keyscan();
		Display(1234);
	}
}
