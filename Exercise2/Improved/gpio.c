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

	// Setup GPIO interrupts
	*GPIO_EXTIPSELL = 0x22222222;	// Pins 0-7 of PORTC set as external interrupt
	*GPIO_EXTIFALL = 0xff;		  	// Sets interrupt on 0->1 
	*GPIO_IEN = 0xff;			      	// Enable interrupt
	*GPIO_IFC = 0xffff;			    	// Clearing all interrupt flags
}

void buttonhandler(soundname *current_sound)
{
	uint32_t butval = *GPIO_PC_DIN;
	butval = (~butval) & 0xff;
	switch (butval) {
		case BTN1:
			*GPIO_PA_DOUT = 0xfe00;
			setsound(FLAAKLYPA);
			break;
		case BTN2:
			*GPIO_PA_DOUT = 0xfd00;
			setsound(COIN);
			break;
		case BTN3:
			*GPIO_PA_DOUT = 0xfb00;
			setsound(CRASH);
			break;
		case BTN4:
			*GPIO_PA_DOUT = 0xf700;
			setsound(FLAP);
			break;
		case BTN6:
			*GPIO_PA_DOUT = 0xf000;
			increasevol();
			break;
		case BTN8:
			*GPIO_PA_DOUT = 0x0f00;
			decreasevol();
			break;
	}
}
