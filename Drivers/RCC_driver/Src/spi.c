/*
 * spi.c
 *
 *  Created on: Mar 26, 2025
 *      Author: ghass
 */
#include "spi.h"

void SPI_PeriClockControl(SPI_Typedef_t* SPIx, uint8_t EnOrDis){
	if (EnOrDis == ENABLE){
		if (SPIx == SPI1){
			SPI1_CLK_EN();
		}
		else if (SPIx == SPI2){
			SPI2_CLK_EN();
		}
		else if (SPIx == SPI3){
			SPI3_CLK_EN();
		}
		else if (SPIx == SPI4){
			SPI4_CLK_EN();
		}
	}
	else if (EnOrDis == DISABLE){
		if (SPIx == SPI1){
			SPI1_CLK_DIS();
		}
		else if (SPIx == SPI2){
			SPI2_CLK_DIS();
		}
		else if (SPIx == SPI3){
			SPI3_CLK_DIS();
		}
		else if (SPIx == SPI4){
			SPI4_CLK_DIS();
		}
	}

}
void SPI_Init(SPI_Handle_t* Spi_handler){
	// enable SPI clock
	SPI_PeriClockControl(Spi_handler->SPIx, ENABLE);

	uint32_t tempReg = 0;

	// CR1 register's configuration
	// SPI device mode
	tempReg |= (Spi_handler->spi_config.SPI_DeviceMode << SPI_CR1_MSTR);

	// Sending Mode
	if (Spi_handler->spi_config.SPI_BusConfig == SPI_BUS_CONFIG_FULL_DUPLEX){
		tempReg &= ~(1 << SPI_CR1_BIDIMODE);
	}
	else if (Spi_handler->spi_config.SPI_BusConfig == SPI_BUS_CONFIG_HALF_DUPLEX){
		tempReg |= (1 << SPI_CR1_BIDIMODE);
	}
	else if (Spi_handler->spi_config.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY){
		tempReg &= ~(1 << SPI_CR1_BIDIMODE);
		tempReg |= (1 << SPI_CR1_RXONLY);
	}

	// Clock Speed
	tempReg |= (Spi_handler->spi_config.SPI_CLK_SPEED << SPI_CR1_BR);

	// Data Format
	tempReg |= (Spi_handler->spi_config.SPI_DFF << SPI_CR1_DFF);

	// CPOL
	tempReg |= (Spi_handler->spi_config.SPI_CPOL << SPI_CR1_CPOL);

	// CPHA
	tempReg |= (Spi_handler->spi_config.SPI_CPHA << SPI_CR1_CPHA);

	Spi_handler->SPIx->SPI_CR1 = tempReg;
}

void SPI_Send(SPI_Typedef_t* SPIx, uint8_t* pTxBuffer, uint32_t len){

	while (len > 0){
		while(!(SPIx->SPI_SR & (1 << SPI_SR_TXE)));
		if (SPIx->SPI_SR & (1 << SPI_CR1_DFF)){
			SPIx->SPI_DR = *((uint16_t*) pTxBuffer);
			pTxBuffer++;
			pTxBuffer++;
			len--;
			len--;
		}
		else {
			SPIx->SPI_DR = *pTxBuffer;
			pTxBuffer++;
			len--;
		}
	}
}

void SPI_Receive(SPI_Typedef_t* SPIx, uint8_t* pRxBuffer, uint32_t len){

	while( len > 0){
		while (!(SPIx->SPI_SR & (1 << SPI_SR_RXNE)));
		if (SPIx->SPI_CR1 & (1 << SPI_CR1_DFF)){
			*((uint16_t*) pRxBuffer) = SPIx->SPI_DR;
			pRxBuffer++;
			pRxBuffer++;
			len--;
			len--;
		}
		else {
			*pRxBuffer = SPIx->SPI_DR;
			pRxBuffer++;
			len--;
		}
	}
}
