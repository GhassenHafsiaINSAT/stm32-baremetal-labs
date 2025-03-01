/*
 * uart.h
 *
 *  Created on: Feb 25, 2025
 *      Author: ghass
 */

#ifndef USART_H_
#define USART_H_
#include "stm32_Nucleo_F401RE_map.h"

// USART enable
#define UART_ENABLE 			0X00002000

// Word length
#define UART_WORDLENGTH_8B 		0x00001000
#define UART_WORDLENGTH_9B 		0x00000000

// Stop bits
#define UART_STOPBITS_0_5 		0x00001000
#define UART_STOPBITS_1			0x00000000
#define UART_STOPBITS_1_5		0x00003000
#define UART_STOPBITS_2			0x00002000

// Parity bit
#define UART_PARITY_NONE		0x00000400
#define UART_PARITY_ODD			0x00000200
#define UART_PARITY_EVEN		0x00000000

// MODE
#define UART_MODE_RX			0x00000004
#define UART_MODE_TX			0x00000008
#define UART_MODE_TX_RX			0x0000000C

// HwFlowCtl
#define UART_HWCONTROL_NONE		0X00000000
#define UART_HWCONTROL_RTS		0X00000100
#define UART_HWCONTROL_CTS		0X00000200

// OverSampling
#define UART_OVERSAMPLING_8		0x00008000
#define UART_OVERSAMPLING_16	0x00000000


typedef struct
{
	uint32_t Baudrate;
	uint32_t WordLength;
	uint32_t StopBits;
	uint32_t Parity;
	uint32_t Mode;
	uint32_t HwFloatCtl;
	uint32_t OverSampling;
} uart_init;

typedef struct
{
	usart_registers* Instance; 	// UART registers base address
	uart_init uart_config;		// UART Communication paramters
	uint8_t *pTxBuffer;			// Pointer to uart tx buffer
	uint16_t TxSize;			// uart tx transfer size
	uint16_t TxCount;			// uart tx transfer counter
	uint8_t *pRxBuffer;
	uint16_t RxSize;
	uint16_t RxCount;
} uart_handle;

typedef enum {
	HAL_ok  	= 0x0000U,
	HAL_ERROR 	= 0x0001U,
	HAL_BUSY	= 0x0002U,
	HAL_TIMEOUT = 0x0003U
} HAL_StatusTypeDef;

HAL_StatusTypeDef HAL_UART_Init(usart_registers *huart);
HAL_StatusTypeDef HAL_UART_Transmit(usart_registers *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(usart_registers *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);

#endif /* USART_H_ */
