/*
 * NUCLEOf401_mem_map.h
 *
 *  Created on: Mar 23, 2025
 *      Author: ghass
 */

#ifndef NUCLEOF401_MEM_MAP_H_
#define NUCLEOF401_MEM_MAP_H_

#include <stdint.h>
#define __vo volatile

#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET 	SET
#define GPIO_PIN_RESET 	RESET

////////////////////////////// RCC //////////////////////////////

#define RCC_BASE_ADDRES 0x40023800

typedef struct{
	__vo uint32_t RCC_CR;
	__vo uint32_t RCC_PLLCFGR;
	__vo uint32_t RCC_CFGR;
	__vo uint32_t RCC_CIR;
	__vo uint32_t RCC_AHB1RSTR;
	__vo uint32_t RCC_AHB2RSTR;
	__vo uint32_t RCC_APB1RSTR;
	__vo uint32_t RCC_APB2RSTR;
	__vo uint32_t RCC_AHB1ENR;
	__vo uint32_t RCC_AHB2ENR;
	__vo uint32_t RCC_APB1ENR;
	__vo uint32_t RCC_APB2ENR;
	__vo uint32_t RCC_AHB1LPENR;
	__vo uint32_t RCC_AHB2LPENR;
	__vo uint32_t RCC_APB1LPENR;
	__vo uint32_t RCC_APB2LPENR;
	__vo uint32_t RCC_BDCR;
	__vo uint32_t RCC_CSR;
	__vo uint32_t RCC_SSCGR;
	__vo uint32_t RCC_PLLI2SCFGR;
	__vo uint32_t RCC_DCKCFGR;
} RCC_Typedef_t;

#define RCC ((RCC_Typedef_t*) RCC_BASE_ADDRES)

////////////////////////////// EXTI //////////////////////////////

#define EXTI_BASE_ADDRESS 0x40013C00

typedef struct{
	__vo uint32_t EXTI_IMR;
	__vo uint32_t EXTI_EMR;
	__vo uint32_t EXTI_RTSR;
	__vo uint32_t EXTI_FTSR;
	__vo uint32_t EXTI_SWIER;
	__vo uint32_t EXTI_PR;
}EXTI_Typedef_t;

#define EXTI ((EXTI_Typedef_t*) EXTI_BASE_ADDRESS)
////////////////////////////// GPIO //////////////////////////////

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS 	0x40020400
#define GPIOC_BASE_ADDRESS 	0x40020800
#define GPIOD_BASE_ADDRESS 	0x40020C00

typedef struct{
	__vo uint32_t GPIO_MODER;
	__vo uint32_t GPIO_OTYPER;
	__vo uint32_t GPIO_OSPEEDR;
	__vo uint32_t GPIO_PUPDR;
	__vo uint32_t GPIO_IDR;
	__vo uint32_t GPIO_ODR;
	__vo uint32_t GPIO_BSRR;
	__vo uint32_t GPIO_LCKR;
	__vo uint32_t GPIO_AF[2];
} GPIO_Typdef_t;

#define GPIOA ((GPIO_Typdef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB ((GPIO_Typdef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC ((GPIO_Typdef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD ((GPIO_Typdef_t*) GPIOD_BASE_ADDRESS)

////////////////////////////// SPI //////////////////////////////

#define  SPI1_BASE_ADDRESS 0x40013000
#define  SPI2_BASE_ADDRESS 0x40003800
#define  SPI3_BASE_ADDRESS 0x40003C00
#define  SPI4_BASE_ADDRESS 0x40013400

typedef struct{
	__vo uint32_t SPI_CR1;
	__vo uint32_t SPI_CR2;
	__vo uint32_t SPI_SR;
	__vo uint32_t SPI_DR;
	__vo uint32_t SPI_CRCPR;
	__vo uint32_t SPI_RXCRCR;
	__vo uint32_t SPI_TXCRCR;
	__vo uint32_t SPI_I2SCFGR;
	__vo uint32_t SPI_I2SPR;
}SPI_Typedef_t;

#define SPI1 ((SPI_Typedef_t*)SPI1_BASE_ADDRESS)
#define SPI2 ((SPI_Typedef_t*)SPI2_BASE_ADDRESS)
#define SPI3 ((SPI_Typedef_t*)SPI3_BASE_ADDRESS)
#define SPI4 ((SPI_Typedef_t*)SPI4_BASE_ADDRESS)

#define SPI1_CLK_EN() 	(RCC->RCC_AHB2ENR |= (1 << 12))
#define SPI2_CLK_EN() 	(RCC->RCC_AHB1ENR |= (1 << 14))
#define SPI3_CLK_EN() 	(RCC->RCC_AHB1ENR |= (1 << 15))
#define SPI4_CLK_EN() 	(RCC->RCC_AHB2ENR |= (1 << 13))

#define SPI1_CLK_DIS() 	(RCC->RCC_APB2RSTR |= (1 << 12))
#define SPI2_CLK_DIS() 	(RCC->RCC_APB1RSTR |= (1 << 14))
#define SPI3_CLK_DIS() 	(RCC->RCC_APB1RSTR |= (1 << 15))
#define SPI4_CLK_DIS() 	(RCC->RCC_APB2RSTR |= (1 << 13))

////////////////////////////// USART //////////////////////////////

#define RCC_APB1_ENR ((uint32_t*) 0x40023840)
#define RCC_APB2_ENR ((uint32_t*) 0x40023844)

#define USART1_BASE_ADDRESS 0x40011000		// APB2
#define USART2_BASE_ADDRESS 0x40004400		// APB1
#define USART6_BASE_ADDRESS 0x40011400		// APB2


typedef struct {
	__vo uint32_t USART_SR;
	__vo uint32_t USART_DR;
	__vo uint32_t USART_BRR;
	__vo uint32_t USART_CR1; // enable uart, word parity, word length, interrupts
	__vo uint32_t USART_CR2; // stop bit, clock settings
	__vo uint32_t USART_CR3; // DMA, error detection
	__vo uint32_t USART_GTPR;
} USART_TypeDef;

#define USART1 ((USART_TypeDef*) USART1_BASE_ADDRESS)
#define USART2 ((USART_TypeDef*) USART2_BASE_ADDRESS)
#define USART6 ((USART_TypeDef*) USART6_BASE_ADDRESS)

#define USART1_CLK_EN() 	(RCC->RCC_AHB2ENR |= (1 << 4))
#define USART2_CLK_EN() 	(RCC->RCC_AHB1ENR |= (1 << 17))
#define USART6_CLK_EN() 	(RCC->RCC_AHB2ENR |= (1 << 5))

#define USART1_CLK_DIS() 	(RCC->RCC_APB2RSTR |= (1 << 4))
#define USART2_CLK_DIS() 	(RCC->RCC_APB1RSTR |= (1 << 17))
#define USART6_CLK_DIS() 	(RCC->RCC_APB2RSTR |= (1 << 5))
#endif /* NUCLEOF401_MEM_MAP_H_ */
