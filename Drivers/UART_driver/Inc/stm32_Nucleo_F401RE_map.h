
/*
 * stm32NucleoF401re_MemMap.h
 *
 *  Created on: Feb 15, 2025
 *      Author: ghassen
 */

#ifndef INC_STM32NUCLEOF401RE_MEMMAP_H_
#define INC_STM32NUCLEOF401RE_MEMMAP_H_

#include <stdint.h>
#define   RCC_AHB1ENR     (uint32_t*)0x40023830

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS 	0x40020400
#define GPIOC_BASE_ADDRESS 	0x40020800
#define GPIOD_BASE_ADDRESS 	0x40020C00

#define usart1_base_addr 0x40011000
#define usart2_base_addr 0x40004400
#define usart6_base_addr 0x40011400

typedef struct{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
} GPIO_Typedef;

typedef struct {
	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1; // enable uart, word parity, word length, interrupts
	uint32_t USART_CR2; // stop bit, clock settings
	uint32_t USART_CR3; // DMA, error detection
	uint32_t USART_GTPR;
} usart_registers;

#define GPIOA ((GPIO_Typedef*) GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_Typedef*) GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_Typedef*) GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_Typedef*) GPIOD_BASE_ADDRESS)

#define usart1 ((usart_registers*) usart1_base_addr)
#define usart2 ((usart_registers*) usart2_base_addr)
#define usart6 ((usart_registers*) usart6_base_addr)

#endif /* INC_STM32NUCLEOF401RE_MEMMAP_H_ */

