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
extern int buttonHandler( int C_s );
extern void updateNote();

int main(void)
{
	setupGPIO();
	setupDAC();
	setupTimer(SAMPLE_PERIOD);
	setupMusic();
	startTimer();
  int C_s = 0;

	while(1){
		C_s = buttonHandler( C_s );
		if (*TIMER1_CNT == SAMPLE_PERIOD){
			if (C_s == 0){
        *GPIO_PA_DOUT = 0x0f00;
			}else{
        C_s = playMelody( C_s );
        *GPIO_PA_DOUT = 0xf000;
      }
		}
	} 
	return 0;
}