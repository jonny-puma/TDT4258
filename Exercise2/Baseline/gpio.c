#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

#include "common.h"

/*
 * function to set up GPIO mode and interrupts
 */
void setupGPIO()
{
	/*
	 * TODO set input and output pins for the joystick 
	 */

	/*
	 * Example of HW access from C code: turn on joystick LEDs D4-D8 check 
	 * efm32gg.h for other useful register definitions 
	 */
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;	/* enable GPIO clock */
	*GPIO_PA_CTRL = 2;	/* set high drive strength */
	*GPIO_PA_MODEH = 0x55555555;	/* set pins A8-15 as output */
	*GPIO_PA_DOUT = 0xff00;	/* turn on LEDs D4-D8 (LEDs are active
				 * low) */
    *GPIO_PC_MODEL = 0x33333333;
    *GPIO_PC_DOUT = 0xff;
    
}

uint32_t readButtons()
{
	// Code to read buttons? 
    uint32_t x = *GPIO_PC_DIN;
    return x;
}

void setLeds(uint32_t buttons)
{
    buttons = (buttons << 8);
    *GPIO_PA_DOUT = buttons;
}

void buttonHandler(){
	uint32_t btns = readButtons();
	switch (btns){
		case BTN1:
			
			break;
		case BTN2:

			break;
		case BTN3:

			break;
		case BTN4:
			
			break;
		
	}
}
