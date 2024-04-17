/*
 * Memory.h
 *
 *  Created on: 16 abr. 2024
 *      Author: Miguel Vladimir Vargas
 *      Elian Gutierrez Alvarez
 */

#ifndef MEMORY_H_
#define MEMORY_H_

void mem_config();

uint8_t* mem_read(uint32_t imageSize, uint32_t imageAddress, uint8_t data);

#define READ_DATA_INSTRUCTION         	  0x03U					//Read instruccion opcode
#define MEM_BAUD_RATE           		  2000000U				//2MHZ
#define SEC_NS 							  1000000000U

#define IMAGE_SIZE 			504U
#define BITS_PER_FRAME 		8U
#define DATA_SIZE      		8
#define IMAGE_QUANTITY      5


#define CLOCK_PORT 			1
#define MOSI_PORT  			2
#define MISO_PORT 			3
#define CE_PORT    			3

#define HIGH_PART 			16
#define MID_PART   			8

#define BEGIN 			0
#define ONE   			1
#define TWO 			2
#define TRHREE   	    3

#define IMAGE_0_ADDRES		0x40000U
#define IMAGE_1_ADDRES		0x41000U
#define IMAGE_2_ADDRES		0x42000U
#define IMAGE_3_ADDRES		0x43000U
#define IMAGE_4_ADDRES		0x44000U

#endif /* MEMORY_H_ */
