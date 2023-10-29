 /**************************************************
 *  File		: Uart.c
 *	Module		: UART
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 ***************************************************/
#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>

static void(*TX_Interrupt_Handler)(void) = NULL;
static void(*RX_Interrupt_Handler)(void) = NULL;

void Tx_set_callback(void (*callback)(void)){
	TX_Interrupt_Handler = callback;
}

void Rx_set_callback(void (*callback)(void)){
	RX_Interrupt_Handler = callback;
}

u8 tx_buffer[TX_BUFFER_MAX_SIZE];
u8 rx_buffer[RX_BUFFER_MAX_SIZE];
u8 tx_index =0;
u8 rx_index =0;

void UART_Init(u16 baudRate)
{
	/* Set baud rate */
	UART_UBRRH_REG = (u8)(baudRate>>8);
	UART_UBRRL_REG = (u8)baudRate;
	/* Enable receiver and transmitter */
	SET_BIT(UART_UCSRB_REG,RXEN_BIT_NO);  /* Enable Receiver*/
	SET_BIT(UART_UCSRB_REG,TXEN_BIT_NO);  /* Enable Transmitter */
	/* Set frame format: 8data, 1stop bit, Even Parity */
	UART_UCSRC_REG |= (1 << URSEL_BIT_NO)|UART_8_BIT_DATA | UART_EVEN_PARITY;
	/* Global Interrupt Enable */
	SET_BIT(UART_SREG_REG,7);
	/*	Enable Rx complete	*/
	SET_BIT(UART_UCSRB_REG,7);
	/*	Enable Tx complete	*/
	SET_BIT(UART_UCSRB_REG,6);
}

void UART_TransmitChr(u8 data)
{
	/* Wait for empty transmit buffer */
	//	while (!(CHECK_BIT(UART_UCSRA_REG,UDRE_BIT_NO)))
	//			;
	/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

u8 UART_ReceiveChr(void)
{
	/* Wait for data to be received */
//	while (!(READ_BIT(UART_UCSRA_REG,RXC_BIT_NO)))
//	;
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}

void UART_TransmitStrPoll(u8 str[])
{
	while (*str != '\0')
	{
		UART_TransmitChr(*str);
		str++;
	}
}

void UART_TransmitStr(u8 *str)
{
	u8 i = 0;
	/*	copy str into global tx buffer	*/
	for (i=0; i < TX_BUFFER_MAX_SIZE; i++)
	{
		tx_buffer[i] = str[i];
	}
	UART_TransmitChr(tx_buffer[tx_index]);
}

ISR(USART_TXC_vect)
{
	if(TX_Interrupt_Handler != NULL){
		TX_Interrupt_Handler();
	}
}


ISR(USART_RXC_vect)
{
	if(RX_Interrupt_Handler != NULL){
		RX_Interrupt_Handler();
	}
}
