#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"

extern void setupDAC();
extern void setupGPIO();
extern void setupmusic();
extern void setupTimer(uint32_t period);

extern void startTimer();
extern void buttonhandler(soundname *current_sound, uint32_t *volume);
extern void updateNote();

int main(void)
{
	setupGPIO();
	setupDAC();
	setupmusic();
	setupTimer(SAMPLE_PERIOD);
	startTimer();

	soundname current_sound = NONE;
	while(1) {
		buttonhandler(&current_sound, &volume);
		if (TIMER1_IF) {
			*TIMER1_IFC = *TIMER1_IF;
			if (current_sound == NONE) {
				*GPIO_PA_DOUT = 0xf000;
			} else {
				playsound(&current_sound);
      		}
		}
	} 
	return 0;
}
