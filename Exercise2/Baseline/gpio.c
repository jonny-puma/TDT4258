#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"


void setupGPIO()
{
	// Enable GPIO clock
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;

	// set pins A0-7 as input
    *GPIO_PC_MODEL = 0x33333333;
    *GPIO_PC_DOUT = 0xff;

	// set high drive strength 
	*GPIO_PA_CTRL = 2;	
	// set pins A8-15 as output 
	*GPIO_PA_MODEH = 0x55555555;	
	// turn off LEDs D4-D8 (LEDs are active low)
	*GPIO_PA_DOUT = 0xff00;
}

void buttonHandler(){
	uint32_t x = *GPIO_PC_DIN;
	x = x & 0x000f;
	switch (x) {
		case BTN2:
			*CURRENT_SONG = COIN;
			*GPIO_PA_DOUT = 0xfd00;
			resetSong();
			break;

		case BTN6:
			increaseVolume();
			*GPIO_PA_DOUT = 0xf000;
			break;
		
		case BTN8:
			decreaseVolume();
			*GPIO_PA_DOUT = 0x0f00;
			break;

		default:
			*CURRENT_SONG = NONE; 
			*GPIO_PA_DOUT = 0x5500;
			break;
	}
}
