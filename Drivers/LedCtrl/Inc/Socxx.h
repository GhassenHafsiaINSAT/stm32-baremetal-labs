/*
 * Socxx.h
 *
 *  Created on: Mar 10, 2025
 *      Author: ghass
 */

#ifndef SOCXX_H_
#define SOCXX_H_

#include <stdint.h>

#define LCD1_BASE_ADDR 0x10010000
#define LCD2_BASE_ADDR 0x10010040

typedef struct{
	uint16_t MODE;
	uint16_t LUM;
	uint16_t POS;
	uint16_t COLOR;
} LCD_typedef;

#define LCD1 ((LCD_typedef*) LCD1_BASE_ADDR)
#define LCD2 ((LCD_typedef*) LCD2_BASE_ADDR)

#endif /* SOCXX_H_ */
