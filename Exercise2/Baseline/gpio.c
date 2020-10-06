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
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_GPIO;	/* enable GPIO clock */
	*GPIO_PA_CTRL = 2;	/* set high drive strength */
	*GPIO_PA_MODEH = 0x55555555;	/* set pins A8-15 as output */
	*GPIO_PA_DOUT = 0xff00;	/* turn on LEDs D4-D8 (LEDs are active
				 * low) */
    *GPIO_PC_MODEL = 0x33333333;
    *GPIO_PC_DOUT = 0xff;
    *volume = 1000; //Arbritrary value
}

void buttonHandler(){
	uint32_t btns = *GPIO_PC_DIN;
	switch (btns){
		case BTN1:
			*CURRENT_SONG = FLAAKLYPA;
			resetSong();
			break;

		case BTN2:
			*CURRENT_SONG = COIN;
			resetSong();
			break;

		case BTN3:
			*CURRENT_SONG = JUMP;
			resetSong();
			break;

		case BTN4:
			*CURRENT_SONG = DEATH;
			resetSong();
			break;
		
		case BTN6:
			*volume++;
			break;
		
		case BTN8:
			*volume--;
			break;

		default:
			//CURRENT_SONG = NONE; //?
			break;
	}
}
