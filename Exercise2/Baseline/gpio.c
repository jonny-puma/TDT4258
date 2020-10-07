#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

#include "common.h"
#include "music.h"

/*
 * function to set up GPIO mode and interrupts
 */
void setupGPIO()
{
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
  uint32_t butval = *GPIO_PC_DIN;
  butval = ~butval;
	switch (butval){
		case BTN1:
      changesong(FLAAKLYPA);
			break;

		case BTN2:
      changesong(COIN);
			break;

		case BTN3:
      changesong(JUMP);
			break;

		case BTN4:
			changesong(DEATH);
			break;
		
		case BTN6:
			increaseVolume();
			break;
		
		case BTN8:
			decreaseVolume();
			break;

		default:
			// Do nothing
			break;
	}
}
