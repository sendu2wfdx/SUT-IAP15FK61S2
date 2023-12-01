#include <Delay.h>

void delayms(unsigned char x)
{
	int i,j;
	for(i=x;i>0;i--)
		for(j=0;j<120;j++);
}
