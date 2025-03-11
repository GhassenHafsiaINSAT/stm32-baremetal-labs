/*
 * uart.h
 *
 *  Created on: Feb 25, 2025
 *      Author: ghass
 */

#ifndef UART_H_
#define UART_H_

#include "stm32_Nucleo_F401RE_map.h"
#include "gpio.h"
#include "rcc.h"

// USART Clock enable
#define USART1_CLK_EN 0x00000044
#define USART2_CLK_EN 0x00002040
#define USART6_CLK_EN 0x00000064

// USART enable (UE)
#define UART_ENABLE 			0X00002000

// Word length (M)
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
	USART_TypeDef* Instance; 	// UART registers base address
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

typedef struct{
	USART_TypeDef* uart_instance;
	uint32_t usart_clk_enable;
	GPIO_Typedef* gpio_instance;
	uint16_t TX_pin;
	uint8_t TX_AF;
	uint32_t RX_pin;
	uint8_t RX_AF;
} USART_config;
//
//USART_config USART_table[] = {
//		{USART1, USART1_CLK_EN, GPIOA, GPIO_PIN_9, 7, GPIO_PIN_10, 7},
//		{USART2, USART2_CLK_EN, GPIOA, GPIO_PIN_2, 7, GPIO_PIN_3, 7},
//		{USART6, USART6_CLK_EN, GPIOC, GPIO_PIN_6, 8, GPIO_PIN_7, 8},
//};

#endif /* UART_H_ */
