/*
 * gpio.h
 *
 *  Created on: Feb 15, 2025
 *      Author: ghassen
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stdint.h>
#include "NUCLEOf401_mem_map.h"

typedef struct {
	uint32_t GPIO_PIN;
	uint32_t GPIO_Mode;
    uint32_t GPIO_Otyper;
    uint32_t GPIO_Ospeeder;
	uint32_t GPIO_PullPush;
} GPIO_Struct;


#define GPIO_Mode_INPUT 		0x00000000
#define GPIO_Mode_OUTPUT 		0x00000001
#define GPIO_Mode_ALTERNATE 	0x00000002
#define GPIO_Mode_ANALOG 		0x00000003

#define OUTPUT_PUSH_PULL 		0x00000000
#define OUTPUT_OPEN_DRAIN 		0x00000001

#define LOW_SPEED 				0x00000000
#define MEDIUM_SPEED 			0x00000001
#define HIGH_SPEED 				0x00000002
#define VERY_HIGH_MODE 			0x00000003

#define GPIO_PullPush_NoPull 	0x00000000
#define PULL_UP 				0x00000001
#define PULL_DOWN 				0x00000002


#define GPIO_PIN_0 	((uint16_t)0x0001)
#define GPIO_PIN_1 	((uint16_t)0x0002)
#define GPIO_PIN_2 	((uint16_t)0x0004)
#define GPIO_PIN_3 	((uint16_t)0x0008)
#define GPIO_PIN_4 	((uint16_t)0x0010)
#define GPIO_PIN_5 	((uint16_t)0x0020)
#define GPIO_PIN_6 	((uint16_t)0x0040)
#define GPIO_PIN_7 	((uint16_t)0x0080)
#define GPIO_PIN_8 	((uint16_t)0x0100)
#define GPIO_PIN_9	((uint16_t)0x0200)
#define GPIO_PIN_10 ((uint16_t)0x0400)
#define GPIO_PIN_11 ((uint16_t)0x0800)
#define GPIO_PIN_12	((uint16_t)0x1000)
#define GPIO_PIN_13	((uint16_t)0x2000)
#define GPIO_PIN_14	((uint16_t)0x4000)
#define GPIO_PIN_15	((uint16_t)0x8000)

int GPIO_ReadPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_SetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_ResetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_TogglePin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN);
void GPIO_Init(GPIO_Typedef* GPIOx, GPIO_Struct* gpio);

#endif /* INC_GPIO_H_ */

