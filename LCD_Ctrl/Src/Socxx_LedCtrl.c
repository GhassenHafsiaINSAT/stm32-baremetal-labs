/*
 * Socxx_LedCtrl.c
 *
 *  Created on: Mar 10, 2025
 *      Author: ghass
 */

#include "SocxxLedCtrl.h"

void lcdinit(LCD_typedef* LCDx, Lcd_InitTypeDef* config){
	uint8_t position;

	for (uint8_t i = 0; i<4; i++){
		uint8_t pin = 1<<i;
		uint8_t target_pin = config->Led_Id & pin;
		if (target_pin == pin){
			LCDx->MODE &= ~(0x3u << i*2);
			LCDx->MODE |= config->LedMode << i*2;

			LCDx->LUM &= ~(0x3u << i*2);
			LCDx->LUM |= config->LedLum << i*2;
		}
	}

	LCDx->POS &= ~(0x256u);
	LCDx->POS |= config->Xpos;

	LCDx->POS &= ~(0x256u << 8);
	LCDx->POS |= config->Ypos;

	LCDx->COLOR &= ~(0x31u);
	LCDx->COLOR |= config->Red;

	LCDx->COLOR &= ~(0x31u << 5);
	LCDx->COLOR |= config->Green;

	LCDx->POS &= ~(0x31u << 10);
	LCDx->COLOR |= config->Blue;



}

