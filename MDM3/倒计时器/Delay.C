#include "PIN.H"
#include "delay.h"

#define FOSC 24000000L  //24M

void delay_us(unsigned int us) 
{
    unsigned int count = us * (FOSC / 1000000L) / 12;
    while (count--) 
		{
        _nop_();
    }
}

void delay_ms(unsigned int ms) 
{
    while (ms--) 
		{
        delay_us(1000);
    }
}
