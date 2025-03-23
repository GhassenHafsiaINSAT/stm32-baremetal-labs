/*
 * NUCLEOf401_mem_map.h
 *
 *  Created on: Mar 23, 2025
 *      Author: ghass
 */

#ifndef NUCLEOF401_MEM_MAP_H_
#define NUCLEOF401_MEM_MAP_H_

#include <stdint.h>

////////////////////////////// RCC //////////////////////////////
#define RCC_BASE_ADDRESS  0x40023800

typedef struct{
	uint32_t RCC_CR;
	uint32_t RCC_PLLCFGR;
	uint32_t RCC_CFGR;
	uint32_t RCC_CIR;
	uint32_t RCC_AHB1RSTR;
	uint32_t RCC_AHB2RSTR;
	uint32_t RCC_APB1RSTR;
	uint32_t RCC_APB2RSTR;
	uint32_t RCC_AHB1ENR;
	uint32_t RCC_AHB2ENR;
	uint32_t RCC_APB1ENR;
	uint32_t RCC_APB2ENR;
	uint32_t RCC_AHB1LPENR;
	uint32_t RCC_AHB2LPENR;
	uint32_t RCC_APB1LPENR;
	uint32_t RCC_APB2LPENR;
	uint32_t RCC_BDCR;
	uint32_t RCC_CSR;
	uint32_t RCC_SSCGR;
	uint32_t RCC_PLLI2SCFGR;
	uint32_t RCC_DCKCFGR;
} RCC_Typedef;

#define RCC ((RCC_Typedef*) RCC_BASE_ADDRESS)

////////////////////////////// GPIO //////////////////////////////
#define   RCC_AHB1ENR     (uint32_t*)0x40023830

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS 	0x40020400
#define GPIOC_BASE_ADDRESS 	0x40020800
#define GPIOD_BASE_ADDRESS 	0x40020C00

typedef struct{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEEDR;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
} GPIO_Typedef;

#define GPIOA ((GPIO_Typedef*) GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_Typedef*) GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_Typedef*) GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_Typedef*) GPIOD_BASE_ADDRESS)

////////////////////////////// USART //////////////////////////////

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

#endif /* NUCLEOF401_MEM_MAP_H_ */
