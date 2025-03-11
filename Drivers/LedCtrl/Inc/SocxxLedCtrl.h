/*
 * SocxxLedCtrl.h
 *
 *  Created on: Mar 10, 2025
 *      Author: ghass
 */

#ifndef SOCXXLEDCTRL_H_
#define SOCXXLEDCTRL_H_

#include "Socxx.h"

typedef struct{
	uint8_t Led_Id;
	uint8_t LedMode;
	uint8_t LedLum;
	uint8_t Xpos;
	uint8_t Ypos;
	uint8_t Red;
	uint8_t Green;
	uint8_t Blue;
} Lcd_InitTypeDef;

#define MODE_INACTIF 		0x00
#define MODE_NOIR_BLANC 	0x01
#define MODE_NIVEAU_GRIS 	0x02
#define MODE_COULEUR 		0x03
#define LUM_FAIBLE 			0x00
#define LUM_MOYEN 			0x01
#define LUM_FORT 			0x02
#define LUM_TRES_FORT 		0x03

#define LCD_0	0x01
#define LCD_1	0x02
#define LCD_2 	0x04
#define LCD_3	0x08

void lcdinit(LCD_typedef* LCDx, Lcd_InitTypeDef* config);

#endif /* SOCXXLEDCTRL_H_ */
