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
extern void buttonhandler(soundname *current_sound, int *volume);
extern void updateNote();

int main(void)
{
	setupGPIO();
	setupDAC();
	setupmusic();
	setupTimer(SAMPLE_PERIOD);
	startTimer();

  soundname current_sound = NONE;

	while(1){
		buttonhandler(&current_sound, &volume);
		if (*TIMER1_CNT == SAMPLE_PERIOD) {
			if (current_sound != NONE) {
        playsound(&current_sound);
      }
        *GPIO_PA_DOUT = 0xf000;
      }
		}
	} 
	return 0;
}
