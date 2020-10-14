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
	*TIMER1_TOP = 2*period;
	// Enabling timer interrupt generation.
	*TIMER1_IEN = 0x1;
}

// Function to start timer
void startTimer()
{
    *TIMER1_CMD = 0x1;
}

