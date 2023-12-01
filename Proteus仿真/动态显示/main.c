#include <REGX51.H>
#include <Keyscan.h>
#include <Smg.h>

unsigned char k;		//¼üÖµ

//Ö÷º¯Êý
void main(void)
{
	while(1)
	{
		keyscan();
		Display(1234);
	}
}
