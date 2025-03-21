/*
 * uart.c
 *
 *  Created on: Feb 25, 2025
 *      Author: ghass
 */
#include "usart.h"
#include "stm32_Nucleo_F401RE_map.h"

void USART_Init(USART_Handle_t *pUSARTHandle)
{

	uint32_t tempreg=0;

	// CR1 register's configurations

	// TX,RX or RX_TX
	if (pUSARTHandle->usart_config.USART_Mode == UART_MODE_RX){
		tempreg |= (1 << 2);
	}
	else if (pUSARTHandle->usart_config.USART_Mode == UART_MODE_TX){
		tempreg |= ( 1 << 3);

	}
	else if (pUSARTHandle->usart_config.USART_Mode == UART_MODE_TX_RX){
		tempreg |= ( ( 1 << 2) | ( 1 << 3) );
	}
	// Word length
	tempreg |= pUSARTHandle->usart_config.USART_WordLength << 12 ;


	// parity control
	if ( pUSARTHandle->usart_config.USART_ParityControl == UART_PARITY_EVEN){
		tempreg |= ( 1 << 10);

	}
	else if (pUSARTHandle->usart_config.USART_ParityControl == UART_PARITY_ODD){
		tempreg |= ( 1 << 10);

		tempreg |= ( 1 << 11);

	}

	//Program the CR1 register
	pUSARTHandle->pUSARTx->USART_CR1 = tempreg;

	// cr2 register's configuration
	tempreg=0;

	// Number of stop bits
	if (pUSARTHandle->usart_config.USART_NoOfStopBits == UART_STOPBITS_1){
		tempreg |= (0 << 12) | (0 << 13);
	}
	else if (pUSARTHandle->usart_config.USART_NoOfStopBits == UART_STOPBITS_0_5){
		tempreg |= (1 << 12)| (0 << 13);
	}
	else if (pUSARTHandle->usart_config.USART_NoOfStopBits == UART_STOPBITS_2){
		tempreg |= (0 << 12)| (1 << 13);
	}
	else if (pUSARTHandle->usart_config.USART_NoOfStopBits == UART_STOPBITS_1_5){
		tempreg |= (1 << 12)| (1 << 13);
	}

	//Program the CR2 register
	pUSARTHandle->pUSARTx->USART_CR2 = tempreg;

	// CR3 register's configuration
	tempreg=0;

	// hardware flow control
	if ( pUSARTHandle->usart_config.USART_HwFloatCtl == UART_HWCONTROL_CTS){
		tempreg |= (1 << 9);


	}
	else if (pUSARTHandle->usart_config.USART_HwFloatCtl == UART_HWCONTROL_RTS){
		tempreg |= (1 << 8);

	}
	else if (pUSARTHandle->usart_config.USART_HwFloatCtl == UART_HWCONTROL_CTS_RTS){
		tempreg |= (1 << 8) | (1 << 9);
	}


	pUSARTHandle->pUSARTx->USART_CR3 = tempreg;

	// Baudrate register's configuration

}
