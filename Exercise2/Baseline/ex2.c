#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"
#include "timer.h"



extern void setupDAC();
extern void setupGPIO();
extern void setupMusic();
extern void setupTimer(uint32_t period);

extern void startTimer();
extern void buttonHandler();
extern void updateNote();



int main(void)
{
	// Setting up sub modules
	setupGPIO();
	setupDAC();
	setupTimer(SAMPLE_PERIOD);
	setupMusic();

	startTimer();

	while(1){
		buttonHandler();
		if (*TIMER1_CNT == SAMPLE_PERIOD){
			// Checking state
			if (*CURRENT_SONG != NONE){
				playMelody();
			}
		}
	} 
	return 0;
}