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

uint32_t buttonHandler(uint32_t C_s){
	uint32_t x = *GPIO_PC_DIN;
	x = (~x)&0xff;
	switch (x) {
		case BTN1:
			C_s = 1;
			resetSong( C_s );
			return C_s;
			break;

		case BTN2:
			C_s = 2;
			resetSong( C_s );
			return C_s;
			break;

		case BTN6:
			increaseVolume();
			return C_s;
			break;
		
		case BTN8:
			decreaseVolume();
			return C_s;
			break;

		default:
			return C_s;
			break; 
	}
	return C_s;
}
