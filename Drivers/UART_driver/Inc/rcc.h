/*
 * rcc.h
 *
 *  Created on: Feb 25, 2025
 *      Author: ghassen
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>

#define RCC_BASE_ADDR  0x40023800

typedef struct {
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
} RCC_registers;

#define RCC ((RCC_registers*) RCC_BASE_ADDR)

#endif /* RCC_H_ */
