#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "timer.h"
#include "gpio.h"
#include "dac.h"


void setupNVIC()
{
	// Enable handling of interrupts
	*ISER0 |= ISER0_GPIO_EVEN | ISER0_GPIO_ODD | ISER0_TIMER1;
}

int main(void)
{
	setupGPIO();
	setupTimer(SAMPLE_PERIOD);
	setupNVIC();

	sleep();
	__asm__("wfi;");
	
	return 0;
}
