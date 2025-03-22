/*
 * rcc.h
 *
 *  Created on: Mar 22, 2025
 *      Author: ghass
 */

#ifndef RCC_H_
#define RCC_H_

// System Clock Sources
#define RCC_SYSCLK_HSI   0
#define RCC_SYSCLK_HSE   1
#define RCC_SYSCLK_PLL   2

// AHB, APB Prescalers
#define RCC_AHB_PRESCALER_1   0x0
#define RCC_AHB_PRESCALER_2   0x8
#define RCC_AHB_PRESCALER_4   0x9
#define RCC_AHB_PRESCALER_8   0xA
#define RCC_AHB_PRESCALER_16  0xB

#define RCC_APB_PRESCALER_1   0x0
#define RCC_APB_PRESCALER_2   0x4
#define RCC_APB_PRESCALER_4   0x5
#define RCC_APB_PRESCALER_8   0x6
#define RCC_APB_PRESCALER_16  0x7

// Bus Types
#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2

// Example Peripheral Macros (specific to STM32)
#define RCC_GPIOA   (1 << 0)
#define RCC_GPIOB   (1 << 1)
#define RCC_USART1  (1 << 4)
#define RCC_TIM2    (1 << 0)


void RCC_EnableHSI(void);
void RCC_EnableHSE(void);
void RCC_EnablePLL(uint8_t source, uint8_t mul_factor);
void RCC_SetSysClock(uint8_t source);
uint32_t RCC_GetSysClock(void);


void RCC_SetAHBPrescaler(uint8_t prescaler);
void RCC_SetAPB1Prescaler(uint8_t prescaler);
void RCC_SetAPB2Prescaler(uint8_t prescaler);
uint32_t RCC_GetAHBClock(void);
uint32_t RCC_GetAPB1Clock(void);
uint32_t RCC_GetAPB2Clock(void);

void RCC_EnablePeripheralClock(uint8_t bus, uint32_t peripheral);
void RCC_DisablePeripheralClock(uint8_t bus, uint32_t peripheral);

#endif /* RCC_H_ */
