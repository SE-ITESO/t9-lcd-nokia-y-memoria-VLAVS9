/*
 * Memory.c
 *
 *  Created on: 16 abr. 2024
 *      Author: Miguel Vladimir Vargas
 *      Elian Gutierrez Alvarez
 */

#include "fsl_dspi.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "fsl_clock.h"
#include "Memory.h"
#include "bits.h"

uint8_t image1[IMAGE_SIZE] = {BEGIN};

uint8_t image2[IMAGE_SIZE] = {BEGIN};

uint8_t image3[IMAGE_SIZE] = {BEGIN};

uint8_t image4[IMAGE_SIZE] = {BEGIN};

uint8_t image5[IMAGE_SIZE] = {BEGIN};

uint8_t * images[IMAGE_QUANTITY] =	{
			image1,
			image2,
			image3,
			image5,
			image5
};

uint8_t* mem_read(uint32_t imageSize, uint32_t imageAddress, uint8_t data) {
    dspi_half_duplex_transfer_t config;

    //Se establece la direccion en 3 partes y la instruccion de leer
    uint8_t instruccion_addres[DATA_SIZE];
    instruccion_addres[BEGIN] = READ_DATA_INSTRUCTION;
    instruccion_addres[ONE] = (uint8_t)(imageAddress >> HIGH_PART);
    instruccion_addres[TWO] = (uint8_t)(imageAddress >> MID_PART);
    instruccion_addres[TRHREE] = (uint8_t)(imageAddress);

    config.txData                = instruccion_addres;
    config.rxData                = images[data];
    config.txDataSize            = DATA_SIZE;
    config.rxDataSize            = imageSize;
    config.isTransmitFirst       = TRUE;
    config.isPcsAssertInTransfer = TRUE;
    config.configFlags           = kDSPI_MasterCtar1 | kDSPI_MasterPcs1 | kDSPI_MasterPcsContinuous;


    DSPI_MasterHalfDuplexTransferBlocking(SPI0, &config);

    // Return pointer to the requested image data
    return images[data];
}


void mem_config(){

	uint32_t srcClock_Hz;

	CLOCK_SetSimSafeDivs();

	dspi_master_config_t config;

	CLOCK_EnableClock(kCLOCK_PortC);
	CLOCK_EnableClock(kCLOCK_PortD);

	PORT_SetPinMux(PORTC, TRHREE, kPORT_MuxAlt2);			//CE
	PORT_SetPinMux(PORTD, ONE, kPORT_MuxAlt2);			//CLOCK
	PORT_SetPinMux(PORTD, TWO, kPORT_MuxAlt2);			//MOSI
	PORT_SetPinMux(PORTD, TRHREE, kPORT_MuxAlt2);			//MISO

	//SPI memory config
	config.whichCtar                                = kDSPI_Ctar1;
	config.ctarConfig.baudRate                      = MEM_BAUD_RATE;
	config.ctarConfig.bitsPerFrame                  = BITS_PER_FRAME;
	config.ctarConfig.cpol                          = kDSPI_ClockPolarityActiveLow; 	//CPOL = 1
	config.ctarConfig.cpha                          = kDSPI_ClockPhaseSecondEdge;		//CPHASE = 1
	config.ctarConfig.direction                     = kDSPI_MsbFirst;
	config.ctarConfig.pcsToSckDelayInNanoSec        = SEC_NS/MEM_BAUD_RATE;
	config.ctarConfig.lastSckToPcsDelayInNanoSec    = SEC_NS/MEM_BAUD_RATE;
	config.ctarConfig.betweenTransferDelayInNanoSec = SEC_NS/MEM_BAUD_RATE;

	config.whichPcs           = kDSPI_Pcs1;
	config.pcsActiveHighOrLow = kDSPI_PcsActiveLow;

	config.enableContinuousSCK        = FALSE;
	config.enableRxFifoOverWrite      = FALSE;
	config.enableModifiedTimingFormat = FALSE;
	config.samplePoint                = kDSPI_SckToSin0Clock;

	srcClock_Hz = CLOCK_GetFreq(DSPI0_CLK_SRC);
	DSPI_MasterInit(SPI0, &config, srcClock_Hz);

}


