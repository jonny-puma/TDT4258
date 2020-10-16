#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"

/*
 * function to setup the timer 
 */
void setupTimer(uint16_t period)
{
	// Enabling clock to timer
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_TIMER1;
	// Setting timer period
	*TIMER1_TOP = period;
	// Enabling timer interrupt generation.
}

// Function to start timer
void startTimer()
{
	*TIMER1_IEN = 0x1;
    *TIMER1_CMD = 0x1;
}

void sleep() {
	// Disabling timer
	*TIMER1_IEN = 0x0;
	*TIMER1_CMD = 0x0;

	// Setting sleep mode to deep sleep
	*SCR = 0x6;

	// Deactivating RAM blocks
	*EMU_MEMCTRL = 0x7;

	// Sisabling DAC
	*CMU_HFPERCLKEN0 &= ~(1 << 17);
    *DAC0_CTRL = 0;
    *DAC0_CH0CTRL = 0;
    *DAC0_CH1CTRL = 0;
	
}
