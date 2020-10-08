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
<<<<<<< HEAD
	setupMusic();
    startTimer();
	
	while(1){
		buttonHandler();
		if (*TIMER1_CNT == SAMPLE_PERIOD){
			// Checking state
			if (*CURRENT_SONG != NONE){
				//*GPIO_PA_DOUT = (0x00)<<8;
				updateNote();
=======
	startTimer();

	soundname current_sound = NONE;

	while(1) {
		buttonhandler(&current_sound, &volume);
		if (*TIMER1_CNT == SAMPLE_PERIOD) {
			if (current_sound == NONE) {
        			*GPIO_PA_DOUT = 0xf000;
			} else {
				playsound(&current_sound);
>>>>>>> jonas3
			}
		}
	} 
	return 0;
}
