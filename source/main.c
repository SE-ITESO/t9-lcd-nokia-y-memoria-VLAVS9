/*
 * ImageDisplay.c
 *
 *  Created on: 16 abr. 2024
 *      Author: miguelvladimirvargassanchez
 *      Elian Gutierrez Alvarez
 */

#include "LCD_nokia.h"
#include "stdint.h"
#include "SPI.h"
#include "Memory.h"
#include "PIT.h"
#include "NVIC.h"


int main(void)
{

	SPI_config();
	mem_config();
	LCD_nokia_init();

	PIT0_init();

	NVIC_set_basepri_threshold(PRIORITY_2);

	NVIC_enable_interrupt_and_priotity(PIT_CH0_IRQ, PRIORITY_1);

	NVIC_global_enable_interrupts;

	while(1);

	return 0;
}

