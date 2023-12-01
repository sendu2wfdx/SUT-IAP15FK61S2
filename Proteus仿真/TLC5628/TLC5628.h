#ifndef _TCL5628_h_
#define _TCL5628_h_

void TCL5628_Write(unsigned char addr, bit rng, unsigned char dat);
void Init_TLC5628();
void SinWave(unsigned char ch);

#endif