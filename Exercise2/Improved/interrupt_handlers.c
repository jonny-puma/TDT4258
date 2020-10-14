#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "gpio.h"
#include "timer.h"
#include "music.h"

soundname current_sound = NONE;

void __attribute__ ((interrupt)) TIMER1_IRQHandler()
{
	*TIMER1_IFC = *TIMER1_IF;
	playsound(&current_sound);
}

void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	startTimer();
	buttonhandler(&current_sound);
}

void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	startTimer();
	buttonhandler(&current_sound);
}
