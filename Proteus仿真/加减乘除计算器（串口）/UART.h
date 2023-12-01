#ifndef _UART_h_
#define _UART_h_

void UartInit(void);
void uart1_sendByte(char byte);
void uart1_sendstring(char* str);
void UART1_IRQ_Handle(void);

#endif