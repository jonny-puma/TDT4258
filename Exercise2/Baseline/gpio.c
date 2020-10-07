#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

#include "common.h"
#include "music.h"

/*
 * function to set up GPIO mode and interrupts
 */
void setupGPIO(){
	// Enable GPIO clock
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;

// Not using LEDs in this implementation
	
	// set high drive strength 
	*GPIO_PA_CTRL = 2;
	// set pins A8-15 as output 
	*GPIO_PA_MODEH = 0x55555555;	
	// turn on LEDs D4-D8 (LEDs are active low)
	*GPIO_PA_DOUT = 0xff00;	
	

	// set pins A0-7 as input
    *GPIO_PC_MODEL = 0x33333333;
    *GPIO_PC_DOUT = 0xff;
}

void buttonHandler(){
	uint32_t btn = *GPIO_PC_DIN;
	btn = (~btn);
	switch (btn){
		case BTN1:
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = FLAAKLYPA;
			resetSong();
			break;

		case BTN2:
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = COIN;
			resetSong();
			break;

		case BTN3:
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = JUMP;
			resetSong();
			break;

		case BTN4:
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = DEATH;
			resetSong();
			break;
		
		case BTN6:
			//*GPIO_PA_DOUT = (~btn)<<8;
			increaseVolume();
			break;
		
		case BTN8:
			//*GPIO_PA_DOUT = (~btn)<<8;
			decreaseVolume();
			break;

		default:
			// Do nothing
			//*GPIO_PA_DOUT = (0x00)<<8;
			break;
	}
}
