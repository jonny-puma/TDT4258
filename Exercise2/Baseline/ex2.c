#include <stdint.h>
#include <stdbool.h>

#include "efm32gg.h"
#include "common.h"
#include "music.h"

<<<<<<< HEAD

/*
 * Declaration of sub system setup functions 
 */
extern void setupTimer(uint32_t period);
=======
>>>>>>> aksel_ex2
extern void setupDAC();
extern void setupGPIO();
extern void setupMusic();
extern void setupTimer(uint32_t period);

extern void startTimer();
<<<<<<< HEAD
extern void buttonHandler();
=======
extern int buttonHandler( int C_s );
extern void updateNote();
>>>>>>> aksel_ex2

int main(void)
{
	setupGPIO();
	setupDAC();
	setupTimer(SAMPLE_PERIOD);
	setupMusic();
<<<<<<< HEAD
    startTimer();
	
=======
	startTimer();
  int C_s = 0;

>>>>>>> aksel_ex2
	while(1){
		C_s = buttonHandler( C_s );
		if (*TIMER1_CNT == SAMPLE_PERIOD){
<<<<<<< HEAD
			// Checking state
			if (*CURRENT_SONG != NONE){
				*GPIO_PA_DOUT = (0x00)<<8;
				updateNote();
			}
=======
			if (C_s == 0){
        *GPIO_PA_DOUT = 0x0f00;
			}else{
        C_s = playMelody( C_s );
        *GPIO_PA_DOUT = 0xf000;
      }
>>>>>>> aksel_ex2
		}
	}

	return 0;
}