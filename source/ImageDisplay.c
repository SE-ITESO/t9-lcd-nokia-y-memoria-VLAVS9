/*
 * ImageDisplay.c
 *
 *  Created on: 16 abr. 2024
 *      Author: Miguel Vladimir Vargas
 *      Elian Gutierrez Alvarez
 */
#include "LCD_nokia.h"
#include "LCD_nokia_images.h"
#include "stdint.h"
#include "ImageDisplay.h"
#include "SPI.h"
#include "Memory.h"
#include "PIT.h"

#include "stdint.h"
uint8_t image = 0;

uint8_t selector = 0;

void imageDisplaySequence() {

	LCD_nokia_clear();

	switch(selector) {

		case CASE_ITESO:
			LCD_nokia_bitmap(getITESO());
			break;
		case CASE_IMAGE1:
			LCD_nokia_bitmap(mem_read(IMAGE_SIZE, IMAGE_0_ADDRES, 0));
			break;

		case CASE_IMAGE2:
			LCD_nokia_bitmap(mem_read(IMAGE_SIZE, IMAGE_1_ADDRES, 1));
			break;

		case CASE_IMAGE3:
			LCD_nokia_bitmap(mem_read(IMAGE_SIZE, IMAGE_2_ADDRES, 2));
			break;

		case CASE_IMAGE4:
			LCD_nokia_bitmap(mem_read(IMAGE_SIZE, IMAGE_3_ADDRES, 3));
			break;

		case CASE_IMAGE5:
			LCD_nokia_bitmap(mem_read(IMAGE_SIZE, IMAGE_4_ADDRES, 4));
			break;

		default:
			LCD_nokia_clear();
			break;

	}

	if(NO_IMAGES <= selector) {

		selector = IMAGE_INITIAL_VALUE;

	}
	else {

		selector++;

	}

}
