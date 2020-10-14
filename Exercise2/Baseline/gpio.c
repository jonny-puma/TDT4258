#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"


void setupGPIO() {
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;
    *GPIO_PC_MODEL = 0x33333333;
    *GPIO_PC_DOUT = 0xff;
	*GPIO_PA_CTRL = 2; 
	*GPIO_PA_MODEH = 0x55555555;
	*GPIO_PA_DOUT = 0xff00;
}

int buttonHandler( int C_s){
	uint32_t x = *GPIO_PC_DIN;
	x 		   = (~x)&0xff;

	switch (x) {
		case BTN1:
			*GPIO_PA_DOUT = 0xfe00;
			resetSong( 1 );
			return 1;
			break;
		case BTN2:
			*GPIO_PA_DOUT = 0xfd00;
			resetSong( 2 );
			return 2;
			break;

		case BTN6:
			increaseVolume();
			*GPIO_PA_DOUT = 0xf000;
			break;
		
		case BTN8:
			decreaseVolume();
			*GPIO_PA_DOUT = 0x0f00;
			break;
	}
	return C_s;
}