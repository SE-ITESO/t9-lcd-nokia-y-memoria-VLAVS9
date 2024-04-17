#include "fsl_gpio.h"
#include "fsl_port.h"
#include "SPI.h"
#include "LCD_nokia.h"
#include "stdint.h"
#include "fsl_dspi.h"
#include "LocalImage.h"


void LCD_nokia_init(void)
{

	gpio_pin_config_t led_config = {
		        kGPIO_DigitalOutput,
		        1,
		    };

		CLOCK_EnableClock(kCLOCK_PortD);
		CLOCK_EnableClock(kCLOCK_PortC);

		PORT_SetPinMux(PORT_DATA_OR_CMD_PIN, DATA_OR_CMD_PIN, kPORT_MuxAsGpio);
		PORT_SetPinMux(PORT_RESET_PIN, RESET_PIN, kPORT_MuxAsGpio);

		GPIO_PinInit(GPIO_DATA_OR_CMD_PIN, DATA_OR_CMD_PIN, &led_config);
		GPIO_PinInit(GPIO_RESET_PIN, RESET_PIN, &led_config);

		GPIO_PortClear(GPIO_RESET_PIN, 1u << RESET_PIN);
		LCD_nokia_delay();
		GPIO_PortSet(GPIO_RESET_PIN, 1u << RESET_PIN);

		LCD_nokia_write_byte(LCD_CMD, 0x21); //Tell LCD that extended commands follow
		LCD_nokia_write_byte(LCD_CMD, 0xB1); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
		LCD_nokia_write_byte(LCD_CMD, 0x04); //Set Temp coefficent
		LCD_nokia_write_byte(LCD_CMD, 0x14); //LCD bias mode 1:48: Try 0x13 or 0x14

		LCD_nokia_write_byte(LCD_CMD, 0x20); //We must send 0x20 before modifying the display control mode
		LCD_nokia_write_byte(LCD_CMD, 0x0C); //Set display control, normal mode. 0x0D for inverse



}

void LCD_nokia_bitmap(const uint8_t bitmap[]){

	uint16_t index=0;
   for (index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++)
   	  LCD_nokia_write_byte( LCD_DATA, *(bitmap + index));
}



void LCD_nokia_write_byte(uint8_t data_or_command, uint8_t data)
{
	dspi_transfer_t masterXfer;

	if(data_or_command)
		GPIO_PortSet(GPIO_DATA_OR_CMD_PIN, 1u << DATA_OR_CMD_PIN);
	else
		GPIO_PortClear(GPIO_DATA_OR_CMD_PIN, 1u << DATA_OR_CMD_PIN);

	  /**
  Falta codigo SPI transfer

  **/
	masterXfer.txData      = &data;
		masterXfer.rxData      = NULL;
		masterXfer.dataSize    = 1;
		masterXfer.configFlags = kDSPI_MasterCtar0 | kDSPI_MasterPcs0 | kDSPI_MasterPcsContinuous;
		DSPI_MasterTransferBlocking(SPI0, &masterXfer);

}





void LCD_nokia_clear(void) {
	uint16_t index = 0;
  for (index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++)
	  LCD_nokia_write_byte(LCD_DATA, 0x00);
  LCD_nokia_goto_xy(0, 0); //After we clear the display, return to the home position
}

void LCD_nokia_goto_xy(uint8_t x, uint8_t y) {
	LCD_nokia_write_byte(LCD_CMD, 0x80 | x);  // Column.
	LCD_nokia_write_byte(LCD_CMD, 0x40 | y);  // Row.  ?
}

void LCD_nokia_delay(void)
{
	int counter;

	for(counter=0; counter<1500; counter++)
	{

	}
}
