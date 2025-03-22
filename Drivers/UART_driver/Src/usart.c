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
	// enabling clocks

	if (pUSARTHandle->pUSARTx == USART1){
		*RCC_APB2_ENR |= (1 << 4);
	}
	else if (pUSARTHandle->pUSARTx == USART2){
		*RCC_APB1_ENR |= (1 << 17);

	}
	else if (pUSARTHandle->pUSARTx == USART6){
		*RCC_APB2_ENR |= (1 << 5);

	}

	uint32_t tempreg=0;

	// CR1 register's configurations

	// USART Enable Bit
	tempreg |= (1 << 13);

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

uint8_t USART_GetFlagStatus(USART_TypeDef *pUSARTx , uint32_t FlagName){

	if (FlagName == USART_SR_TXE){
		return ((uint8_t)(pUSARTx->USART_SR & (1 << 7)));
	}
	else if (FlagName == USART_SR_TC){
		return ((uint8_t)(pUSARTx->USART_SR & (1 << 6)));
	}
	else if (FlagName == USART_SR_RXNE){
		return ((uint8_t)(pUSARTx->USART_SR & (1 <<5)));
	}
	return 0;
}

void USART_SendData(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t len){

	uint16_t *pdata;
	for(uint32_t i = 0 ; i < len; i++)
	{
		// wait for TXE to be set
		while(! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_SR_TXE));

		// 9bit data transfer
		if(pUSARTHandle->usart_config.USART_WordLength == UART_WORDLENGTH_9B)
		{

			pdata = (uint16_t*) pTxBuffer;
			pUSARTHandle->pUSARTx->USART_DR = (*pdata & (uint16_t)0x01FF);

			//check for USART_ParityControl
			if(pUSARTHandle->usart_config.USART_ParityControl == UART_PARITY_DISABLE)
			{
				// No parity is used in this transfer.
				// each data will be written on 2 bits
				pTxBuffer++;
				pTxBuffer++;
			}
			else
			{
				// Parity bit is used in this transfer the 9th bit will be replaced by parity bit.
				// each data will be written on 1 bit
				pTxBuffer++;
			}
		}
		else
		{
			if (pUSARTHandle->usart_config.USART_ParityControl == UART_PARITY_DISABLE){
				// 8bit data transfer
				pUSARTHandle->pUSARTx->USART_DR = (*pTxBuffer  & (uint8_t)0xFF);
				pTxBuffer++;
			}
			else{
				// 7bit data transfer
				pUSARTHandle->pUSARTx->USART_DR = (*pTxBuffer & (uint8_t)0x7F);
				pTxBuffer++;
			}
		}
	}

	// wait for TC to be set
	while( ! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_SR_TC));
}

void USART_ReceiveData(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t len){

	//Loop over until "len" number of bytes are transferred
	for(uint32_t i = 0 ; i < len; i++)
	{
		//Implement the code to wait until RXNE flag is set in the SR
		while( ! USART_GetFlagStatus(pUSARTHandle->pUSARTx, USART_SR_RXNE));

		//Check the USART_WordLength to decide whether we are going to receive 9bit of data in a frame or 8 bit
		if( pUSARTHandle->usart_config.USART_WordLength == UART_WORDLENGTH_9B)
		{
			//We are going to receive 9bit data in a frame

			//check are we using USART_ParityControl control or not
			if(pUSARTHandle->usart_config.USART_ParityControl == UART_PARITY_DISABLE)
			{
				// No parity is used. so, 9bits will be received
				*((uint16_t*) pRxBuffer) = (pUSARTHandle->pUSARTx->USART_DR  & (uint16_t)0x01FF);

				pRxBuffer++;
				pRxBuffer++;
			}
			else
			{
				// Parity is used, so, 8bits will be received
				*pRxBuffer = (pUSARTHandle->pUSARTx->USART_DR  & (uint8_t)0xFF);
				pRxBuffer++;
			}
		}
		else
		{
			// receiving 8bit data in a frame

			//check are we using USART_ParityControl control or not
			if(pUSARTHandle->usart_config.USART_ParityControl == UART_PARITY_DISABLE)
			{
				//No parity is used , so all 8bits will be of user data

				//read 8 bits from DR
				*pRxBuffer = (uint8_t)pUSARTHandle->pUSARTx->USART_DR & (uint8_t)0xFF;
			}

			else
			{
				// Parity is used, 7 bits will be of user data and 1 bit is parity
				*pRxBuffer = (uint8_t)pUSARTHandle->pUSARTx->USART_DR & (uint8_t) 0x7F;
			}
			pRxBuffer++;
		}
	}
}

HAL_StatusTypeDef USART_SendDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pTxBuffer, uint32_t Len)
{
	uint8_t txstate = pUSARTHandle->TxBusyState;

	if(txstate != HAL_BUSY)
	{
		pUSARTHandle->TxLength = Len;
		pUSARTHandle->pTxBuffer = pTxBuffer;
		pUSARTHandle->TxBusyState = HAL_BUSY;

		// enable interrupt for TXE
		pUSARTHandle->pUSARTx->USART_CR1 |= (1 << 7);

		// enable interrupt for TC
		pUSARTHandle->pUSARTx->USART_CR1 |= (1 << 6);
	}
	return txstate;
}

uint8_t USART_ReceiveDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pRxBuffer, uint32_t Len)
{
	uint8_t rxstate = pUSARTHandle->RxBusyState;

	if(rxstate != HAL_BUSY)
	{
		pUSARTHandle->RxLength = Len;
		pUSARTHandle->pRxBuffer = pRxBuffer;
		pUSARTHandle->RxBusyState = HAL_BUSY;

		//Implement the code to enable interrupt for RXNE
		pUSARTHandle->pUSARTx->USART_CR1 |= (1 << 5);
	}

	return rxstate;
}

