#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"

void enableDAC(){
	// Prescaling DAC clk
	*CMU_HFPERCLKEN0 |= CMU2_HFPERCLKEN0_DAC0;
	*DAC0_CTRL = 0x50010;
	
	// Enabling audio channels
	*DAC0_CH0CTRL = 0x1;
	*DAC0_CH1CTRL = 0x1;
}


void disableDac(){
	// Doing opposite of code above
    *DAC0_CTRL = 0x0;
    *DAC0_CH0CTRL = 0x0;
    *DAC0_CH1CTRL = 0x0;
	*CMU_HFPERCLKEN0 &= ~CMU2_HFPERCLKEN0_DAC0;
}