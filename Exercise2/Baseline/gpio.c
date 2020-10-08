#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"

<<<<<<< HEAD
/*
 * function to set up GPIO mode and interrupts
 */
void setupGPIO(){
	// Enable GPIO clock
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;

// Not using LEDs in this implementation
	
=======

void setupGPIO()
{
	// Enable GPIO clock
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;

	// set pins A0-7 as input
	*GPIO_PC_MODEL = 0x33333333;
	*GPIO_PC_DOUT = 0xff;

>>>>>>> jonas3
	// set high drive strength 
	*GPIO_PA_CTRL = 2;	
	// set pins A8-15 as output 
	*GPIO_PA_MODEH = 0x55555555;	
<<<<<<< HEAD
	// turn on LEDs D4-D8 (LEDs are active low)
	*GPIO_PA_DOUT = 0xff00;	
	

	// set pins A0-7 as input
    *GPIO_PC_MODEL = 0x33333333;
    *GPIO_PC_DOUT = 0xff;
}

void buttonHandler(){
	uint32_t btn = *GPIO_PC_DIN;
	btn = (~btn)&0xff;
	switch (btn){
		case BTN1:
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = FLAAKLYPA;
			resetSong();
=======
	// turn off LEDs D4-D8 (LEDs are active low)
	*GPIO_PA_DOUT = 0xff00;
}

void buttonhandler(soundname *current_sound, uint32_t *volume)
{
	uint32_t butval = *GPIO_PC_DIN;
	butval = (~butval) & 0xff;
	switch (butval) {
		case BTN1:
			*GPIO_PA_DOUT = 0xfe00;
			*current_sound = FLAAKLYPA;
			setsound(*current_sound);
>>>>>>> jonas3
			break;
		case BTN2:
<<<<<<< HEAD
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = COIN;
			resetSong();
=======
			*GPIO_PA_DOUT = 0xfd00;
			*current_sound = COIN;
			setsound(*current_sound);
>>>>>>> jonas3
			break;
		case BTN3:
<<<<<<< HEAD
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = JUMP;
			resetSong();
=======
			*GPIO_PA_DOUT = 0xfd00;
			*current_sound = CRASH;
			setsound(*current_sound);
>>>>>>> jonas3
			break;
		case BTN4:
<<<<<<< HEAD
			//*GPIO_PA_DOUT = (~btn)<<8;
			*CURRENT_SONG = DEATH;
			resetSong();
=======
			*GPIO_PA_DOUT = 0xfd00;
			*current_sound = FLAP;
			setsound(*current_sound);
>>>>>>> jonas3
			break;
		case BTN6:
<<<<<<< HEAD
			//*GPIO_PA_DOUT = (~btn)<<8;
			increaseVolume();
=======
			*GPIO_PA_DOUT = 0xf000;
			increasevol();
>>>>>>> jonas3
			break;
		case BTN8:
<<<<<<< HEAD
			//*GPIO_PA_DOUT = (~btn)<<8;
			decreaseVolume();
			break;

		default:
			// Do nothing
			//*GPIO_PA_DOUT = (0x00)<<8;
=======
			*GPIO_PA_DOUT = 0x0f00;
			decreasevol();
>>>>>>> jonas3
			break;
	}
}
