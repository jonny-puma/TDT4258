#include <stdint.h>
#include <stdbool.h>

#include "music.h"
#include "efm32gg.h"

extern void startTimer();
extern void buttonhandler(soundname *current_sound);

/*
 * TIMER1 interrupt handler 
 */
void __attribute__ ((interrupt)) TIMER1_IRQHandler()
{
	*TIMER1_IFC = *TIMER1_IF;
	playsound(&current_sound);
}

/*
 * GPIO even pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	startTimer();
	buttonhandler(&current_sound);
}

/*
 * GPIO odd pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	startTimer();
	buttonhandler(&current_sound);
}
