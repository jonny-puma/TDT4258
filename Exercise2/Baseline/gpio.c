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
}

void buttonHandler(){
	uint32_t x = *GPIO_PC_DIN;
	x = x & 0x00ff;
	switch (x) {
		case BTN2:
			*CURRENT_SONG = COIN;
			resetSong();
			break;
		
		case BTN6:
			increaseVolume();
			break;
		
		case BTN8:
			decreaseVolume();
			break;

		default:
			*CURRENT_SONG = NONE; 
			break;
	}
}
