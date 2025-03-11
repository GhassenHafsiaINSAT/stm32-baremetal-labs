/*
 * gpio.c
 *
 *  Created on: Mar 2, 2025
 *      Author: ghass
 */

#include "gpio.h"
#include "rcc.h"



void GPIO_SetAF(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t AF)
{
    if (pin < 8) {
        GPIOx->AFRL &= ~(0xF << (4 * pin));
        GPIOx->AFRL |= (AF << (4 * pin));
    } else {
        GPIOx->AFRH &= ~(0xF << (4 * (pin - 8)));
        GPIOx->AFRH |= (AF << (4 * (pin - 8)));
    }
}

void GPIO_Init(GPIO_Typedef* GPIOx, USART_config* usart){
	RCC->RCC_AHB1ENR  |=  0x00000005;

	GPIOx->MODER &= (~(0x3u << 2* usart->TX_pin) | ~(0x3u << 2* usart->RX_pin));
	GPIOx->MODER |= ((GPIO_Mode_AF_PP << 2* usart->TX_pin) | (GPIO_Mode_AF_PP << 2* usart->RX_pin));

	GPIOx->OTYPER &= (~(0x3u << 2* usart->TX_pin) | ~(0x3u << 2* usart->RX_pin));
	GPIOx->OTYPER |= ((OUTPUT_PUSH_PULL << usart->TX_pin)  | (OUTPUT_PUSH_PULL << usart->RX_pin));

	GPIOx->OSPEEDR &= (~(0x3u << 2* usart->TX_pin) | ~(0x3u << 2* usart->RX_pin));
	GPIOx->OSPEEDR |= ((MEDIUM_SPEED << usart->TX_pin)  | (MEDIUM_SPEED << usart->RX_pin));

	GPIOx->PUPDR &= (~(0x3u << 2* usart->TX_pin) | ~(0x3u << 2* usart->RX_pin));
	GPIOx->PUPDR |= ((OUTPUT_PUSH_PULL << usart->TX_pin) | (OUTPUT_PUSH_PULL << usart->RX_pin));

	GPIO_SetAF(GPIOx, usart->TX_pin, usart->TX_AF);
	GPIO_SetAF(GPIOx, usart->RX_pin, usart->RX_AF);

}
