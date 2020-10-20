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


int main(void)
{
	setupGPIO();
	setupDAC();
	setupmusic();
	setupTimer(SAMPLE_PERIOD);
	startTimer();
<<<<<<< HEAD
	
	/*
	 * Enable interrupt handling, not relevant in baseline
	 */
	//setupNVIC();

	/*
	 * TODO for higher energy efficiency, sleep while waiting for
	 * interrupts instead of infinite loop for busy-waiting 
	 */
	while(1){
		// Read buttons
		uint32_t x = readButtons();
        setLeds( x );
        
        /*
		// Play some sound depending on which button was pressed?
		if arr[3]{ // Assuming this would be the music or something
			playWaveform(sound);
		}else{ //Simple sound effects can be played as raw.
			playRaw(sound);
=======

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
>>>>>>> origin/master
		}
	} 
	return 0;
}
