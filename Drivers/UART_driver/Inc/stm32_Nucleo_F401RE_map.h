
/*
 * stm32NucleoF401re_MemMap.h
 *
 *  Created on: Feb 15, 2025
 *      Author: ghassen
 */

#ifndef INC_STM32NUCLEOF401RE_MEMMAP_H_
#define INC_STM32NUCLEOF401RE_MEMMAP_H_

#include <stdint.h>

#define RCC_APB1_ENR ((uint32_t*) 0x40023840)
#define RCC_APB2_ENR ((uint32_t*) 0x40023844)

#define USART1_BASE_ADDRESS 0x40011000		// APB2
#define USART2_BASE_ADDRESS 0x40004400		// APB1
#define USART6_BASE_ADDRESS 0x40011400		// APB2


typedef struct {
	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1; // enable uart, word parity, word length, interrupts
	uint32_t USART_CR2; // stop bit, clock settings
	uint32_t USART_CR3; // DMA, error detection
	uint32_t USART_GTPR;
} USART_TypeDef;

#define USART1 ((USART_TypeDef*) USART1_BASE_ADDRESS)
#define USART2 ((USART_TypeDef*) USART2_BASE_ADDRESS)
#define USART6 ((USART_TypeDef*) USART6_BASE_ADDRESS)

#endif /* INC_STM32NUCLEOF401RE_MEMMAP_H_ */

