/*
 * gpio.c
 *
 *  Created on: Feb 15, 2025
 *      Author: ghassen
 */
#include "gpio.h"

int GPIO_ReadPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN){
	if ((GPIOx->IDR & GPIO_PIN) == 0)
		return 0;
	else
		return 1;
}

void GPIO_SetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN){
	GPIOx->BSRR = GPIO_PIN;
}

void GPIO_ResetPin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN){
	GPIOx->BSRR = GPIO_PIN << 16;
}

void GPIO_TogglePin(GPIO_Typedef* GPIOx, uint16_t GPIO_PIN){
	if ((GPIOx->IDR & GPIO_PIN) == 0)
		GPIOx->BSRR = GPIO_PIN;
	else
		GPIOx->BSRR = GPIO_PIN << 16;
}


void GPIO_Init(GPIO_Typedef* GPIOx, GPIO_Struct* gpio){

	uint32_t pin = 0x00u;
	uint32_t target_pin = 0x00u;
	for (uint32_t position = 0; position < 16; position++){
		pin = 0x01u << position;
		target_pin = (gpio->GPIO_PIN) & pin;
		if (target_pin == pin){
			GPIOx->MODER &= ~(0x3u << 2*position);
			GPIOx->MODER |= (gpio->GPIO_Mode) << 2*position;

			GPIOx->OTYPER &= ~(0x3u << 2*position);
			GPIOx->OTYPER |= (gpio->GPIO_Otyper) << 2*position;

			GPIOx->OSPEEDR &= ~(0x3u << 2*position);
			GPIOx->OSPEEDR |= (gpio->GPIO_Ospeeder) << 2*position;

			GPIOx->PUPDR &= ~(0x3u << 2*position);
			GPIOx->PUPDR |= (gpio->GPIO_PullPush) << 2*position;
		}
	}
}

