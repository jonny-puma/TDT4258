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
extern void buttonHandler(soundname current_sound);
extern void updateNote();

int main(void)
{
	setupGPIO();
	setupDAC();
	setupTimer(SAMPLE_PERIOD);
	setupMusic();
	startTimer();

  soundname current_song = NONE;

	while(1){
		buttonHandler(&current_sound, &volume);
		if (*TIMER1_CNT == SAMPLE_PERIOD) {
			if (current_sound == NONE) {
        *GPIO_PA_DOUT = 0x0f00;
			} else {
        playsound(&current_sound);
        *GPIO_PA_DOUT = 0xf000;
      }
		}
	} 
	return 0;
}
