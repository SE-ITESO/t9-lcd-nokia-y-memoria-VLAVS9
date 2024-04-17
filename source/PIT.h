/*
 * PIT.h
 *
 *  Created on: 16 abr. 2024
 *      Author: Miguel Vladimir Vargas
 *      Elian Gutierrez Alvarez
 */

#ifndef PIT_H_
#define PIT_H_

#include <stdint.h>

#define PIT_BASEADDR		PIT
#define PIT0_CHANNEL		kPIT_Chnl_0
#define PIT0_IRQ_ID			PIT0_IRQn
#define PIT0_TIME			USEC_TO_COUNT(1500000U, PIT_SOURCE_CLOCK)
#define PIT_SOURCE_CLOCK	CLOCK_GetFreq(kCLOCK_BusClk)
#define CALLBACK_INIT 0
/*! These constants are used to select an specific port in the different API functions */
typedef enum {

	PIT_0,	/*!< Definition to select PIT0 */
	PIT_1,	/*!< Definition to select PIT1 */
	PIT_2,	/*!< Definition to select PIT2 */
	PIT_3,	/*!< Definition to select PIT3 */

} pit_t;

void PIT_callback_init(pit_t pit, void (*handler)(void));	//void -> uint32_t flags
void PIT0_init(void);
void PIT0_stop(void);

#endif /* PIT_H_ */
