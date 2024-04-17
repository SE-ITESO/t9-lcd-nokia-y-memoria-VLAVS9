/*
 * PIT.c
 *
 *  Created on: 16 abr. 2024
 *      Author: miguelvladimirvargassanchez
 */

#include "PIT.h"
#include "ImageDisplay.h"
#include <fsl_pit.h>


static void (*pit_0_callback)(void) = CALLBACK_INIT;	//void -> uint32_t flags
static void (*pit_1_callback)(void) = CALLBACK_INIT;	//void -> uint32_t flags
static void (*pit_2_callback)(void) = CALLBACK_INIT;	//void -> uint32_t flags
static void (*pit_3_callback)(void) = CALLBACK_INIT;	//void -> uint32_t flags

void PIT_callback_init(pit_t pit, void (*handler)(void)) {

	if(PIT_0 == pit) {

		pit_0_callback = handler;

	}
	else if(PIT_1 == pit) {

		pit_1_callback = handler;

	}
	else if(PIT_2 == pit) {

		pit_2_callback = handler;

	}
	else if(PIT_3 == pit) {

		pit_3_callback = handler;

	}

}

void PIT0_IRQHandler(void) {

	PIT_ClearStatusFlags(PIT_BASEADDR, PIT0_CHANNEL, kPIT_TimerFlag);

	imageDisplaySequence();
	__DSB();

}

void PIT0_init(void) {

	CLOCK_SetSimSafeDivs();
	pit_config_t pitConfig;
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(PIT_BASEADDR, &pitConfig);
	PIT_SetTimerPeriod(PIT_BASEADDR, PIT0_CHANNEL, PIT0_TIME);
	PIT_EnableInterrupts(PIT_BASEADDR, PIT0_CHANNEL, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT0_IRQ_ID);
	PIT_StartTimer(PIT_BASEADDR, PIT0_CHANNEL);

}

void PIT0_stop(void) {

	PIT_ClearStatusFlags(PIT_BASEADDR, PIT0_CHANNEL, kPIT_TimerFlag);
	PIT_StopTimer(PIT_BASEADDR, PIT0_CHANNEL);

}
