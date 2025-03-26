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
			SPI1_CLK_DIS()();
		}
		else if (SPIx == SPI2){
			SPI2_CLK_DIS()();
		}
		else if (SPIx == SPI3){
			SPI3_CLK_DIS()();
		}
		else if (SPIx == SPI4){
			SPI4_CLK_DIS()();
		}
	}

}
void SPI_Init(SPI_Handle_t* Spi_handler){

}
