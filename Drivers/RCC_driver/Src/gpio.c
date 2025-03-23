/*
 * gpio.c
 *
 *  Created on: Feb 15, 2025
 *      Author: ghassen
 */
#include "gpio.h"
#include "rcc.h"

int GPIO_ReadPin(GPIO_Typdef_t* GPIOx, uint16_t GPIO_PIN){
	if ((GPIOx->GPIO_IDR & GPIO_PIN) == 0)
		return 0;
	else
		return 1;
}

void GPIO_SetPin(GPIO_Typdef_t* GPIOx, uint16_t GPIO_PIN){
	GPIOx->GPIO_BSRR = ((uint32_t) GPIO_PIN);
}

void GPIO_ResetPin(GPIO_Typdef_t* GPIOx, uint16_t GPIO_PIN){
	GPIOx->GPIO_BSRR = ((uint32_t) GPIO_PIN ) << 16;
}

void GPIO_TogglePin(GPIO_Typdef_t* GPIOx, uint16_t GPIO_PIN){
	if ((GPIOx->GPIO_IDR & GPIO_PIN) == 0)
		GPIOx->GPIO_BSRR = GPIO_PIN;
	else
		GPIOx->GPIO_BSRR = GPIO_PIN << 16;
}

void GPIO_CLK_Ctrl(GPIO_Typdef_t* GPIOx, uint8_t control){
	if (control == ENABLE){
		if (GPIOx == GPIOA){
			RCC->RCC_AHB1ENR |= (1 << 0);
		}
		else if (GPIOx == GPIOB){
			RCC->RCC_AHB1ENR |= (1 << 1);
		}
		else if (GPIOx == GPIOC){
			RCC->RCC_AHB1ENR |= (1 << 2);
		}
		else if (GPIOx == GPIOD){
			RCC->RCC_AHB1ENR |= (1 << 3);
		}
	}
	else if (control == DISABLE){
		if (GPIOx == GPIOA){
			RCC->RCC_AHB1RSTR |= (1 << 0);
		}
		else if (GPIOx == GPIOB){
			RCC->RCC_AHB1RSTR |= (1 << 1);
		}
		else if (GPIOx == GPIOC){
			RCC->RCC_AHB1RSTR |= (1 << 2);
		}
		else if (GPIOx == GPIOD){
			RCC->RCC_AHB1RSTR |= (1 << 3);
		}
	}
}
void GPIO_Init(GPIO_Typdef_t* GPIOx, GPIO_PinConfig_t* gpio){

	uint32_t pin = 0x00u;
	uint32_t target_pin = 0x00u;
	for (uint32_t position = 0; position < 16; position++){
		pin = 0x01u << position;
		target_pin = (gpio->GPIO_PIN) & pin;
		if (target_pin == pin){
			GPIOx->GPIO_MODER &= ~(0x3u << 2*position);
			GPIOx->GPIO_MODER |= (gpio->GPIO_Mode) << 2*position;

			GPIOx->GPIO_OTYPER &= ~(0x3u << 2*position);
			GPIOx->GPIO_OTYPER |= (gpio->GPIO_Otyper) << 2*position;

			GPIOx->GPIO_OSPEEDR &= ~(0x3u << 2*position);
			GPIOx->GPIO_OSPEEDR |= (gpio->GPIO_Ospeeder) << 2*position;

			GPIOx->GPIO_PUPDR &= ~(0x3u << 2*position);
			GPIOx->GPIO_PUPDR |= (gpio->GPIO_PullPush) << 2*position;

			if (gpio->GPIO_Mode == GPIO_MODE_ALTERNATE){
				uint32_t AF_reg = gpio->GPIO_PIN / 8;
				uint32_t AFx = gpio->GPIO_PIN % 8;
				GPIOx->GPIO_AF[AF_reg] |= (gpio->GPIO_AF << AFx * 4);
			}
		}
	}
}

void GPIO_DeInit(GPIO_Typdef_t* GPIOx){
	GPIO_CLK_Ctrl(GPIOx, DISABLE);
}

