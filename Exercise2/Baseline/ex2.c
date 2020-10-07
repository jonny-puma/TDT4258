#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"

extern void setupDAC();
extern void setupGPIO();
extern void setupMusic();
extern void setupTimer(uint32_t period);

extern void startTimer();
extern uint32_t buttonHandler(int current_song );

int main(void)
{
	setupGPIO();
	setupDAC();
	setupTimer(SAMPLE_PERIOD);
	setupMusic();
	startTimer();

  	uint32_t current_song = 0;

	while(1){
		current_song = buttonHandler(current_song);
		if (*TIMER1_CNT == SAMPLE_PERIOD){
			if (current_song != 0){
				playMelody();
				if (medoldyFinished()){
					current_song = 0;
				}
			}
		}
	}
	return 0;
}