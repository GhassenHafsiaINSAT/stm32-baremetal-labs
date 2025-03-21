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
		return (uint8_t (pUSARTx->USART_SR & (1 << 7)));
	}
	else if (FlagName == USART_SR_TC){
		return (uint8_t (pUSARTx->USART_SR & (1 << 6)));
	}
	else if (FlagName == USART_SR_RXNE){
		return (uint8_t (pUSARTx->USART_SR & (1 <<5)));
	}
}

void USART_SendData(USART_Handle_t *pUSARTHandle, uint8_t *pTxBuffer, uint32_t Len)
{

	uint16_t *pdata;
   //Loop over until "Len" number of bytes are transferred
	for(uint32_t i = 0 ; i < TODO; i++)
	{
		//Implement the code to wait until TXE flag is set in the SR
		while(! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_TODO));

         //Check the USART_WordLength item for 9BIT or 8BIT in a frame
		if(pUSARTHandle->USART_Config.TODO == USART_WORDLEN_9BITS)
		{
			//if 9BIT, load the DR with 2bytes masking the bits other than first 9 bits
			pdata = (uint16_t*) pTxBuffer;
			TODO = (*pdata & (uint16_t)0x01FF);

			//check for USART_ParityControl
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used in this transfer. so, 9bits of user data will be sent
				//Implement the code to increment pTxBuffer twice
				pTxBuffer++;
				pTxBuffer++;
			}
			else
			{
				//Parity bit is used in this transfer . so , 8bits of user data will be sent
				//The 9th bit will be replaced by parity bit by the hardware
				pTxBuffer++;
			}
		}
		else
		{
			//This is 8bit data transfer
			pUSARTHandle->pUSARTx->DR = (*pTxBuffer  & (uint8_t)0xFF);

			//Implement the code to increment the buffer address
			TODO
		}
	}

	//Implement the code to wait till TC flag is set in the SR
	while( ! USART_GetFlagStatus(pUSARTHandle->pUSARTx,USART_FLAG_TODO));
}

void USART_ReceiveData(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t Len)
{
   //Loop over until "Len" number of bytes are transferred
	for(uint32_t i = 0 ; i < TODO; i++)
	{
		//Implement the code to wait until RXNE flag is set in the SR
		TODO

		//Check the USART_WordLength to decide whether we are going to receive 9bit of data in a frame or 8 bit
		if(pUSARTHandle->USART_Config.USART_WordLength == USART_WORDLEN_9BITS)
		{
			//We are going to receive 9bit data in a frame

			//check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == TODO)
			{
				//No parity is used. so, all 9bits will be of user data

				//read only first 9 bits. so, mask the DR with 0x01FF
				*((uint16_t*) pRxBuffer) = (pUSARTHandle->pUSARTx->DR  & (uint16_t)TODO);

				//Now increment the pRxBuffer two times
				TODO
			}
			else
			{
				//Parity is used, so, 8bits will be of user data and 1 bit is parity
				 *pRxBuffer = (pUSARTHandle->pUSARTx->DR  & (uint8_t)0xFF);

				 //Increment the pRxBuffer
				TODO
			}
		}
		else
		{
			//We are going to receive 8bit data in a frame

			//check are we using USART_ParityControl control or not
			if(pUSARTHandle->USART_Config.USART_ParityControl == USART_PARITY_DISABLE)
			{
				//No parity is used , so all 8bits will be of user data

				//read 8 bits from DR
				 *pRxBuffer = TODO;
			}

			else
			{
				//Parity is used, so , 7 bits will be of user data and 1 bit is parity

				//read only 7 bits , hence mask the DR with 0X7F
				 *pRxBuffer = (uint8_t) TODO

			}

			//increment the pRxBuffer
			pRxBuffer++;
		}
	}

}

uint8_t USART_SendDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pTxBuffer, uint32_t Len)
{
	uint8_t txstate = pUSARTHandle->TODO;

	if(txstate != USART_BUSY_IN_TX)
	{
		pUSARTHandle->TODO = Len;
		pUSARTHandle->pTxBuffer = TODO;
		pUSARTHandle->TxBusyState = TODO;

		//Implement the code to enable interrupt for TXE
		TODO


		//Implement the code to enable interrupt for TC
		TODO


	}

	return txstate;

}

uint8_t USART_ReceiveDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pRxBuffer, uint32_t Len)
{
	uint8_t rxstate = pUSARTHandle->TODO;

	if(rxstate != TODO)
	{
		pUSARTHandle->RxLen = Len;
		pUSARTHandle->pRxBuffer = TODO;
		pUSARTHandle->RxBusyState = TODO;

		//Implement the code to enable interrupt for RXNE
		TODO

	}

	return rxstate;

}


