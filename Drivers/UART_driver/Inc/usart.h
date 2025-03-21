/*
 * uart.h
 *
 *  Created on: Feb 25, 2025
 *      Author: ghass
 */

#ifndef USART_H_
#define USART_H_

#include "stm32_Nucleo_F401RE_map.h"


// USART Clock enable
#define USART1_CLK_EN 0x00000044
#define USART2_CLK_EN 0x00002040
#define USART6_CLK_EN 0x00000064

// USART enable (UE)
#define UART_ENABLE 			0X00002000

// Word length (M)
#define UART_WORDLENGTH_8B 		0
#define UART_WORDLENGTH_9B 		1

// Baudrate
#define USART_STD_BAUD_1200		1200
#define USART_STD_BAUD_2400		400
#define USART_STD_BAUD_9600		9600
#define USART_STD_BAUD_19200 	19200
#define USART_STD_BAUD_38400 	38400
#define USART_STD_BAUD_57600 	57600
#define USART_STD_BAUD_115200 	115200
#define USART_STD_BAUD_230400 	230400
#define USART_STD_BAUD_460800 	460800
#define USART_STD_BAUD_921600 	921600
#define USART_STD_BAUD_2M 		2000000
#define SUART_STD_BAUD_3M 		3000000

// Stop bits
#define UART_STOPBITS_1			0
#define UART_STOPBITS_0_5 		1
#define UART_STOPBITS_2			2
#define UART_STOPBITS_1_5		3

// Parity bit
#define UART_PARITY_ODD			1
#define UART_PARITY_EVEN		0
#define UART_PARITY_DISABLE		0

// MODE
#define UART_MODE_RX			0x00000004
#define UART_MODE_TX			0x00000008
#define UART_MODE_TX_RX			0x0000000C

// HwFlowCtl
#define UART_HWCONTROL_NONE		0
#define UART_HWCONTROL_RTS		1
#define UART_HWCONTROL_CTS		2
#define UART_HWCONTROL_CTS_RTS	3


typedef struct
{
	uint8_t USART_Mode;
	uint32_t USART_Baudrate;
	uint8_t USART_NoOfStopBits;
	uint8_t USART_WordLength;
	uint8_t USART_ParityControl;
	uint8_t USART_HwFloatCtl;
} USART_config_t;

typedef struct
{
	USART_TypeDef* pUSARTx;
	USART_config_t usart_config;

} USART_Handle_t;

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

void USART_Init(USART_Handle_t *pUSARTHandle);

/*
//
//USART_config USART_table[] = {
//		{USART1, USART1_CLK_EN, GPIOA, GPIO_PIN_9, 7, GPIO_PIN_10, 7},
//		{USART2, USART2_CLK_EN, GPIOA, GPIO_PIN_2, 7, GPIO_PIN_3, 7},
//		{USART6, USART6_CLK_EN, GPIOC, GPIO_PIN_6, 8, GPIO_PIN_7, 8},
//};
void USART_PeriClockControl(USART_RegDef_t *pUSARTx, uint8_t EnorDi);


void USART_DeInit(USART_RegDef_t *pUSARTx);



void USART_SendData(USART_RegDef_t *pUSARTx,uint8_t *pTxBuffer, uint32_t Len);
void USART_ReceiveData(USART_RegDef_t *pUSARTx, uint8_t *pRxBuffer, uint32_t Len);
uint8_t USART_SendDataIT(USART_Handle_t *pUSARTHandle,uint8_t *pTxBuffer, uint32_t Len);
uint8_t USART_ReceiveDataIT(USART_Handle_t *pUSARTHandle, uint8_t *pRxBuffer, uint32_t Len);


void USART_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void USART_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void USART_IRQHandling(USART_Handle_t *pHandle);


void USART_PeripheralControl(USART_RegDef_t *pUSARTx, uint8_t EnOrDi);
uint8_t USART_GetFlagStatus(USART_RegDef_t *pUSARTx , uint32_t FlagName);
void USART_ClearFlag(USART_RegDef_t *pUSARTx, uint16_t StatusFlagName);


void USART_ApplicationEventCallback(USART_Handle_t *pUSARTHandle,uint8_t AppEv);
*/
#endif /* USART_H_ */
