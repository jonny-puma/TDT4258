#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "gpio.h"
#include "timer.h"
#include "music.h"
#include "dac.h"

<<<<<<< HEAD
extern void startTimer();
extern void buttonhandler(soundname *current_sound);
=======
soundname current_sound = NONE;
>>>>>>> master

void __attribute__ ((interrupt)) TIMER1_IRQHandler()
{
	*TIMER1_IFC = *TIMER1_IF;
	playsound(&current_sound);
}

void __attribute__ ((interrupt)) GPIO_EVEN_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	startTimer();
<<<<<<< HEAD
	buttonhandler(&current_sound);
=======
	enableDAC();
	buttonhandler();
	*SCR = 0x2;
>>>>>>> master
}

void __attribute__ ((interrupt)) GPIO_ODD_IRQHandler()
{
	*GPIO_IFC = *GPIO_IF;
	startTimer();
<<<<<<< HEAD
	buttonhandler(&current_sound);
=======
	enableDAC();
	buttonhandler();
	*SCR = 0x2;
>>>>>>> master
}
