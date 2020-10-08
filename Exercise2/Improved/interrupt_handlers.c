#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"

/*
 * TIMER1 interrupt handler 
 */
void __attribute__ ((interrupt)) TIMER1_IRQHandler()
{
	*TIMER1_IFC = *TIMER1_IF;
	// playsound(&current_sound);
}

/*
 * GPIO even pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	// Button handler
}

/*
 * GPIO odd pin interrupt handler 
 */
void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	// Button handler
}
